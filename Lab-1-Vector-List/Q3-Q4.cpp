/*Referring to Sample of Program at last page, complete the following questions:
1.	Import suitable preprocessor (header)
2.	Create a struct named Book that holds data members: bookName (string), bookID (int), price (float) and bookQty (int)
3.	Complete a function named registerBook(). This function should accept all input of struct data members.
4.	Complete a function named displayBook() based on following conditions:
•	Option 1 (individual): User will enter book ID as input and function will display the details of individual book.
•	Option 2: Function will display details of all books in record.*/


#include<iostream>
#include<vector>
using namespace std;

struct Book
{
    /* data */
    string bookName;
    int bookID;
    float price;
    int bookQty;
};

void registerBook(Book , vector<Book>& );
void displayBook(vector<Book>& );
void deleteBook(vector<Book>& , int );
void updateBook(vector<Book>& , int );
int menu(void);


int main(){

    vector<Book> Record;
    Book data;
    int choice;
    int bookID;
    do {
		choice = menu();
		switch (choice) {
		  case 1: registerBook(data,Record);//call function registerBook() and push the data to vector. 
          break;
          case 2: displayBook(Record);
          break;
		  case 3: 
          //int bookID; 
          cout << "Enter book ID to delete: ";
          cin >> bookID;
          deleteBook(Record, bookID);
          break;
		  case 4:
          //int bookID;
          cout << "Enter book ID to update: ";
          cin >> bookID;
          updateBook(Record, bookID);
          break;
		}
	} while (choice != 5);

    return 0;
}

int menu() {
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

void registerBook(Book data, vector<Book>& rec){
   cout << "Enter book name: ";
    cin >> data.bookName;
    
    cout << "Enter bookID: ";
    cin >> data.bookID;

    cout << "Enter price: ";
    cin >> data.price;

    cout << "Enter bookQty: ";
    cin >> data.bookQty;

    rec.push_back(data);
}

void displayBook(vector<Book>& rec){
    int id;
    int choice;

    cout << "\nEnter 1 to search specific book\nEnter 2 to display details of all books in record\nEnter choice: ";
    cin >> choice;

    if(choice == 1){
    cout << "Enter book ID: ";
    cin >> id;
    //Use iterator
    vector<Book>::iterator it;
   for(it = rec.begin(); it != rec.end(); it++){
    if(it->bookID == id){
        cout << "Book ID: " << it->bookID << endl;
        cout << "Book Name: " << it->bookName << endl;
        cout << "Price: " << it->price << endl;
        cout << "Quantity: " << it->bookQty << endl;
            return; // Book found, no need to continue searching
    }
   }
    }
    else{
    vector<Book>::iterator it;
        for(it = rec.begin(); it != rec.end(); it++){
                 cout << "---------------------------------------\n";
                 cout << "Book ID: " << it->bookID << endl;
                 cout << "Book Name: " << it->bookName << endl;
                 cout << "Price: " << it->price << endl;
                 cout << "Quantity: " << it->bookQty << endl;
                 cout << "---------------------------------------\n";
            
   }

    }
}

void deleteBook(vector<Book>& rec, int id){

    vector<Book>::iterator it;
    for(it = rec.begin(); it != rec.end(); it++){

        if(it->bookID == id){
            it = rec.erase(it);
            cout << "Book with ID " << id << " deleted successfully!\n" << endl;
            return;
        }

    }
    cout << "Book not found with the given ID.\n" << endl;

}

void updateBook(vector<Book>& rec , int id){

    vector<Book>::iterator it;
    for(it = rec.begin(); it != rec.end(); it++){
        if(it->bookID == id){
        int updateChoice;
        cout << "Enter 1 to update bookname: \n";
        cout << "Enter 2 to update price: \n";
        cout << "Enter 3 to update book quantity: \n";
        cin >> updateChoice;

            switch(updateChoice){
                case 1: 
                cout << "Enter new book name: "; cin >> it->bookName; cout << "Book name updated successfully!\n"; break;
                case 2: 
                cout << "Enter new price: "; cin >> it->price; cout << "Book price updated successfully!\n"; break;
                case 3:
                cout << "Enter new qty: "; cin >> it->bookQty; cout << "Book quantity updated successfully!\n"; break;
            }
        return;
        }
    }
    cout << "Book not found with the given ID.\n" << endl;

}