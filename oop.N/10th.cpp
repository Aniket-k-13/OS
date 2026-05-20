#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

struct Student {
    int student_id;
    string name;
    int roll_no;
    string class_name;
    float marks;
    string address;
};

// Function to add a record
void addRecord() {
    ofstream file("students.txt", ios::app);
    Student s;
    cout << "\nEnter Student ID: ";
    cin >> s.student_id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Roll Number: ";
    cin >> s.roll_no;
    cin.ignore();
    cout << "Enter Class: ";
    getline(cin, s.class_name);
    cout << "Enter Marks: ";
    cin >> s.marks;
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, s.address);

    file << s.student_id << "," << s.name << "," << s.roll_no << ","
         << s.class_name << "," << s.marks << "," << s.address << endl;
    file.close();

    cout << "\nRecord added successfully.\n";
}

// Function to display all records
void displayRecords() {
    ifstream file("students.txt");
    if (!file) {
        cout << "\nNo records found.\n";
        return;
    }

    cout << "\n--- Student Database ---\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Roll No"
         << setw(10) << "Class" << setw(10) << "Marks" << "Address" << endl;
    cout << "-------------------------------------------------------------------------------\n";

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student s;
        string marks_str;
        getline(ss, line, ',');
        s.student_id = stoi(line);
        getline(ss, s.name, ',');
        getline(ss, line, ',');
        s.roll_no = stoi(line);
        getline(ss, s.class_name, ',');
        getline(ss, marks_str, ',');
        s.marks = stof(marks_str);
        getline(ss, s.address);

        cout << left << setw(10) << s.student_id << setw(20) << s.name
             << setw(10) << s.roll_no << setw(10) << s.class_name
             << setw(10) << s.marks << s.address << endl;
    }
    file.close();
}

// Function to search a record by ID
void searchRecord() {
    ifstream file("students.txt");
    if (!file) {
        cout << "\nNo records found.\n";
        return;
    }

    int id;
    cout << "\nEnter Student ID to search: ";
    cin >> id;
    bool found = false;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student s;
        string marks_str;
        getline(ss, line, ',');
        s.student_id = stoi(line);
        getline(ss, s.name, ',');
        getline(ss, line, ',');
        s.roll_no = stoi(line);
        getline(ss, s.class_name, ',');
        getline(ss, marks_str, ',');
        s.marks = stof(marks_str);
        getline(ss, s.address);

        if (s.student_id == id) {
            cout << "\nRecord Found:\n";
            cout << "Name: " << s.name << "\nRoll No: " << s.roll_no
                 << "\nClass: " << s.class_name << "\nMarks: " << s.marks
                 << "\nAddress: " << s.address << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nRecord not found.\n";
    file.close();
}

// Function to delete a record
void deleteRecord() {
    ifstream file("students.txt");
    if (!file) {
        cout << "\nNo records found.\n";
        return;
    }

    ofstream temp("temp.txt");
    int id;
    cout << "\nEnter Student ID to delete: ";
    cin >> id;
    bool found = false;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student s;
        string marks_str;
        getline(ss, line, ',');
        s.student_id = stoi(line);
        getline(ss, s.name, ',');
        getline(ss, line, ',');
        s.roll_no = stoi(line);
        getline(ss, s.class_name, ',');
        getline(ss, marks_str, ',');
        s.marks = stof(marks_str);
        getline(ss, s.address);

        if (s.student_id != id)
            temp << s.student_id << "," << s.name << "," << s.roll_no << ","
                 << s.class_name << "," << s.marks << "," << s.address << endl;
        else
            found = true;
    }

    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nRecord deleted successfully.\n";
    else
        cout << "\nRecord not found.\n";
}

// Function to update a record
void updateRecord() {
    ifstream file("students.txt");
    if (!file) {
        cout << "\nNo records found.\n";
        return;
    }

    ofstream temp("temp.txt");
    int id;
    cout << "\nEnter Student ID to update: ";
    cin >> id;
    bool found = false;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Student s;
        string marks_str;
        getline(ss, line, ',');
        s.student_id = stoi(line);
        getline(ss, s.name, ',');
        getline(ss, line, ',');
        s.roll_no = stoi(line);
        getline(ss, s.class_name, ',');
        getline(ss, marks_str, ',');
        s.marks = stof(marks_str);
        getline(ss, s.address);

        if (s.student_id == id) {
            cout << "\nEnter new details:\n";
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, s.name);
            cout << "Enter Roll Number: ";
            cin >> s.roll_no;
            cin.ignore();
            cout << "Enter Class: ";
            getline(cin, s.class_name);
            cout << "Enter Marks: ";
            cin >> s.marks;
            cin.ignore();
            cout << "Enter Address: ";
            getline(cin, s.address);
            found = true;
        }

        temp << s.student_id << "," << s.name << "," << s.roll_no << ","
             << s.class_name << "," << s.marks << "," << s.address << endl;
    }

    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        cout << "\nRecord updated successfully.\n";
    else
        cout << "\nRecord not found.\n";
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n====== Student Database Menu ======\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Search Record\n";
        cout << "4. Delete Record\n";
        cout << "5. Update Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addRecord(); break;
            case 2: displayRecords(); break;
            case 3: searchRecord(); break;
            case 4: deleteRecord(); break;
            case 5: updateRecord(); break;
            case 6: cout << "\nExiting program...\n"; break;
            default: cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
