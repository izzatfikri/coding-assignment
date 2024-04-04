//Muhammad Izzat Fikri (SW01082295)
//Question 1
#include<iostream>
#include<list>

using namespace std;

void display(list<int> myList){
      //display all data in the list using iterator
      list<int>::iterator it;

      for (it = myList.begin(); it != myList.end(); it++) {
      cout << *it << " ";
    }
}

int main() {
	list<int> rec {4,4,6,8};
	int no = 0;

    cout << "\nOriginal list:";
	display(rec);
	    
	cout<<"\n\nEnter three additional data:";
	for (int i=1;i<4;i++) {
	    cin>>no;
        rec.push_front(no);
	    
	}
    cout << "List after adding three data:";
	display(rec);
   
    cout << "\n\nChange the 3rd data to 9";
    list<int>::iterator it = rec.begin();
    advance(it,2);
    *it = 9;

    cout << "\nList after update the 3rd data:";
    display(rec);
    
    cout << "\n\nSort the data in acsending order";
    rec.sort();

    cout << "\nList after the data are sorted:";
    display(rec);
    
    cout << "\n\nDelete data 4";
    rec.remove(4);

    cout << "\nList after data 4 is deleted:";
    display(rec);
    
    cout << "\n\nDelete the first three data";
    for (int i = 0; i < 3; i++) {
        rec.pop_front();
    }
    cout << "\nList after the first three data are deleted:";
    display(rec);
    cout << "\n\n";
   
    return 0;
}