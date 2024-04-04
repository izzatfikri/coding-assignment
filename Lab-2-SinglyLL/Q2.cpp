//Create a linked list - many nodes
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

    while(head != NULL){

        cout << head->value << endl;
        head = head->next;

    }



    return 0;
}