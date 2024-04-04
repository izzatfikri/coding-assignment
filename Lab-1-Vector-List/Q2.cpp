//Muhammad Izzat Fikri (SW01082295)
//Question 2 
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void display(vector<int> myVec){
      //display all data in the list using iterator
      vector<int>::iterator it;

      for (it = myVec.begin(); it != myVec.end(); it++) {
      cout << *it << " ";
    }
}

int main() {
	vector<int> vec {2,4,6,8};
	int no = 0;

    cout << "\nOriginal list:";
	display(vec);
	    
	cout<<"\n\nEnter three additional data:";
	for (int i=1;i<4;i++) { 
	    cin>>no;
        vec.insert(vec.begin(),no);
	    
	}
    cout << "List after adding three data:";
	display(vec);
   
    cout << "\n\nChange the 3rd data to 9";
    vector<int>::iterator it = vec.begin();
    advance(it,2);
    *it = 9;

    cout << "\nList after update the 3rd data:";
    display(vec);
    
    cout << "\n\nSort the data in acsending order";
    sort(vec.begin(),vec.end());

    cout << "\nList after the data are sorted:";
    display(vec);
    
    cout << "\n\nDelete data 4";
     it = vec.begin();
    for(; it != vec.end();){
        if(*it == 4)
            it = vec.erase(it);
        else
            ++it;

    }

    cout << "\nList after data 4 is deleted:";
    display(vec);
    
    cout << "\n\nDelete the first three data";
    vec.erase(vec.begin(), vec.begin() + 3);
    cout << "\nList after the first three data are deleted:";
    display(vec);
    cout << "\n\n";
   
    return 0;
}