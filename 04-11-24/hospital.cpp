#include <iostream>
using namespace std;

class Hospital {
private:
    
    static int inpatientCount;
    static int outpatientCount;
    static int criticalCareCount;
    static int totalPatientCount;
    
public:
    
    static void addInpatients(int count) {
        inpatientCount += count;
        totalPatientCount += count;
    }

    static void addOutpatients(int count) {
        outpatientCount += count;
        totalPatientCount += count;
    }

    static void addCriticalCarePatients(int count) {
        criticalCareCount += count;
        totalPatientCount += count;
    }

    
    static int getTotalPatients() {
        return totalPatientCount;
    }

    static int getInpatients() {
        return inpatientCount;
    }

    static int getOutpatients() {
        return outpatientCount;
    }

    static int getCriticalCarePatients() {
        return criticalCareCount;
    }

   
    static void displayPatientCounts() {
        cout << "\nCurrent Patient Counts:" << endl;
        cout << "Inpatients: " << inpatientCount << endl;
        cout << "Outpatients: " << outpatientCount << endl;
        cout << "Critical Care Patients: " << criticalCareCount << endl;
        cout << "Total Patients: " << totalPatientCount << endl;
    }
};


int Hospital::inpatientCount = 0;
int Hospital::outpatientCount = 0;
int Hospital::criticalCareCount = 0;
int Hospital::totalPatientCount = 0;

int main() {
    int inpatientInput, outpatientInput, criticalCareInput;
    char choice;

    do {
        // Get user input for inpatients
        cout << "Enter the number of inpatients to add: ";
        cin >> inpatientInput;
        Hospital::addInpatients(inpatientInput);

        // Get user input for outpatients
        cout << "Enter the number of outpatients to add: ";
        cin >> outpatientInput;
        Hospital::addOutpatients(outpatientInput);

        // Get user input for critical care patients
        cout << "Enter the number of critical care patients to add: ";
        cin >> criticalCareInput;
        Hospital::addCriticalCarePatients(criticalCareInput);

        // Display the updated patient counts
        Hospital::displayPatientCounts();

        // Ask the user if they want to add more patients
        cout << "\nDo you want to add more patients? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y'); // Repeat if user enters 'y' or 'Y'

    // Final display of patient counts
    cout << "\nFinal Patient Counts:" << endl;
    Hospital::displayPatientCounts();

    return 0;
}
