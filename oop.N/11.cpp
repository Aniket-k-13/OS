#include <iostream>
#include <stdexcept>  
using namespace std;

int main() {
    try {
        int a, b;
        cout << "Enter two numbers (a and b): ";
        cin >> a >> b;

        // Arithmetic Exception: Division by zero
        if (b == 0)
            throw runtime_error("Error: Division by zero is not allowed!");

        cout << "Result of division (a / b): " << a / b << endl;

        // Array Index Out of Bounds
        int arr[5] = {10, 20, 30, 40, 50};
        int index;

        cout << "Enter array index (0 to 4): ";
        cin >> index;

        if (index < 0 || index >= 5)
            throw out_of_range("Error: Array index out of bounds!");

        cout << "Value at index " << index << ": " << arr[index] << endl;
    }

    // Catch block for arithmetic error
    catch (runtime_error &e) {
        cout << e.what() << endl;
    }

    // Catch block for out of range error
    catch (out_of_range &e) {
        cout << e.what() << endl;
    }

    // Generic catch block for unexpected exceptions
    catch (...) {
        cout << "An unexpected error occurred!" << endl;
    }

    cout << "Program completed successfully." << endl;
    return 0;
}
