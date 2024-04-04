/*This program will generate a dean list record based on the students’ cgpa. Using the requirements and incomplete program provided below,
write a complete C++ program for the dean list program using STL List and Linked List implementation.*/
//suitable header(s)
#include<iostream>
#include<iomanip>
#include<list>
using namespace std;

struct Data{
    string name;
    float cgpa;
};

struct Node{
    string name;
    float cgpa;
    Node *next;
    Node(string newName,float newCgpa){
        next = NULL;
        name = newName;
        cgpa = newCgpa;
    }
};

void filterRecord(list<Data> myStudent, Node **headRef){

    /*this function shall copy all data from storage student and store it in a singly   
      linked list, ONLY if the value of cgpa is 3.50 and above */
      list<Data>:: iterator it = myStudent.begin();
      for(;it != myStudent.end(); it++){
        if(it->cgpa > 3.50){
        Node *newNode = new Node(it->name,it->cgpa);
        if(*headRef == NULL){
            *headRef = newNode;
        }
        else{
            Node *current = *headRef;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = newNode;
             }
        }
    }

}

void display(Node *head){
    cout<<"\n:: Dean List Record ::"<<endl;

    /*this function shall display all data in the singly linked list */
    while(head != NULL){
        cout << "Name: " << head->name << endl;
        cout << "Cgpa: " << head->cgpa << endl;
        head = head->next;
    }
}

int main()
{
    list<Data>student = {{"Mei Ling",3.92}, {"Rajesh", 2.68}, {"Husin", 3.7}}; 
    Data temp;
    /*suitable variable(s)*/
    Node *head = NULL;
    char sentinel;
    
    cout<<":: New Record ::"<<endl;
    /*this section shall prompt user to input data for student name and cgpa. 
    Store the input data at the beginning of the storage student */
    do{
        cout << "Enter student name: "; cin >> temp.name;
        cout << "Enter student cgpa: "; cin >> temp.cgpa;
        student.push_front(temp);
        cout << "Do you want to add more record ?('y' to continue): "; cin >> sentinel;
    }while(sentinel == 'y');
    
    cout<<"\n:: All Students Record ::"<<endl;
    /*this function shall display all data in the storage student using iterator */    
    list<Data>::iterator it = student.begin();
    for(; it != student.end(); it++){
        cout << "Student name: " << it->name << endl;
        cout << "Student cgpa: " << fixed << setprecision(2) << it->cgpa << endl;
    }     
    
    filterRecord(student,&head);
    display(head);
    cout<<"End of Program";

    return 0;

}