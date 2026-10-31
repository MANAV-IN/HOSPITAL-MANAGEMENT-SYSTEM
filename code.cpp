
#include <iostream>
#include <string>
using namespace std;

class appointment {
public:
    char pname[20], dname[20];
    int date, month, year;

    int insert() {
        cout << "Enter Patient Name: ";
        cin.width(20);
        cin >> pname;

        cout << "Enter Doctor Name: ";
        cin.width(20);
        cin >> dname;

        cout << "Enter Appointment Date (DD MM YYYY): ";
        while (!(cin >> date >> month >> year) ||
               date < 1 || date > 31 ||
               month < 1 || month > 12 ||
               year < 1) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter Appointment Date (DD MM YYYY): ";
        }

        return 0;
    }

    void view() {
        cout << "Patient Name: " << pname << "\n";
        cout << "Doctor Name: " << dname << "\n";
        cout << "Appointment Date: "
             << date << "/" << month << "/" << year << "\n";
    }
};

class patient {
public:
    int age;
    char fname[20], lname[20], gender[10];
    char department[20], dname[20];

    int info() {
        cout << "Enter First Name: ";
        cin.width(20);
        cin >> fname;

        cout << "Enter Last Name: ";
        cin.width(20);
        cin >> lname;

        cout << "Enter Age: ";
        while (!(cin >> age) || age < 0 || age > 150) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid age! Enter a valid age: ";
        }

        cout << "Enter Gender: ";
        cin.width(10);
        cin >> gender;

        cout << "Enter Department: ";
        cin.width(20);
        cin >> department;

        cout << "Enter Doctor Name: ";
        cin.width(20);
        cin >> dname;

        return 0;
    }
};

class doc {
public:
    char dname[20], department[20];

    int info() {
        cout << "Enter Doctor Name: ";
        cin.width(20);
        cin >> dname;

        cout << "Enter Department: ";
        cin.width(20);
        cin >> department;

        return 0;
    }
};

class billing {
public:
    char pname[20], dname[20];
    int amount;

    int info() {
        cout << "Enter Patient Name: ";
        cin.width(20);
        cin >> pname;

        cout << "Enter Doctor Name: ";
        cin.width(20);
        cin >> dname;

        cout << "Enter Bill Amount: ";
        while (!(cin >> amount) || amount < 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter Bill Amount: ";
        }

        return 0;
    }
};

