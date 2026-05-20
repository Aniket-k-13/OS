#include <iostream>
using namespace std;

class Publication {
protected:
    string title;
    double price;
    int copies;

public:
    Publication() {
        title = "";
        price = 0;
        copies = 0;
    }

    Publication(string t, double p, int c) {
        title = t;
        price = p;
        copies = c;
    }

    
    double saleCopy() {
        return price * copies;
    }

    void display() {
        cout << "Title: " << title << ", Price: " << price
             << ", Copies: " << copies << endl;
    }
};

class Book : public Publication {
private:
    string author;

public:
    Book() {}

    Book(string t, string a, double p, int c) : Publication(t, p, c) {
        author = a;
    }

    void getDetails() {
        cout << "\nEnter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Number of Copies: ";
        cin >> copies;
        cin.ignore(); 
    }

    void orderCopies(int num) {
        copies += num;
        cout << num << " copies of book \"" << title << "\" ordered.\n";
    }

    void display() {
        Publication::display();
        cout << "Author: " << author << endl;
    }
};


class Magazine : public Publication {
private:
    string currentIssue;

public:
    Magazine() {}

    Magazine(string t, string issue, double p, int c) : Publication(t, p, c) {
        currentIssue = issue;
    }

    void getDetails() {
        cout << "\nEnter Magazine Title: ";
        getline(cin, title);
        cout << "Enter Current Issue: ";
        getline(cin, currentIssue);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Number of Copies: ";
        cin >> copies;
        cin.ignore();
    }

    void orderQty(int num) {
        copies += num;
        cout << num << " copies of magazine \"" << title << "\" ordered.\n";
    }

    void receiveIssue(string issue) {
        currentIssue = issue;
        cout << "Magazine \"" << title << "\" updated to issue: " << currentIssue << endl;
    }

    void display() {
        Publication::display();
        cout << "Current Issue: " << currentIssue << endl;
    }
};


int main() {
    int nBooks, nMagazines;
    double totalSale = 0;

    cout << "Enter number of books: ";
    cin >> nBooks;
    cin.ignore();

    Book books[10]; 
    for (int i = 0; i < nBooks; i++) {
        cout << "\n--- Enter details for Book " << i + 1 << " ---";
        books[i].getDetails();

        int order;
        cout << "Enter how many more copies to order: ";
        cin >> order;
        books[i].orderCopies(order);
        cin.ignore();
    }

    cout << "\nEnter number of magazines: ";
    cin >> nMagazines;
    cin.ignore();

    Magazine mags[10];
    for (int i = 0; i < nMagazines; i++) {
        cout << "\n--- Enter details for Magazine " << i + 1 << " ---";
        mags[i].getDetails();

        int order;
        cout << "Enter how many more copies to order: ";
        cin >> order;
        mags[i].orderQty(order);
        cin.ignore();
    }

    cout << "\n--- Publication Details ---\n";
    for (int i = 0; i < nBooks; i++) {
        books[i].display();
        totalSale += books[i].saleCopy();
    }

    for (int i = 0; i < nMagazines; i++) {
        mags[i].display();
        totalSale += mags[i].saleCopy();
    }

    cout << "\nTotal sale of all publications: " << totalSale << endl;

    return 0;
}
