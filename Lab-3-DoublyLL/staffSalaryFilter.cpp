/*This program will generate a list of staff with salary greater than RM5000. Using the requirements and incomplete program provided below, 
write a complete C++ program using combination of STL Vector and Doubly Linked List implementation.*/
//suitable header(s)
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Data{
    string name;
    float salary;
};

struct Node{
    string name;
    float salary;
    Node *next, *prev;
    Node(string newName, float newSalary){
        next = nullptr;
        prev = nullptr;
        name = newName;
        salary = newSalary;
    }
};

void filterRecord(vector<Data> myStaff, Node **headRef){

    /*this function shall copy all data from STL staff and store it in a doubly
      linked list, ONLY if the value of the salary is greater than RM5000 */
      vector<Data>:: iterator it = myStaff.begin();
      for(;it != myStaff.end(); it++){
        if(it->salary > 5000){
            Node *newNode = new Node(it->name,it->salary);

                if(*headRef == nullptr)
                    *headRef = newNode;
                else{
                    Node *helper = *headRef;
                    while(helper->next != NULL){
                        helper = helper->next;
                    }
                    helper->next = newNode;
                    newNode->prev = helper;
                }
        }
        
      }

}

void display(Node *head){
    cout<<"\n:: Staff Record With Salary > RM5k ::"<<endl;
    /*this function shall display all data in the doubly linked list */
        while(head != nullptr){
            cout << "Name: " << head->name << endl;
            cout << "Salary: RM " << head->salary << endl;
            head = head->next;
        }

}

void removeRecord (Node **headRef){
    string input; 
    Node *p = *headRef, *q;
    cout<<"\n:: Staff Record Deletion ::"<<endl;
    //display(*headRef);
    /*this function shall prompt user to input staff name and delete the record in 
    the doubly linked list (if any)*/
    cout<<"Enter staff name to delete: ";
    cin>>ws;
    getline(cin, input);
    if ((*headRef)->name == input) {
		*headRef = (*headRef)->next;
		free(p);
	}
	else {
		while (p->next->name != input && p != NULL)
			p = p->next;
		q = p->next;
		p->next = q->next;
		free(q);
	}
    display(*headRef);

}


int main(){
    vector<Data>staff = {{"Mei Ling",12000}, {"Rajesh", 4000}, {"Husin", 7500}};
    Data temp;
    /*suitable variable(s)*/
    char sentinel;
    Node *head = nullptr;

    cout<<":: New Record ::"<<endl;
    /* this section shall prompt user to input data for staff name and salary. 
    Store the input data at the end of the STL staff */
    do{
        cout << "Enter staff name: "; cin>>ws; getline(cin,temp.name);
        cout << "Enter staff salary: RM "; cin >> temp.salary;
        staff.push_back(temp);
        cout << "Press [y] to insert more data"; cin >> sentinel;
    }while(sentinel == 'y');
    
    cout<<"\n:: All Staff Record ::"<<endl;
    /*this function shall display all data in the STL staff using iterator */  
    vector<Data>:: iterator it = staff.begin();
    for(; it != staff.end(); it++){
        cout << "Name: " << it->name << endl;
        cout << "Salary: RM " << it->salary << endl; 
    }   

    filterRecord(staff,&head);
    display(head);
    removeRecord(&head);
    cout<<"End of Program";

    return 0;
}
