#include <iostream>
using namespace std;

class scorun {
    public:
    string name;
    int point;
    scorun *next;
};


scorun *createScorun() {
    scorun *n = new scorun;
    return n;
}

void insertNode(scorun *&h) {	  
    //variable declaration
    scorun *n; char choice;
    do{
        n = createScorun (); // hold address
        cout << "Enter name: ";
        cin >> n->name;
        cout << "Enter point: ";
        cin >> n->point;
        //insert first node into linked list
        if(h == NULL){
        h = n;   
         
        }
        
        //insert second node onwards at the end of linked list
        else {
            scorun *current = h;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = n;

        }

        cout<<"Press [y] for new record:";
        cin>>choice;
    }while(choice=='y');
}

void display(scorun *h) {
    cout<<"All records  : \n";
    while(h != NULL){
        cout << "Name: " << h->name << endl;
        cout << "Point: " << h->point << endl;
        h = h->next;
    }
}

int main() {
    scorun *head = NULL;
    insertNode(head);
    cout <<"\n**List of existing record**\n"<<endl;
    display(head);
    //call analysis()
    return 0;
}
