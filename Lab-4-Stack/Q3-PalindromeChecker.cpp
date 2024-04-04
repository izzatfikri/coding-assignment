#include<iostream>
#include<string>
#include<stack>
using namespace std;

//Function to check if a string is a palindrome
bool isPalindrome(const string &str){
    stack<char> s;

    //Push alphanumeric characters onto the stack
    for(auto it = str.begin(); it != str.end(); ++it){
        if(isalpha(*it)){
            s.push(tolower(*it));
        }
    }

    for(auto it = str.begin(); it != str.end(); ++it){
        if(isalpha(*it)){
            if(tolower(*it) != s.top())
                return false;
        }
        s.pop();
    }

    return true;
}

int main(){

    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if(isPalindrome(input)){
            cout << "\"" << input << "\" is a palindrome." << endl;
    }   else {
            cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}