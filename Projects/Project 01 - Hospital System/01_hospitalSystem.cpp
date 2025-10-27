/**
 * @file 01_hospitalSystem.cpp
 * @brief Hospital System Simulation using arrays and functions
 *
 * PROJECT : HOSPITAL SYSTEM
 * Implement the following system for a hospital
 *  ● There are 20 different specialization (e.g. Children, Surgery, etc)
 *  ● For each specialization, there are only 5 available spots [queue]
 *  ● Adding a patient
 *    ○ Read the requested specialization [1-20].
 *    ○ Read his name and status (0 = regular, 1 urgent)
 *    ○ If 5 patients exist, apologize and don’t accept.
 *    ○ If the user is regular, add in end of queue. Otherwise, add in Begin
 *  ● Print patients, for the specializations that have waiting patients
 *  ● Dr pickup a patient
 *    ○ Read the requested specialization. If no patients, inform the doctor
 *    ○ Otherwise, ask the patient to go with the Dr. Remove from the queue
 *

 */

#include <iostream>
#include <string>

using namespace std;

/* ---------------------- Configuration (constants) ---------------------- */

/** Total number of available specializations (IDs: 1..MAX_SPECIALIZATION) */
const int MAX_SPECIALIZATION = 20;

/** Maximum queue length per specialization (0..MAX_QUEUE-1 are valid positions) */
const int MAX_QUEUE = 5;

/* ---------------------- Global storage ---------------------- */

/**
 * patientNames[specId][pos] holds the name of the patient at position pos
 * for specialization specId.
 * We allocate +1 so we can use 1..MAX_SPECIALIZATION for human-friendly indexing.
 */
string patientNames[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1];

/**
 * patientStatus[specId][pos] holds 0 or 1 for regular/urgent respectively
 * for patient at position pos in specialization specId.
 */
int patientStatus[MAX_SPECIALIZATION + 1][MAX_QUEUE + 1];

/**
 * queueLength[specId] holds the number of patients currently waiting
 * for specialization specId (0..MAX_QUEUE).
 */
int queueLength[MAX_SPECIALIZATION + 1] = {0}; // initialize all to 0

/*--------------- Function Declarations ------------------------*/
int displayMenu();
void shiftLeft(int specializationId, string patientNames[], int patientStatus[]);
void shiftRight(int specializationId, string patientNames[], int patientStatus[]);
bool addPatient();
void printPatientList(int specializationId, string patientNames[], int patientStatus[]);
void printAllPatients();
void getNextPatient();
void hospitalSystem();

/* ---------------------- Menu and core functions ---------------------- */

int main()
{
    // welcome message for first time use of the software
    cout << "***** Welcome To Hospital Management System *******" << endl;
    // start the interactive hospital system
    hospitalSystem();

    return 0;
}

/*-------------- Function Definitions ------------------*/
/**
 * @brief Display menu and get a validated choice from user.
 *
 * The function loops until the user types a valid integer between 1 and 4.
 *
 * @return int Menu choice: 1=add patient, 2=print all, 3=get next, 4=exit.
 */
int displayMenu()
{
    int choice = -1;

    // keep asking until a valid choice is provided
    while (choice == -1)
    {

        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n\n";

        cout << "\nEnter your choice:\n";

        // read the user's choice (assumes user provides an integer)
        cin >> choice;

        // validate range; if invalid, reset to -1 so loop repeats
        if (!(1 <= choice && choice <= 4))
        {
            cout << "Invalid choice. Try again\n";
            choice = -1;
        }
    }

    // return the valid choice
    return choice;
}

/**
 * @brief Shift all patients for a specialization one index to the left.
 *
 * This is used when the front (index 0) patient is removed (doctor took the patient),
 * so we move every element at i -> i-1, effectively deleting index 0.
 *
 * Example:
 *  names: [A, B, C] -> after shiftLeft -> [B, C, ...]
 *
 * @param specializationId The specialization id (1..MAX_SPECIALIZATION)
 * @param namesArray The array of names for that specialization
 * @param statusArray The array of statuses for that specialization
 */
