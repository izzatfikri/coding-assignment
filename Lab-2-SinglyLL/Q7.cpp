//Delete linked list-targeted node
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
	Node *rose = new Node();
	Node *lily = new Node();
	Node *puspa = new Node();
	Node *leaf = new Node();

    head->value = 5;
	head->next = secondNode;

	secondNode->value = 6;
	secondNode->next = thirdNode;

	thirdNode->value = 7;
	thirdNode->next = rose;

	rose->value = 444;
	rose->next = lily;

	lily->value = 666;
	lily->next = puspa;

	puspa->value = 888;
	puspa->next = leaf;

	leaf->value = 10000;
	leaf->next = NULL;

    //to delete 444
	Node *traverse = head;
	Node *x = new Node();

	while (traverse->next->value != 444)
	{
		traverse = traverse->next;
	}

	x = traverse->next;
	traverse->next = x->next;
	free(x);

	while (head != NULL) {
		cout << head->value << endl;
		head = head->next;
	}




    return 0;
}
