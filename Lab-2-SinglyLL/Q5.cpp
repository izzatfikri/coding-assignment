//Insert a linked list(based on position)
#include<iostream>
using namespace std;

class Node{
public:
    int value;
    Node *next;

};

int main(){

    Node *head = new Node();
    Node *secondNode = new Node();
    Node *thirdNode = new Node();

    head->value = 5;
    head->next = secondNode;

    secondNode->value = 6;
    secondNode->next = thirdNode;

    thirdNode->value = 7;
    thirdNode->next = NULL;

    Node *n = new Node();
    n->value = 10;
    n->next = head;
    head = n;

    Node *palingLast = new Node();
    palingLast->value = 999;
    palingLast->next = NULL;

    //Helper pointer
    Node *h = head;
    while(h->next != NULL){
        h = h->next; //iterate to next node;
    }

    h->next = palingLast;

    Node *Node6 = new Node();
    Node6->value = 268;

    //need one node as helper to jalan from beginning until elemen kedua
    int i = 0;
    Node*k = head;

    for(i = 0; i<2; i++){
        k = k->next;
    }

    Node6->next = k->next;
    k->next = Node6;

    while(head!=NULL){
        cout << head->value << endl;
        head = head->next;
    }

    cout << endl;

    return 0;
}