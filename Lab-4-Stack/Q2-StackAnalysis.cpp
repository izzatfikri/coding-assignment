#include<iostream>
#include<stack>

using namespace std;

void analysis(stack<int> rec){
    cout << "\n:: Analysis ::\n";
    int odd = 0, even = 0, i = 1;
    while(!rec.empty()){
        if(rec.top() % 2 == 0){
            cout << "Value " << i << " : " << rec.top() << " (Even) \n";
            even++;
        }
        else{
            cout << "Value " << i << " : " << rec.top() << " (Odd) \n";
            odd++;
        }
        i++;
        rec.pop();
    }
     cout << "Total even value : " << even << endl;
     cout << "Total odd value : " << odd << endl;

}

void deletion(stack<int> *rec){
    cout << "\nRemoving all numbers...\n";
    while(!rec->empty()){
        rec->pop();
    }
    if(rec->empty())
    cout << "[Result] All numbers have been deleted.\n";
}
int main(){

    int size, val;
    stack<int> record;
    cout << "Enter total value to insert: ";
    cin >> size;
    
    for(int i = 1; i <= size; i++){
        cout << "Enter a value : ";
        cin >> val;
        record.push(val);
    }

    analysis(record);
    deletion(&record);

    cout << "\nEnd of program";

    return 0;
}