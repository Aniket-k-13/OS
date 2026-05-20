#include <iostream>

class Student {
private:
    int roll_no;
    std::string name;
    float marks;

public:
    
    Student() {
        std::cout << "Constructor called!" << std::endl;
        roll_no = 0;
        name = "Unknown";
        marks = 0.0;
    }

    
    Student(int r, std::string n, float m) {
        std::cout << "Parameterized Constructor called!" << std::endl;
        roll_no = r;
        name = n;
        marks = m;
    }

    
    void get_details() {
        std::cout << "Enter Roll Number: ";
        std::cin >> roll_no;
        std::cin.ignore(); 

        std::cout << "Enter Name: ";
        std::getline(std::cin, name);

        std::cout << "Enter Marks: ";
        std::cin >> marks;
    }

    
    void show_details() {
        std::cout << "\n--- Student Details ---" << std::endl;
        std::cout << "Roll No: " << roll_no << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Marks: " << marks << std::endl;
    }

    // Destructor
    ~Student() {
        std::cout << "Destructor called for " << name << "!" << std::endl;
    }
};


int main() {

    Student student1;
    student1.get_details();
    student1.show_details();

    Student student2 = Student(102, "Aniket", 89.5); 
    student2.show_details();

    std::cout << "\nEnd of main function..." << std::endl;
    return 0; 
}
