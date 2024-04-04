//Create a linked list - one node
#include<iostream>
using namespace std;

class Node{
public:
    int value;
    Node *next; //Store memory address of the next node.


};


int main(){

    Node *head = new Node();
    head->value = 5;
    head->next = NULL;

    cout << head->value << endl;

    return 0;
}