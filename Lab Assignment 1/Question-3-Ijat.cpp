/*This program will generate a list of staff with salary greater than RM5000. Using the requirements and incomplete program provided below,
 write a complete C++ program using combination of STL Vector and Doubly Linked List implementation.*/
//suitable header(s)
#include<iostream>
#include<vector>
using namespace std;

struct Data{
    string name;
    float salary;
};

struct Node{
    string name;
    float salary;
    Node *next, *prev;
    //declare constructor
    Node(string tempName, float tempSalary){
        next = nullptr;
        prev = nullptr;
        name = tempName;
        salary = tempSalary;
    }
};

void filterRecord(vector<Data> myVec, Node **headRef){

    /*this function shall copy all data from STL staff and store it in a doubly
      linked list, ONLY if the value of the salary is greater than RM5000 */

      vector<Data>:: iterator it = myVec.begin();
      for(;it != myVec.end(); it++){
        if(it->salary > 5000){
        Node *newNode = new Node(it->name,it->salary);
        if(*headRef == NULL){
            *headRef = newNode;
        }
        else{
            Node *current = *headRef;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
            }
        }
    }

}

void display(Node *head){
    cout<<"\n:: Staff Record With Salary > RM5k ::"<<endl;
    /*this function shall display all data in the doubly linked list */
    while(head != NULL){
        cout << "Name: " << head->name << endl;
        cout << "Salary: " << head->salary << endl;
        head = head->next;
    }

}

void removeRecord (Node **headRef){
    string input; /*suitable variable(s)*/
    string ws;
    cout<<"\n:: Staff Record Deletion ::"<<endl;

    /*this function shall prompt user to input staff name and delete the record in 
    the doubly linked list (if any)*/

    cout<<"Enter staff name to delete: ";
    cin>>ws;
    getline(cin, input);

    Node *current = *headRef;
    Node *prev = nullptr;

    while (current != nullptr) {
        if (current->name == input) {
            /* Node found, perform deletion */
            if (prev != nullptr) {
                prev->next = current->next;
                if (current->next != nullptr) {
                    current->next->prev = prev;
                }
                delete current;
            } else {
                /* Deletion at the head */
                *headRef = current->next;
                if (current->next != nullptr) {
                    current->next->prev = nullptr;
                }
                delete current;
            }
        }
            cout << "Record for " << input << " deleted successfully." << endl;
            return;
}
}

int main(){
    vector<Data>staff = {{"Mei Ling",12000}, {"Rajesh", 4000}, {"Husin", 7500}};
    Data temp;
    /*suitable variable(s)*/
    char sentinel;
    Node *head = NULL;

    cout<<":: New Record ::"<<endl;
    /* this section shall prompt user to input data for staff name and salary. 
    Store the input data at the end of the STL staff */
    do{
        cout << "Enter staff name: "; cin >> ws; getline(cin,temp.name);
        cout << "Enter staff salary: "; cin >> temp.salary;
        staff.push_back(temp); //Store input data at the end of the STL staff
        cout << "Do you want to add more data? (press y to continue): "; cin >> sentinel;
    }while(sentinel == 'y');
    
    cout<<"\n:: All Staff Record ::"<<endl;
    /*this function shall display all data in the STL staff using iterator */    
    vector<Data>:: iterator it;
    for(it = staff.begin(); it != staff.end(); it++){
        cout << "Name: " << it->name << endl;
        cout << "Salary: " << it->salary << endl;
    } 

    filterRecord(staff,&head);
    display(head);
    removeRecord(&head);
    cout<<"End of Program";

    return 0;
}