int main() {
    patient p[100];
    doc d[100];
    appointment a[100];
    billing b[100];

    int choice, ch, num;
    int patientCount = 0;
    int doctorCount = 0;
    int appointmentCount = 0;
    int billCount = 0;

    do {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";
        cout << "1. Patient Management\n";
        cout << "2. Doctor Management\n";
        cout << "3. Appointment Management\n";
        cout << "4. Billing Management\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n--- PATIENT MANAGEMENT ---\n";
            cout << "1. Register Patient\n";
            cout << "2. View Patients\n";
            cout << "3. Update Patient\n";
            cout << "4. Delete Patient\n";
            cout << "Enter choice: ";
            cin >> ch;

            if (ch == 1) {
                cout << "How many patients to register? ";
                cin >> num;

                if (num <= 0 || num > 100 - patientCount) {
                    cout << "Invalid number of patients!\n";
                } else {
                    for (int i = 0; i < num; i++) {
                        cout << "\nEnter details of Patient "
                             << patientCount + 1 << ":\n";

                        p[patientCount].info();
                        patientCount++;

                        cout << "Patient Registered Successfully!\n";
                    }
                }
            }

            else if (ch == 2) {
                if (patientCount == 0) {
                    cout << "No patients registered yet.\n";
                } else {
                    cout << "\nTotal Patients: "
                         << patientCount << "\n";

                    for (int i = 0; i < patientCount; i++) {
                        cout << "\nPatient Number: " << i + 1 << "\n";
                        cout << "Name: " << p[i].fname << " "
                             << p[i].lname << "\n";
                        cout << "Age: " << p[i].age << "\n";
                        cout << "Gender: " << p[i].gender << "\n";
                        cout << "Department: "
                             << p[i].department << "\n";
                        cout << "Doctor: " << p[i].dname << "\n";
                    }
                }
            }

            else if (ch == 3) {
                if (patientCount == 0) {
                    cout << "No patients available to update.\n";
                } else {
                    cout << "Enter patient number to update (1-"
                         << patientCount << "): ";
                    cin >> num;

                    if (num < 1 || num > patientCount) {
                        cout << "Invalid patient number!\n";
                    } else {
                        cout << "\nEnter updated patient details:\n";
                        p[num - 1].info();
                        cout << "Patient Updated Successfully!\n";
                    }
                }
            }

            else if (ch == 4) {
                if (patientCount == 0) {
                    cout << "No patients available to delete.\n";
                } else {
                    cout << "Enter patient number to delete (1-"
                         << patientCount << "): ";
                    cin >> num;

                    if (num < 1 || num > patientCount) {
                        cout << "Invalid patient number!\n";
                    } else {
                        for (int i = num - 1;
                             i < patientCount - 1; i++) {
                            p[i] = p[i + 1];
                        }

                        patientCount--;
                        cout << "Patient Deleted Successfully!\n";
                    }
                }
            }

            else {
                cout << "Invalid patient menu choice!\n";
            }
        }

        else if (choice == 2) {
            cout << "\n--- DOCTOR MANAGEMENT ---\n";
            cout << "1. Register Doctor\n";
            cout << "2. View Doctors\n";
            cout << "3. Exit Doctor Management\n";
            cout << "Enter choice: ";
            cin >> ch;

            if (ch == 1) {
                cout << "How many doctors to register? ";
                cin >> num;

                if (num <= 0 || num > 100 - doctorCount) {
                    cout << "Invalid number of doctors!\n";
                } else {
                    for (int i = 0; i < num; i++) {
                        cout << "\nEnter details of Doctor "
                             << doctorCount + 1 << ":\n";

                        d[doctorCount].info();
                        doctorCount++;

                        cout << "Doctor Registered Successfully!\n";
                    }

                    cout << "\nTotal Doctors Registered: "
                         << doctorCount << "\n";
                }
            }

            else if (ch == 2) {
                if (doctorCount == 0) {
                    cout << "No doctors registered yet.\n";
                } else {
                    for (int i = 0; i < doctorCount; i++) {
                        cout << "\nDoctor Number: " << i + 1 << "\n";
                        cout << "Name: " << d[i].dname << "\n";
                        cout << "Department: "
                             << d[i].department << "\n";
                    }
                }
            }

            else if (ch == 3) {
                cout << "Exiting Doctor Management.\n";
            }

            else {
                cout << "Invalid doctor menu choice!\n";
            }
        }

        else if (choice == 3) {
            cout << "\n--- APPOINTMENT MANAGEMENT ---\n";
            cout << "1. Schedule Appointment\n";
            cout << "2. View Appointments\n";
            cout << "3. Exit Appointment Management\n";
            cout << "Enter choice: ";

            int appChoice;
            cin >> appChoice;

            if (appChoice == 1) {
                cout << "How many appointments to schedule? ";
                cin >> num;

                if (num <= 0 || num > 100 - appointmentCount) {
                    cout << "Invalid number of appointments!\n";
                } else {
                    for (int i = 0; i < num; i++) {
                        cout << "\nEnter details of Appointment "
                             << appointmentCount + 1 << ":\n";

                        a[appointmentCount].insert();
                        appointmentCount++;

                        cout << "Appointment Scheduled Successfully!\n";
                    }
                }
            }

            else if (appChoice == 2) {
                if (appointmentCount == 0) {
                    cout << "No appointments scheduled yet.\n";
                } else {
                    cout << "\n--- LIST OF APPOINTMENTS ---\n";

                    for (int i = 0; i < appointmentCount; i++) {
                        cout << "Patient Name: "
                             << a[i].pname << "\n";
                        cout << "Doctor Name: "
                             << a[i].dname << "\n";
                        cout << "Date: "
                             << a[i].date << "/"
                             << a[i].month << "/"
                             << a[i].year << "\n\n";
                    }
                }
            }

            else if (appChoice == 3) {
                cout << "Exiting Appointment Management.\n";
            }

            else {
                cout << "Invalid appointment menu choice!\n";
            }
        }

        else if (choice == 4) {
            cout << "\n--- BILLING MANAGEMENT ---\n";
            cout << "1. Generate Bill\n";
            cout << "2. View Bills\n";
            cout << "3. Exit Billing Management\n";
            cout << "Enter choice: ";
            cin >> ch;

            if (ch == 1) {
                cout << "How many bills to generate? ";
                cin >> num;

                if (num <= 0 || num > 100 - billCount) {
                    cout << "Invalid number of bills!\n";
                } else {
                    for (int i = 0; i < num; i++) {
                        cout << "\nEnter details of Bill "
                             << billCount + 1 << ":\n";

                        b[billCount].info();
                        billCount++;

                        cout << "Bill Generated Successfully!\n";
                    }
                }
            }

            else if (ch == 2) {
                if (billCount == 0) {
                    cout << "No bills generated yet.\n";
                } else {
                    cout << "\n--- LIST OF BILLS ---\n";

                    for (int i = 0; i < billCount; i++) {
                        cout << "Patient Name: "
                             << b[i].pname << "\n";
                        cout << "Total Amount: "
                             << b[i].amount << "\n\n";
                    }
                }
            }

            else if (ch == 3) {
                cout << "Exiting Billing Management.\n";
            }

            else {
                cout << "Invalid billing menu choice!\n";
            }
        }

        else if (choice == 5) {
            cout << "Exiting Hospital Management System.\n";
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
