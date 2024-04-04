//Muhammad Izzat Fikri Bin Zurilan, SW01082295 
//preprocessor
#include<iostream>
#include<queue>
using namespace std;
//details of functions involved

struct record{
    string name;
    float salary;
    int service;
};

void insert(queue<record> *myStaff, string name[], float salary[], int service[]){
    int i = 0;
    record rec;
  
    for(; i<6; i++){
        rec.name = name[i];
        rec.salary = salary[i];
        rec.service = service[i];
        myStaff->push(rec);
    }
    cout << endl;
}

void display(queue<record> myStaff){

    int i = 1;
    cout << "List of Employee";
    cout << "\n--------------------------------------------";

    while(!myStaff.empty()){
        cout << "\n" << i << ". Staff Name: " << myStaff.front().name << ", Salary : RM " << myStaff.front().salary << ", Year of Service: " << myStaff.front().service;
        myStaff.pop();
        i++;
    }
    cout << endl;
}

void update(queue<record> *myStaff){

    queue<record> temp;
    string name;
    float salary;
    int service;
    int choice;

    cout << "Enter name : "; getline(cin,name);

    while(!myStaff->empty()){
       
    if(myStaff->front().name == name){
        cout << "Press [1] for Salary or [2] for Year of Service: ";
        cin >> choice;
        if(choice == 1){
            cout << "Enter new salary: "; cin >> salary;
            myStaff->front().salary = salary;
        }
        else if(choice == 2){
            cout << "Enter new year of service: "; cin >> service;
            myStaff->front().service = service;
        }
    }
    temp.push(myStaff->front());
    myStaff->pop();
    }
    //Rebuild the queue
    while(!temp.empty()){
        myStaff->push(temp.front());
        temp.pop();
    }

}



        
int main() {
    string name [] = {"Ahmad","Siew May","Ravi","John","Mohammad","Jennifer"};
    float salary [] = {12000.0, 4800.0,6000.0, 5500.0, 14000.0, 11000.0};
    int service [] = {10,4,12,7,6,5};
    queue <record> staff;     
    record rec; //object untuk data type record

    insert(&staff, name, salary, service);
    cout<<"\n # Menu : Current Record # "<<endl;
    display(staff);
    cout<<"\n # Menu : Update Record # "<<endl;
    update(&staff);
    cout<<"\n # Menu : Updated Record # "<<endl;
    display(staff);     
    cout<<"\nEnd of program";
    return 0;
}
