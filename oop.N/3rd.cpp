#include <iostream>

class Student {
private:
    int roll_no;
    std::string name;
    double marks[5];
    double percentage;
    std::string grade;

public:
    
    Student(int r, std::string n,double m1, double m2, double m3,double m4, double m5) {
        roll_no = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        marks[3] = m4;
        marks[4] = m5;
        percentage = 0;
        grade = "";
    }

    
    ~Student() {
        std::cout << "Destructor called for " << name << std::endl;
    }


    void calculate() {
        double total = 0;
        for (int i = 0; i < 5; i++) {
            total += marks[i];
        }
        percentage = total / 5;

        if (percentage >= 60)
            grade = "First Class";
        else if (percentage >= 50)
            grade = "Second Class";
        else if (percentage >= 40)
            grade = "Third Class";
        else
            grade = "Fail";
    }

   
    void display() {
        std::cout << "\n--- Student Details ---" << std::endl;
        std::cout << "Roll No: " << roll_no << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Marks: ";
        for (int i = 0; i < 5; i++)
            std::cout << marks[i] << " ";
        std::cout << std::endl;
        std::cout << "Percentage: " << percentage << "%" << std::endl;
        std::cout << "Grade/Class: " << grade << std::endl;
    }
};

int main() {
    int roll;
    std::string name;
    double m1, m2, m3, m4, m5;

    std::cout << "Enter Roll Number: ";
    std::cin >> roll;
    std::cin.ignore(); // clear newline
    std::cout << "Enter Name: ";
    getline(std::cin, name);

    std::cout << "Enter marks of 5 subjects: ";
    std::cin >> m1 >> m2 >> m3 >> m4 >> m5;

    // Create Student object
    Student s1(roll, name, m1, m2, m3, m4, m5);

    s1.calculate(); // Calculate percentage and grade
    s1.display();   // Display details

    return 0; // Destructor called automatically
}
