#include <iostream>

class Book {
private:
    int bookid;
    std::string book_name;
    std::string author;
    float price;

public:
    
    void get_details() {
        std::cout << "Enter Book ID: ";
        std::cin >> bookid;
        std::cin.ignore(); 

        std::cout << "Enter Book Name: ";
        std::getline(std::cin, book_name);

        std::cout << "Enter Author Name: ";
        std::getline(std::cin, author);

        std::cout << "Enter Book Price: ";
        std::cin >> price;
    }

    
    void print_details() {
        std::cout << bookid << "\t" 
             << book_name << "\t\t" 
             << author << "\t\t" 
             << price <<std::endl;
    }

    double get_price() {
        return price;
    }
};

int main() {
    int n;
    double total_price = 0;

    std::cout << "Enter number of books: ";
    std::cin >> n;

    Book books[100];

    std::cout << std::endl;
    
    for (int i = 0; i < n; i++) {
        std::cout << "Enter details for Book " << i + 1 << ":\n";
        books[i].get_details();
        std::cout << std::endl;
    }

    
    std::cout << "--------------------------------------------------------------\n";
    std::cout << "Book ID\tBook Name\t\tAuthor\t\tPrice\n";
    std::cout << "--------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        books[i].print_details();
        total_price += books[i].get_price();
    }

    std::cout << "--------------------------------------------------------------\n";
    std::cout << "Total Price of all books: " << total_price << std::endl;
    std::cout << "--------------------------------------------------------------\n";

    return 0;
}
