/*Design and develop inheritance for a given case study, identify objects and relationships and implement 
inheritance wherever applicable. Employee class has Emp_name, Emp_id, Address, Mail_id, and Mobile_no as members. 
Inherit the classes: Programmer, Team Lead, Assistant Project Manager and Project Manager from employee class.
 Add Basic Pay (BP) as the member of all the inherited classes with 52% of BP as DA, 27 % of BP as HRA,
  12% of BP as PF, 0.1% of BP for staff club fund. Generate pay slips for the employees with their gross 
  and net salary.*/


#include <iostream>
using namespace std;

class Employee {
public:
    string Emp_name;
    int Emp_id;
    string Address;
    string Mail_id;
    int Mobile_no;   

    void getDetails() {
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, Emp_name);

        cout << "Enter Employee ID: ";
        cin >> Emp_id;
        cin.ignore();

        cout << "Enter Address: ";
        getline(cin, Address);

        cout << "Enter Mail ID: ";
        getline(cin, Mail_id);

        cout << "Enter Mobile Number (only last few digits if overflow): ";
        cin >> Mobile_no;
    }

    void displayDetails() {
        cout << "\nEmployee Name  : " << Emp_name;
        cout << "\nEmployee ID    : " << Emp_id;
        cout << "\nAddress        : " << Address;
        cout << "\nMail ID        : " << Mail_id;
        cout << "\nMobile Number  : " << Mobile_no;
    }
};

class Programmer : public Employee {
public:
    double Basic_Pay;

    void getSalaryDetails() {
        cout << "Enter Basic Pay for Programmer: ";
        cin >> Basic_Pay;
    }

    void generatePaySlip() {
        double DA = 0.52 * Basic_Pay;
        double HRA = 0.27 * Basic_Pay;
        double PF = 0.12 * Basic_Pay;
        double Club = 0.001 * Basic_Pay;

        double Gross = Basic_Pay + DA + HRA;
        double Net = Gross - PF - Club;

        displayDetails();
        cout << "\n\n------ PAY SLIP (Programmer) ------";
        cout << "\nBasic Pay        : " << Basic_Pay;
        cout << "\nDA (52%)         : " << DA;
        cout << "\nHRA (27%)        : " << HRA;
        cout << "\nPF (12%)         : " << PF;
        cout << "\nStaff Club (0.1%): " << Club;
        cout << "\nGross Salary     : " << Gross;
        cout << "\nNet Salary       : " << Net << endl;
    }
};

class Team_Lead : public Employee {
public:
    double Basic_Pay;

    void getSalaryDetails() {
        cout << "Enter Basic Pay for Team Lead: ";
        cin >> Basic_Pay;
    }

    void generatePaySlip() {
        double DA = 0.52 * Basic_Pay;
        double HRA = 0.27 * Basic_Pay;
        double PF = 0.12 * Basic_Pay;
        double Club = 0.001 * Basic_Pay;

        double Gross = Basic_Pay + DA + HRA;
        double Net = Gross - PF - Club;

        displayDetails();
        cout << "\n\n------ PAY SLIP (Team Lead) ------";
        cout << "\nBasic Pay        : " << Basic_Pay;
        cout << "\nDA (52%)         : " << DA;
        cout << "\nHRA (27%)        : " << HRA;
        cout << "\nPF (12%)         : " << PF;
        cout << "\nStaff Club (0.1%): " << Club;
        cout << "\nGross Salary     : " << Gross;
        cout << "\nNet Salary       : " << Net << endl;
    }
};

class Assistant_Project_Manager : public Employee {
public:
    double Basic_Pay;

    void getSalaryDetails() {
        cout << "Enter Basic Pay for Assistant Project Manager: ";
        cin >> Basic_Pay;
    }

    void generatePaySlip() {
        double DA = 0.52 * Basic_Pay;
        double HRA = 0.27 * Basic_Pay;
        double PF = 0.12 * Basic_Pay;
        double Club = 0.001 * Basic_Pay;

        double Gross = Basic_Pay + DA + HRA;
        double Net = Gross - PF - Club;

        displayDetails();
        cout << "\n\n------ PAY SLIP (Assistant Project Manager) ------";
        cout << "\nBasic Pay        : " << Basic_Pay;
        cout << "\nDA (52%)         : " << DA;
        cout << "\nHRA (27%)        : " << HRA;
        cout << "\nPF (12%)         : " << PF;
        cout << "\nStaff Club (0.1%): " << Club;
        cout << "\nGross Salary     : " << Gross;
        cout << "\nNet Salary       : " << Net << endl;
    }
};

class Project_Manager : public Employee {
public:
    double Basic_Pay;

    void getSalaryDetails() {
        cout << "Enter Basic Pay for Project Manager: ";
        cin >> Basic_Pay;
    }

    void generatePaySlip() {
        double DA = 0.52 * Basic_Pay;
        double HRA = 0.27 * Basic_Pay;
        double PF = 0.12 * Basic_Pay;
        double Club = 0.001 * Basic_Pay;

        double Gross = Basic_Pay + DA + HRA;
        double Net = Gross - PF - Club;

        displayDetails();
        cout << "\n\n------ PAY SLIP (Project Manager) ------";
        cout << "\nBasic Pay        : " << Basic_Pay;
        cout << "\nDA (52%)         : " << DA;
        cout << "\nHRA (27%)        : " << HRA;
        cout << "\nPF (12%)         : " << PF;
        cout << "\nStaff Club (0.1%): " << Club;
        cout << "\nGross Salary     : " << Gross;
        cout << "\nNet Salary       : " << Net << endl;
    }
};


int main() {
    int choice;
    cout << "========= Employee Payroll System =========";
    cout << "\n1. Programmer\n2. Team Lead\n3. Assistant Project Manager\n4. Project Manager";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            Programmer p;
            p.getDetails();
            p.getSalaryDetails();
            p.generatePaySlip();
            break;
        }
        case 2: {
            Team_Lead t;
            t.getDetails();
            t.getSalaryDetails();
            t.generatePaySlip();
            break;
        }
        case 3: {
            Assistant_Project_Manager a;
            a.getDetails();
            a.getSalaryDetails();
            a.generatePaySlip();
            break;
        }
        case 4: {
            Project_Manager m;
            m.getDetails();
            m.getSalaryDetails();
            m.generatePaySlip();
            break;
        }
        default:
            cout << "Invalid choice!";
    }

    return 0;
}
