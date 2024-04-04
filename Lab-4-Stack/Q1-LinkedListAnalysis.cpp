#include<iostream>

using namespace std;
struct Data{
    int no;
    Data *next;
};

//Parameter(value dari main dgn top pointer)
void push(int val, Data **top){
    Data *n = new Data; //Node creation
    n->no = val;
    n->next = NULL;
    /*insertion process*/
    if(*top == NULL)
        *top = n;
    else{
        n->next = *top;
        *top = n;
    }
}

//Question 1(b)
void analysis(Data *top){
    int odd = 0, even = 0, i = 1;
    cout << "\n:: Analysis ::\n";
    while(top != NULL){
        if(top->no % 2 == 0){
            cout << "Value " << i << " : " << top->no << " (Even) \n";
            even++;
        }
        else{
            cout << "Value " << i << " : " << top->no << " (Odd) \n";
            odd++;
        }
        i++;
        top = top->next;
    }
    cout << "Total even value : " << even << endl;
    cout << "Total odd value : " << odd << endl;
}


//Question 1(c)
void pop(Data **top){
    cout << "\nRemoving all numbers...\n";
    
    while(*top != NULL){
        Data *temp = *top;
        *top = (*top)->next;
        free(temp);
    }
    cout << "[Result] All numbers have been deleted.\n";
}

int main(){
    Data *head = NULL; int size; int val;

    cout << "Enter total value to insert: ";
    cin >> size;
    for(int i = 1; i <= size; i++){
        cout << "Enter a value: ";
        cin >> val;
        //Question 1(a)
        push(val,&head);
    }
    //Question 1(a)
    analysis(head);
    pop(&head);

    cout << "\nEnd of program";
    return 0;
}

