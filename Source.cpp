#include <iostream>
#include <string>
using namespace std;

const int maxStudent = 200;
int studentIDs[maxStudent];
string sports[maxStudent];
int numStudents = 0;

bool isStudentEligible(int age, bool isTA) {
    return ((age <= 25) && (!isTA));
}

void registerStudent(int id, string sport) {
    if (numStudents >= maxStudent) {
        cout << "Maximum number of students reached." << endl;
        return;
    }
    bool newStudent = true;
    if (isStudentEligible(25, false)) {
        for (int i = 0; i < numStudents; i++) {
            if (studentIDs[i] == id) {
                cout << "Student cannot Register ,  Already registered " << endl;
                newStudent = false;
                break;
            }
        };
        if (newStudent) {
            studentIDs[numStudents] = id;
            sports[numStudents] = sport;
            numStudents++;
            cout << "Student registered successfully." << endl;
        }
       
    }
    else {
        cout << "Student is not eligible to register." << endl;
    }
}

void viewStudentRecord(int id) {
    if (numStudents == 0) {
        cout << "No Student Registered" << endl;
    }
    else
    {
        for (int i = 0; i < numStudents; i++) {
            if (studentIDs[i] == id) {
                cout << "Student ID : " << studentIDs[i] << endl;
                cout << "Sport : " << sports[i] << endl;
                return;
            }
        }
        cout << "Student not found." << endl;
    }
}

void viewAllRecords() {
    cout << "Student ID\t\tSport" << endl;
    cout << "-----------------------------------------------------" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << studentIDs[i] << "\t\t\t" << sports[i] << endl;
    }
}

void updateStudentSport(int id, string newSport) {
    for (int i = 0; i < numStudents; i++) {
        if (studentIDs[i] == id) {
            sports[i] = newSport;
            cout << "Sport updated successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void deleteStudentRecord(int id) {
    for (int i = 0; i < numStudents; i++) {
        if (studentIDs[i] == id) {
            for (int j = i; j < numStudents - 1; j++) {
                studentIDs[j] = studentIDs[j + 1];
                sports[j] = sports[j + 1];
            }
            numStudents--;
            cout << "Student record deleted successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

int main() {
    int choice;

    while (true) {
        cout << endl;
        cout << "1. Register student" << endl;
        cout << "2. View student record" << endl;
        cout << "3. View all records" << endl;
        cout << "4. Update student sport" << endl;
        cout << "5. Delete student record" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 0:
            exit(0);
        case 1: {
            int id;
            string sport;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter sport: ";
            cin >> sport;
            registerStudent(id, sport);
            break;
        }
        case 2: {
            int id;
            cout << "Enter student ID: ";
            cin >> id;
            viewStudentRecord(id);
            break;
        }
        case 3:
            viewAllRecords();
            break;
        case 4: {
            int id;
            string newSport;
            cout << "Enter student ID: ";
            cin >> id;
            cout << "Enter new sport: ";
            cin >> newSport;
            updateStudentSport(id, newSport);
            break;
        }
        case 5: {
            int id;
            cout << "Enter student ID: ";
            cin >> id;
            deleteStudentRecord(id);
            break;
        }
        default:
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}