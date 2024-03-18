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
    //variable declaration
    scorun *n;
    char choice;
    do{
        n = createScorun ();

        //insert first node into linked list
        cout << "Enter name: "; cin >> n->name;
        cout << "Enter scorun point: "; cin >> n->point;
        //missing code
        if(*headRef == NULL){
            *headRef = n;
        }
        //insert second node onwards at the end of linked list
        else {
            //missing code
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

int main() {
    scorun *head = NULL;
    insertNode(&head);
    cout <<"\n**List of existing record**\n"<<endl;
    display(head);
    //call analysis()
    return 0;
}
