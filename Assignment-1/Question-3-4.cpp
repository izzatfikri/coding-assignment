#include <iostream>
#include <iomanip>
using namespace std;

class Meal{
    //Question 3(1)
    public:
    string name;
    string remark;
    int quantity;
    float price, total;
    Meal *next = NULL;
    Meal(){
        remark = "Normal";
    }
};

int menu() {
	int choice;
	cout << "::FOOD ORDERING::\n";
	cout << "1. Add meal\n"; 	
    cout << "2. Display meal\n";
	cout << "3. Update meal\n";
	cout << "4. Exit program\n";
	cout << "Enter choice: ";
	cin >> choice;
	cin.ignore();
	return choice;
}

Meal *mealInfo() {
	//Question 3(2)
	//create a new node
	//accept user’s data inputs
	//return address of new node to addMeal()
	char member;

	cout << "Do you have membership?(y/n): "; cin >> member;

    Meal *n = new Meal();


	cout << "Enter meal name: ";
	cin >> ws; getline(cin, n->name);

	cout << "Enter meal quantity: ";
	cin >> n->quantity;

	cout << "Enter meal price: ";
	cin >> n->price;

	n->total = (n->quantity)*(n->price);

	if(member == 'y'){
		n->total = n->total * 0.90;
		n->remark = "Membership";
	}
    
    return n;
}

void addMeal(Meal **headRef){
      //Question 3(3)      
      //invoke mealInfo() and accept new node’s address
	  //add new node to linked list
      Meal *newNode = mealInfo();

	  if(*headRef == NULL){
		*headRef = newNode;
	  }

	  else{
		Meal *current = *headRef;
		while(current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	  }


}

void display(Meal *head) {
	//Question 3(4)
	//accept user’s input (option)
	//display meal according to user’s input (option)

	int choice;

	cout << "Enter '1' for display individual meal, '2' for all meals in record: ";
	cin >> choice;

	if(choice == 1){
		string mealName;
		cout << "Enter meal name: ";
		cin >> mealName;

		while(head->name != mealName){
			head = head->next;
		}

		cout << "Name: " << head->name << endl;
		cout << "Quantity: " << head->quantity << endl;
		cout << "Price: " << head->price << endl;
		cout << "Total: RM " << fixed << setprecision(2) << head->total << endl;
		cout << "Remark: " << head->remark << endl;

	}

	else{
		while(head != NULL){
			cout << "Name: " << head->name << endl;
			cout << "Quantity: " << head->quantity << endl;
			cout << "Price: " << head->price << endl;
			cout << "Total: RM " << fixed << setprecision(2) << head->total << endl;
			cout << "Remark: " << head->remark << endl;
			head = head->next;
		}
	}

}

void update(Meal **headRef) {
	//Question 4
	//update meal according to user’s input (option)
	string mealName;
	int choice;
	Meal *current = *headRef;

	cout << "Enter meal name: "; cin >> mealName;

	while(current->name != mealName){
		current = current->next;
	}

	cout << "1: Update Meal Name\n2: Update Meal Quantity\n3: Update Meal Price\nEnter Choice: ";
	cin >> choice;

	if(choice == 1){
		cout << "Enter new name: "; cin >> ws; getline(cin, current->name);
	}
	else if(choice == 2){
		if(current->remark == "Membership"){
			cout << "Enter new quantity: "; cin >> current->quantity;
			current->total = 0.9*current->price*current->quantity;
		}
		else{
			cout << "Enter new quantity: "; cin >> current->quantity;
			current->total = current->price*current->quantity;
		}
	}
	else{
		if(current->remark == "Membership"){
		cout << "Enter new price: "; cin >> current->price;
		current->total = 0.9*current->price*current->quantity;
		}
		else{
			cout << "Enter new price: "; cin >> current->price;
			current->total = current->price*current->quantity;
		}
	}

}

int main() {
	//declaration of variables
    string name;
	Meal *head = NULL;
    int table, choice;
	cout<<"Enter customer name : ";
	getline(cin, name);
	cout<<"Enter table no : ";
	cin>>table;
	do {
		choice = menu();
            switch (choice) {
            case 1: //call function addMeal()
			addMeal(&head);
			break;
            case 2: //call function display()
			display(head);
			break;
            case 3: //call function update()
			update(&head);
			break;
		}
	} while (choice != 4);
	return 0;
}

