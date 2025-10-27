// <DOCUMENT filename="09_DeviceDriverPolymorphism.cpp">
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @file 09_DeviceDriverPolymorphism.cpp
 * @brief Real-world example: Multiple camera drivers, same interface.
 *
 * Design Pattern: Strategy + Factory
 * - ICameraDevice = pure abstract interface
 * - Different drivers implement it
 * - Apps use interface, not concrete type
 */

class IDevice
{
};

class ICameraDevice : public IDevice
{
public:
    virtual string GetVersion() = 0;
    virtual bool Start() = 0;
    virtual bool Stop() = 0;
    virtual ~ICameraDevice() = default; // Fixed: ICameraDevice, not ICsameraDevice
};

class UbuntuDriverOpenSource : public ICameraDevice
{
public:
    string GetVersion() override { return "Ubuntu OpenSource"; }
    bool Start() override { return true; }
    bool Stop() override { return false; }
};

class UbuntuDriver3rdParty : public ICameraDevice
{
public:
    string GetVersion() override { return "Ubuntu 3rdParty"; }
    bool Start() override { return true; }
    bool Stop() override { return false; }
};

class UbuntuDriverWindows10 : public ICameraDevice
{
public:
    string GetVersion() override { return "Windows 10 Driver"; }
    bool Start() override { return true; }
    bool Stop() override { return false; }
};

class App
{
public:
    virtual void Run() = 0;
    virtual void Shutdown() { cout << "App shutting down...\n"; }
    virtual ~App() = default;
};

class CameraAppCheese : public App
{
    ICameraDevice *camera;

public:
    CameraAppCheese(ICameraDevice *cam) : camera(cam) {}
    void Run() override
    {
        cout << "Cheese: Using " << camera->GetVersion() << "\n";
        for (int i = 0; i < 3; ++i)
            cout << "   [Fast capture]\n";
    }
};

class CameraAppKamoso : public App
{
    ICameraDevice *camera;

public:
    CameraAppKamoso(ICameraDevice *cam) : camera(cam) {}
    void Run() override
    {
        cout << "Kamoso: Using " << camera->GetVersion() << "\n";
        for (int i = 0; i < 3; ++i)
            cout << "   [Slow capture]\n";
    }
};

class UbuntuOS
{
    vector<App *> apps;
    vector<IDevice *> devices;

public:
    App *GetCameraApp(const string &name)
    {
        ICameraDevice *driver = nullptr;

        if (name == "OpenSource")
        {
            driver = new UbuntuDriverOpenSource();
        }
        else if (name == "3rdParty")
        {
            driver = new UbuntuDriver3rdParty();
        }
        else if (name == "Windows10")
        {
            driver = new UbuntuDriverWindows10();
        }
        else
        {
            return nullptr;
        }

        App *app = nullptr;
        if (name == "Cheese")
        {
            app = new CameraAppCheese(driver);
        }
        else if (name == "Kamoso")
        {
            app = new CameraAppKamoso(driver);
        }

        if (app)
        {
            devices.push_back(driver);
            apps.push_back(app);
        }
        return app;
    }

    void Shutdown()
    {
        for (App *app : apps)
            app->Shutdown();
    }

    ~UbuntuOS()
    {
        cout << "OS Terminating...\n";
        Shutdown();
        for (App *app : apps)
            delete app;
        for (IDevice *dev : devices)
            delete dev;
        apps.clear();
        devices.clear();
    }
};

int main()
{
    UbuntuOS os;

    App *app1 = os.GetCameraApp("OpenSource");
    if (app1)
        app1->Run();

    App *app2 = os.GetCameraApp("3rdParty");
    if (app2)
        app2->Run();

    return 0;
}