void shiftLeft(int specializationId, string namesArray[], int statusArray[])
{
    // read current queue length for this specialization
    int currentLength = queueLength[specializationId];

    // if there are 0 or 1 patients, loop below may be skipped or just reduce length
    // loop from index 1 to currentLength-1: move i -> i-1
    for (int index = 1; index < currentLength; index++)
    {
        // move name at position 'index' to position 'index - 1'
        namesArray[index - 1] = namesArray[index];

        // move status similarly
        statusArray[index - 1] = statusArray[index];
    }

    // reduce the recorded length by 1 (we removed the front patient)
    // Note: we don't need to clear the last slot (optional), but it's fine to leave old data.
    queueLength[specializationId]--;
}

/**
 * @brief Shift patients one position to the right to make space at front (index 0).
 *
 * This is used when adding an urgent patient who must be placed at index 0.
 * We must iterate from the end to the beginning of the list to avoid overwriting values.
 *
 * Example:
 *  names: [A, B, C] -> shiftRight -> [_, A, B, C]
 *
 * @param specializationId The specialization id (1..MAX_SPECIALIZATION)
 * @param namesArray The array of names for that specialization
 * @param statusArray The array of statuses for that specialization
 */
void shiftRight(int specializationId, string namesArray[], int statusArray[])
{
    // read current queue length
    int currentLength = queueLength[specializationId];

    // IMPORTANT: iterate from currentLength-1 down to 0 so we move old values to higher indices
    // If currentLength == 0, the for loop condition initializes index = -1 and the body is skipped.
    for (int index = currentLength - 1; index >= 0; index--)
    {
        // move every element one position to the right
        namesArray[index + 1] = namesArray[index];
        statusArray[index + 1] = statusArray[index];
    }

    // increase the queue length (we made a free slot at index 0)
    queueLength[specializationId]++;
}

/**
 * @brief Add a new patient to a specialization queue.
 *
 * Steps:
 *  - Read specializationId, patient name and priorityStatus (0=regular, 1=urgent).
 *  - Validate specializationId range.
 *  - If the queue is full (>= MAX_QUEUE) -> reject.
 *  - If priorityStatus == 0 (regular) -> place at the current end (index = currentLength).
 *  - If priorityStatus == 1 (urgent) -> shiftRight then place at index 0.
 *
 *
 * @return bool True if patient added; False if rejected (e.g., queue full or bad input).
 */
bool addPatient()
{
    // local variables
    int specializationId = 0;
    string patientName;
    int priorityStatus = 0;

    // read all inputs on one line: specialization name status
    cout << "Enter specialization (1-" << MAX_SPECIALIZATION << "), name, and status (0=regular, 1=urgent): ";
    cin >> specializationId >> patientName >> priorityStatus;

    // validate specializationId (must be within 1..MAX_SPECIALIZATION)
    if (!(1 <= specializationId && specializationId <= MAX_SPECIALIZATION))
    {
        cout << "Invalid specialization ID. It must be between 1 and " << MAX_SPECIALIZATION << ".\n";
        return false; // reject
    }

    // current position = number of patients waiting so far in that specialization
    int currentLength = queueLength[specializationId];

    // check whether the queue is already full
    if (currentLength >= MAX_QUEUE)
    {
        // cannot accept more patients for this specialization
        cout << "Sorry, we can't add more patients for this specialization.\n";
        return false;
    }

    // If the patient is regular (priorityStatus == 0), add to the end of the queue.
    if (priorityStatus == 0)
    {
        // place the patient's name at the first free slot (index = currentLength)
        patientNames[specializationId][currentLength] = patientName;

        // record the status (0)
        patientStatus[specializationId][currentLength] = priorityStatus;

        // increase the queue length because we appended one patient
        queueLength[specializationId]++;

        // success
        return true;
    }
    else
    {
        // For urgent patient: we must insert at index 0.
        // Step 1: shift everyone one step to the right (this increases queueLength by 1)
        // This makes index 0 free to receive the new urgent patient.
        shiftRight(specializationId, patientNames[specializationId], patientStatus[specializationId]);

        // Step 2: place the urgent patient's data at index 0
        patientNames[specializationId][0] = patientName;
        patientStatus[specializationId][0] = priorityStatus;

        // success
        return true;
    }
}

