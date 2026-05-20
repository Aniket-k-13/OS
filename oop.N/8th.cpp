#include <iostream>

class Shape {
protected:
    double dimension1;
    double dimension2;

public:
   
    void input_data() {
        std::cout << "Enter dimension 1 (in cm): ";
        std::cin >> dimension1;
        std::cout << "Enter dimension 2 (in cm): ";
        std::cin >> dimension2;
    }

    virtual void compute_area() = 0;
};

class Triangle : public Shape {
public:
   
    void compute_area() override {
        double area = 0.5 * dimension1 * dimension2;
        std::cout << "Area of Triangle: " << area << " sq cm" << std::endl;
    }
};

class Rectangle : public Shape {
public:
   
    void compute_area() override {
        double area = dimension1 * dimension2;
        std::cout << "Area of Rectangle: " << area << " sq cm" << std::endl;
    }
};

int main() {
   
    Shape* shape_ptr = nullptr;

    int choice;

    std::cout << "Select a shape to calculate its area:" << std::endl;
    std::cout << "1. Triangle" << std::endl;
    std::cout << "2. Rectangle" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";
    std::cin >> choice;

    if (choice == 1) {
        
        shape_ptr = new Triangle();
        std::cout << "\n--- Calculating Area of Triangle ---" << std::endl;
        std::cout << "(Dimension 1 will be base, Dimension 2 will be height)" << std::endl;

    } else if (choice == 2) {
        shape_ptr = new Rectangle();
        std::cout << "\n--- Calculating Area of Rectangle ---" << std::endl;
        std::cout << "(Dimension 1 will be length, Dimension 2 will be width)" << std::endl;
    } else {
        std::cout << "Invalid choice." << std::endl;
        return 1; 
    }

    shape_ptr->input_data();
    shape_ptr->compute_area();

    delete shape_ptr;

    return 0;
}

