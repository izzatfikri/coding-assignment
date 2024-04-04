//Insert a linked list(end)

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

    //new node to insert belakang
    Node *palingLast = new Node();
    palingLast->value = 999;
    palingLast->next = NULL;

    //need one node as helper to jalan from beginning until end
    Node *h = head;
    while (h->next != NULL) {
		h = h->next;
	}
	h->next = palingLast;

	while (head != NULL)
	{
		cout << head->value << endl;
		head = head->next;
	}
	
	cout << endl;
	return 0;
}



 