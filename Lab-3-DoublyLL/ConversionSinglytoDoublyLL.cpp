// Introduction on Doubly Linked List concept and operations using C++ programming language.
// Referring to the above solution, convert the program to Doubly Linked List implementation. 
// Give your sample output too.

#include <iostream>
using namespace std;

class Record {
public:
	int year;
	Record *next;
	Record *prev; //1
};

Record *createNode() {
	Record *n = new Record();
	cout << "Enter year : ";
	cin >> n->year;
	n->next = NULL;
	n->prev = NULL; //2
	return n;
}

void insertNode(Record **head) {
	Record *n, *p; char choice;

	do {
		n = createNode();

		if (*head == NULL)
			*head = n;

		//insert second node onwards at the end of linked list 
		else {
			p = *head;
			while (p->next != NULL)
				p = p->next;
			p->next = n;
			n->prev = p; //3
		}

		cout << "Press [y] for new record:";
		cin >> choice;
	} while (choice == 'y');
}

void display(Record *p) {
	cout << "All records  : ";
	while (p != NULL) {
		cout << p->year << " ";
		p = p->next;
	}
}

void analysis(Record *p) {
	int lp = 0, nlp = 0;
	cout << "\n\n:: Analysis :: " << endl;
	while (p != NULL) {
		if (p->year % 4 == 0) {
			cout << p->year << " : leap year " << endl;
			lp++;
		}
		else {
			cout << p->year << " : non-leap year " << endl;
			nlp++;
		}
		p = p->next;
	}
	cout << "Total leap year : " << lp << endl;
	cout << "Total non-leap year : " << nlp << endl;
}

void deleteNode(Record **head) {
	int rec; Record *p = *head, *q;
	cout << "\n:: Delete Record :: " << endl;
	display(*head);
	cout << "\nEnter record to delete : ";
	cin >> rec;
	if ((*head)->year == rec) {
		*head = (*head)->next;
		(*head)->prev = NULL; //4
		free(p);
	}
	else {
		while (p->next->year != rec && p != NULL)
			p = p->next;
		q = p->next;
		p->next = q->next;
		q->next->prev = p;
		free(q);
	}
	display(*head);
}

int main() {
	Record *head = NULL;
	insertNode(&head);
	display(head);
	analysis(head);
	deleteNode(&head);
	return 0;
}