#include <iostream>

class BankAccount {
private:
    int accountNo;
    std::string name;
    double balance;

    static int totalAccounts;
    static double totalBalance;

public:
    
    BankAccount() {
        accountNo = 0;
        name = "";
        balance = 0;
    }

    
    BankAccount(int accNo, std::string n, double bal) {
        accountNo = accNo;
        name = n;
        balance = bal;

        totalAccounts++;
        totalBalance += bal;
    }

    
    void display() {
        std::cout << "Account No: " << accountNo
                  << ", Name: " << name
                  << ", Balance: " << balance << std::endl;
    }

    
    void displayAscending(BankAccount other) {
        std::cout << "Balances in ascending order: ";
        if (balance < other.balance)
            std::cout << balance << " , " << other.balance << std::endl;
        else
            std::cout << other.balance << " , " << balance << std::endl;
    }

    
    static void displayBankStats() {
        std::cout << "\nTotal Accounts: " << totalAccounts << std::endl;
        std::cout << "Total Balance: " << totalBalance << std::endl;
    }

    
    double getBalance() {
        return balance;
    }
};


int BankAccount::totalAccounts = 0;
double BankAccount::totalBalance = 0;

int main() {
    int n;
    std::cout << "Enter number of accounts to create: ";
    std::cin >> n;

    BankAccount accounts[100];

    
    for (int i = 0; i < n; i++) {
        int accNo;
        std::string name;
        double bal;

        std::cout << "\nEnter details for Account " << i + 1 << ":\n";
        std::cout << "Account Number: ";
        std::cin >> accNo;
        std::cout << "Name: ";
        std::getline(std::cin, name);
        std::cout << "Initial Balance: ";
        std::cin >> bal;

        accounts[i] = BankAccount(accNo, name, bal);
    }

    std::cout << "\nAll Accounts:\n";
    for (int i = 0; i < n; i++)
        accounts[i].display();

    BankAccount::displayBankStats();

    int idx1, idx2;
    std::cout << "\nEnter indices (1-based) of two accounts to compare balances: ";
    std::cin >> idx1 >> idx2;

    if (idx1 >= 1 && idx1 <= n && idx2 >= 1 && idx2 <= n) {
        accounts[idx1 - 1].displayAscending(accounts[idx2 - 1]);
    } else {
        std::cout << "Invalid account indices!" << std::endl;
    }

    return 0;
}