/**
 * @brief Print the patient list for one specialization (if it has patients).
 *
 * Prints the number of patients and each entry line-by-line with status.
 *
 * @param specializationId The specialization id to print (1..MAX_SPECIALIZATION)
 * @param namesArray The names array reference for that specialization
 * @param statusArray The status array reference for that specialization
 */
void printPatientList(int specializationId, string namesArray[], int statusArray[])
{
    // read how many patients currently waiting
    int currentLength = queueLength[specializationId];

    // if none, return immediately (no output for this specialization)
    if (currentLength == 0)
    {
        return;
    }

    // print header
    cout << "There are " << currentLength << " patients in specialization " << specializationId << ":\n";

    // iterate through the queue from front (0) to last (currentLength-1)
    for (int index = 0; index < currentLength; ++index)
    {
        // print name
        cout << namesArray[index] << " - ";

        // print textual status
        if (statusArray[index] == 1)
            cout << "Urgent\n";
        else
            cout << "Regular\n";
    }

    // blank line for readability
    cout << "\n";
}

/**
 * @brief Print all specializations that currently have patients.
 *
 * This iterates specialization IDs 1..MAX_SPECIALIZATION and calls printPatientList.
 */
void printAllPatients()
{
    cout << "****************************\n";

    // note: we iterate 1..MAX_SPECIALIZATION because arrays were sized with +1.
    for (int specId = 1; specId <= MAX_SPECIALIZATION; ++specId)
    {
        printPatientList(specId, patientNames[specId], patientStatus[specId]);
    }
}

/**
 * @brief Let a doctor pick the next patient from a specialization (remove front).
 *
 * This function:
 *  - Reads specializationId from user.
 *  - If queue is empty -> tell the doctor to rest.
 *  - Otherwise announce the patient at index 0 and shiftLeft to remove them.
 */
void getNextPatient()
{
    int specializationId = 0;

    // ask the doctor which specialization they want to see next
    cout << "Enter specialization (1-" << MAX_SPECIALIZATION << "): ";
    cin >> specializationId;

    // validate specialization ID
    if (!(1 <= specializationId && specializationId <= MAX_SPECIALIZATION))
    {
        cout << "Invalid specialization ID. It must be between 1 and " << MAX_SPECIALIZATION << ".\n";
        return;
    }

    // get current length
    int currentLength = queueLength[specializationId];

    // if no patients waiting, inform the doctor
    if (currentLength == 0)
    {
        cout << "No patients at the moment. Have a rest, Doctor.\n";
        return;
    }

    // announce the front patient (index 0) who will go with the doctor
    cout << patientNames[specializationId][0] << " please go with the Doctor.\n";

    // remove the front patient by shifting everyone left
    shiftLeft(specializationId, patientNames[specializationId], patientStatus[specializationId]);
}

/**
 * @brief Top-level loop running the whole hospital system.
 *
 * Runs displayMenu, processes user's choices and exits when choice==4.
 */
void hospitalSystem()
{
    while (true)
    {
        // show menu and read a valid choice
        int choice = displayMenu();

        // route to correct handler
        if (choice == 1)
        {
            // add patient
            addPatient();
        }
        else if (choice == 2)
        {
            // print all patient lists
            printAllPatients();
        }
        else if (choice == 3)
        {
            // doctor picks next patient
            getNextPatient();
        }
        else
        { // choice == 4
            // exit the system loop and end the program
            cout << "Exiting hospital system. Goodbye!\n";
            break;
        }
    }
}

/* ---------------------- main ---------------------- */

/* ---------------------- TEST CASES (use these as console input) ----------------------

1
15 mostafa 0
1
15 asmaa 0
1
15 belal 1

2

1
15 ziad 1
2

1
15 safaa 0

1 15 ashraf
2

3
10

3
15

2

1
7 soha 1

2

1
15 amal 1

3
7

2

----------------------------------------------------------------------
*/
