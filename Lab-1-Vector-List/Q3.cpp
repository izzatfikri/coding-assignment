//Muhammad Izzat Fikri (SW01082295)
//Question 3

#include<iostream>
#include<vector>
using namespace std;

struct Book
{
    string bookName;
    int bookID;
    float price;
    int bookQty;
};

void registerBook(Book ,vector<Book>& );
void displayBook(vector<Book>& );
int menu(void);


int main(){

    vector<Book> Record;
    Book data;
    int choice;

    do {
		choice = menu();
		switch (choice) {
		  case 1: registerBook(data, Record); cout << endl;
          break;

          case 2: displayBook(Record); cout << endl;
          break; 
		  //case 3: //call function deleteBook()
		  //case 4: //call function updateBook()
		}
	} while (choice != 5);

    return 0;
}

void registerBook(Book data, vector<Book>& books ){
    cout << "Enter book name: ";
    cin >> data.bookName;
    
    cout << "Enter bookID: ";
    cin >> data.bookID;

    cout << "Enter price: ";
    cin >> data.price;

    cout << "Enter bookQty: ";
    cin >> data.bookQty;

    books.push_back(data);
}

void displayBook(vector<Book>& books) {
    int bookID;
    cout << "Enter book ID: ";
    cin >> bookID;

    // Use an iterator to traverse the vector
    for (vector<Book>::iterator it = books.begin(); it != books.end(); ++it) {
        if (it->bookID == bookID) {
            cout << "Book ID: " << it->bookID << endl;
            cout << "Book Name: " << it->bookName << endl;
            cout << "Price: " << it->price << endl;
            cout << "Quantity: " << it->bookQty << endl;
            return; // Book found, no need to continue searching
        }
    }

    cout << "Book not found with the given ID." << endl;
}

int menu(void){
    int choice;
	cout << "::BOOK STORE PROGRAM MENU::\n";
	cout << "1. Register book\n";
	cout << "2. Display book record\n";
	cout << "3. Delete book\n";
	cout << "4. Update Book\n";
	cout << "5. Exit program\n";
	cout << "Enter choice: ";
	cin >> choice;
	return choice;
}