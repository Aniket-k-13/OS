#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
   
    Complex() {
        real = 0;
        imag = 0;
    }

    
    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    Complex(const Complex &s) {
        real =s.real;
        imag= s.imag;
    }

    void display() {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }

    void add(Complex c) {
        real = real + c.real;
        imag = imag + c.imag;
    }

    void subtract(Complex c) {
        real = real - c.real;
        imag = imag - c.imag;
    }

   
    void multiply(Complex c) {
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;
        real = r;
        imag = i;
    }
};

int main() {
    double r1, i1, r2, i2, r3 , i3;

    cout << "Enter real and imaginary part of first complex number: ";
    cin >> r1 >> i1;

    cout << "Enter real and imaginary part of second complex number: ";
    cin >> r2 >> i2;

    Complex c1 = Complex(r1, i1);
    Complex c2= Complex(r2, i2);
    Complex c3 =  Complex(r3 ,i3);

    c2=c3;



    cout << "\nFirst Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    
    Complex sum = c1;
    sum.add(c2);
    cout << "\nAfter Addition: ";
    sum.display();

    
    Complex diff = c1;
    diff.subtract(c2);
    cout << "After Subtraction: ";
    diff.display();

    
    Complex prod = c1;
    prod.multiply(c2);
    cout << "After Multiplication: ";
    prod.display();



  
    return 0;
}
