/*Subject code : CSEB3213 Data Structure & Algorithms 
  Section      : 02A 
  Student name : Izzat Fikri
  Student ID no: SW01082295
  Question no  : 1(a) */

#include <iostream>
using namespace std;

class scorun {
    public:
    string name;
    int point;
    scorun *next;
};


scorun *createScorun() {
    scorun *n = new scorun();
    return n; //pass address of the empty node
}

void insertNode(scorun **headRef) {	  
    scorun *n;
    char choice;
    do{
        n = createScorun ();

        cout << "Enter name: "; cin >> n->name;
        cout << "Enter scorun point: "; cin >> n->point;
        if(*headRef == NULL){
            *headRef = n;
        }
        else {
            
            scorun *helper = *headRef;
            while(helper->next != NULL){
                helper = helper->next;
            }
             helper->next = n;   	
        }
        cout<<"Press [y] for new record:";
        cin>>choice;
    }while(choice=='y');
}

void display(scorun *head) {
    cout<<"All records  : \n";
    while(head != NULL){
        cout << "Name: " << head->name << endl;
        cout << "Scorun points: " << head->point << endl;
        head = head->next;
    }
}

void analysis(scorun *head){
    int lowPointCount = 0;
    cout << "\nAnalysis of Scorun Points:\n";
    cout << "-----------------------------------------\n";
    while(head != NULL){
        if(head->point < 300){
            lowPointCount++;
            cout << "Name: " << head->name << endl;
            cout << "Scorun points: " << head->point << endl;
            cout << "-----------------------------------------\n";
        }
        head = head->next;
    }
    cout << "Total number of students with low scorun points (less than 300): " << lowPointCount << endl;
}

int main() {
    scorun *head = NULL;
    insertNode(&head);
    cout <<"\n**List of existing record**"<<endl;
    display(head);
    analysis(head);
    return 0;
}
