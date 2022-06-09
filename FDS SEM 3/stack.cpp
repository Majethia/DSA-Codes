#include <iostream>

using namespace std;



class Stack{
    public:
        char l[50], top;
        int len;

    Stack(){
        len = 0;
    }

    void push(char c){
        l[len] = c;
        len += 1;
        top = c;
    }

    void pop(){
        len -= 2;
        top = l[len];
        len += 1;
    }
};



int main(){
    Stack s;
    int n;
    cout<<"Length of string: ";
    cin>>n;
    char word[n];
    char res[n];
    cout<<"Enter the word: ";
    cin>>word;
    for (int i = 0; i < n; i++)
    {
        s.push(word[i]);
    }

    for (int i = 0; i < n; i++)
    {   
        res[i] = s.top;
        cout<<s.top;
        s.pop();
    }

    cout<<endl<<"Its ";

    for (int i = 0; i < n; i++)
    {   
        if (res[i] != word[i])
        {
            cout<<"not ";
            break;
        }
    }
    cout<<"a palindrome";

}

