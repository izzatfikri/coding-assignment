/*Subject code : CSEB3213 Data Structure & Algorithms 
  Section      : 02A 
  Student name : Muhammad Izzat Fikri Bin Zurilan & Danial Hisham
  Student ID no: ( SW01082295 ) , ( SW0103116 )
  Question no  : 1(a)*/

#include <iostream>
using namespace std;

class scorun {
    public:
    string name;
    int point;
    scorun *next;
};


scorun *createScorun(string n, int p) {
    scorun *newScorun = new scorun(); 
    newScorun->name = n;
    newScorun->point = p;
    newScorun->next = NULL;
    return newScorun;
}

void insertNode(scorun **headRef) {	  
    
    scorun *n;
    char choice;
    do{
        
        string name;
        int points;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter scorun point: ";
        cin >> points;
        n = createScorun(name, points);

        
        if (*headRef == NULL) {
            *headRef = n;
        }
        
       else {
            scorun* helper = *headRef;
            while (helper->next != NULL) {
                helper = helper->next;
            }
            helper->next = n;
        }
        cout << "Press [y] for new record:";
        cin >> choice;
    } while (choice == 'y');
}


void display(scorun *head) {
     cout << "All records  : \n";
    while (head != NULL) {
        cout << "Name: " << head->name << endl;
        cout << "Scorun points: " << head->point << endl;
        head = head->next;
    }
}



int main() {
    scorun* head = NULL; 
    insertNode(&head);
    cout <<"\n**List of existing record**"<<endl;
    display(head);
    return 0;
}