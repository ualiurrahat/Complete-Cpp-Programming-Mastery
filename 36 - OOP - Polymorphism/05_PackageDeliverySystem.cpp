// <DOCUMENT filename="05_PackageDeliverySystem.cpp">
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

/**
 * @file 05_PackageDeliverySystem.cpp
 * @brief Full polymorphic package delivery system with different pricing models.
 *
 * Key Features:
 * - `Package` abstract base class with pure virtual `TotalCost()`
 * - `StandardPackage`: base weight × price/kg
 * - `TwoDayPackage`: adds fixed fee
 * - `HeavyPackage`: extra charge for weight > 100kg
 * - `Shipment`: aggregates packages → total cost via polymorphism
 *
 * Intuition:
 *   "Ship any package type, calculate cost correctly without knowing type"
 */

class Address
{
private:
    string name;
    string address;
    string city;

public:
    // --- Getters ---
    const string &GetName() const { return name; }
    const string &GetAddress() const { return address; }
    const string &GetCity() const { return city; }

    // --- Setters ---
    void SetName(const string &n) { name = n; }
    void SetAddress(const string &a) { address = a; }
    void SetCity(const string &c) { city = c; }
};

// ===================================================================
// Abstract Base Class
// ===================================================================
class Package
{
public:
    virtual double TotalCost() const = 0;
    virtual ~Package() = default; // Essential for polymorphic deletion
};

// ===================================================================
// Concrete Package Types
// ===================================================================
class StandardPackage : public Package
{
private:
    Address sender_address;
    Address receiver_address;
    double weight_kg;
    double price_per_kg;

public:
    // Constructor
    StandardPackage(const Address &sender, const Address &receiver,
                    double weight, double price_per_kg)
        : sender_address(sender), receiver_address(receiver),
          weight_kg(weight), price_per_kg(price_per_kg) {}

    // --- Core Polymorphic Function ---
    double TotalCost() const override
    {
        return weight_kg * price_per_kg;
    }

    // --- Getters (for derived classes) ---
    double GetWeightKg() const { return weight_kg; }
    double GetPricePerKg() const { return price_per_kg; }

    const Address &GetSenderAddress() const { return sender_address; }
    const Address &GetReceiverAddress() const { return receiver_address; }

    // --- Setters ---
    void SetWeightKg(double w) { weight_kg = w; }
    void SetPricePerKg(double p) { price_per_kg = p; }
    void SetSenderAddress(const Address &a) { sender_address = a; }
    void SetReceiverAddress(const Address &a) { receiver_address = a; }
};

// -------------------------------------------------------------------
// Two-Day Package: Standard + Fixed Fee
// -------------------------------------------------------------------
class TwoDayPackage : public StandardPackage
{
private:
    double fixed_fee;

public:
    TwoDayPackage(const Address &sender, const Address &receiver,
                  double weight, double price_per_kg, double fee)
        : StandardPackage(sender, receiver, weight, price_per_kg), fixed_fee(fee) {}

    double TotalCost() const override
    {
        return StandardPackage::TotalCost() + fixed_fee;
    }

    double GetFixedFee() const { return fixed_fee; }
    void SetFixedFee(double f) { fixed_fee = f; }
};

// -------------------------------------------------------------------
// Heavy Package: Extra charge if weight > 100kg
// -------------------------------------------------------------------
class HeavyPackage : public StandardPackage
{
private:
    const double limit_kg = 100.0; // Fixed threshold
    double extra_price_per_kg;

public:
    HeavyPackage(const Address &sender, const Address &receiver,
                 double weight, double price_per_kg, double extra_price)
        : StandardPackage(sender, receiver, weight, price_per_kg),
          extra_price_per_kg(extra_price) {}

    /**
     * @brief Calculates total cost with overweight surcharge.
     *
     * Uses GetWeightKg() → respects encapsulation (cannot access private weight_kg directly)
     */
    double TotalCost() const override
    {
        double base_cost = StandardPackage::TotalCost();

        if (GetWeightKg() > limit_kg)
        {
            double excess = GetWeightKg() - limit_kg;
            base_cost += excess * extra_price_per_kg;
        }

        return base_cost;
    }

    double GetExtraPricePerKg() const { return extra_price_per_kg; }
    void SetExtraPricePerKg(double e) { extra_price_per_kg = e; }
};

// ===================================================================
// Shipment: Aggregates multiple packages
// ===================================================================
class Shipment
{
private:
    vector<Package *> packages;

public:
    ~Shipment()
    {
        for (Package *p : packages)
        {
            delete p;
        }
        packages.clear();
    }

    void AddPackage(Package *p)
    {
        if (p)
            packages.push_back(p);
    }

    /**
     * @brief Sums cost of all packages using polymorphism.
     */
    double TotalCost() const
    {
        double total = 0.0;
        for (const Package *p : packages)
        {
            total += p->TotalCost(); // Calls correct version at runtime
        }
        return total;
    }
};

// ===================================================================
// Payment System (Placeholder)
// ===================================================================
class PaymentCard
{
private:
    string card_number;
    double expiry_date; // Simplified
};

class CreditCard : public PaymentCard
{
};
class DebitCard : public PaymentCard
{
};

// ===================================================================
// Main Demo
// ===================================================================
int main()
{
    cout << fixed << std::setprecision(2);

    // Create addresses
    Address sender, receiver;
    sender.SetName("Ali Khan");
    sender.SetCity("Cairo");
    receiver.SetName("Sara Ahmed");
    receiver.SetCity("Alexandria");

    // Create shipment
    Shipment shipment;

    // Add different package types
    shipment.AddPackage(new StandardPackage(sender, receiver, 10, 5.0));    // 50
    shipment.AddPackage(new TwoDayPackage(sender, receiver, 5, 5.0, 20.0)); // 25 + 20 = 45
    shipment.AddPackage(new HeavyPackage(sender, receiver, 120, 5.0, 2.0)); // 600 + 40 = 640

    // Output total
    cout << "=== Shipment Summary ===\n";
    cout << "Total Cost: $" << shipment.TotalCost() << "\n"; // 735.00

    return 0;
}