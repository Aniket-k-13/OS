#include <iostream>
#include <cmath>
using namespace std;

bool isEven(int n) { return n % 2 == 0; }
bool isOdd(int n) { return n % 2 != 0; }

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return false;
    return true;
}

bool isPalindrome(int n) {
    string s = to_string(n);
    string rev = string(s.rbegin(), s.rend());
    return s == rev;
}

template <typename T>
int countIf(T arr[], int size, bool (*property)(T)) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (property(arr[i]))
            count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int choice;

    while (true) {
        cout << "\n=============================\n";
        cout << "Choose property to count:\n";
        cout << "1. Even Numbers\n";
        cout << "2. Odd Numbers\n";
        cout << "3. Prime Numbers\n";
        cout << "4. Palindromes\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cout << "=============================\n";

        if (choice == 5) {
            cout << "Exiting program... Goodbye!\n";
            break;
        }

        int result = 0;

        switch (choice) {
            case 1: result = countIf(arr, n, isEven); break;
            case 2: result = countIf(arr, n, isOdd); break;
            case 3: result = countIf(arr, n, isPrime); break;
            case 4: result = countIf(arr, n, isPalindrome); break;
            default:
                cout << "Invalid choice! Please try again.\n";
                continue;
        }

        cout << "\nNumber of elements satisfying the chosen property: " << result << endl;
    }

    return 0;
}
