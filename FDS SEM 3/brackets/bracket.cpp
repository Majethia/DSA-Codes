#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Stack{
    public:
        char l[2000], top;
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

string read_from_file(string filename){
    fstream file;
    char c;
    string res;

    file.open(filename, ios::in);
    while (!file.eof())
    {
        file.get(c);
        res.push_back(c);
    }
    file.close();

    return res;
}

bool check_file(string filename){
    Stack s;
    string code = read_from_file(filename);
    int n = code.length();
    
    for (int i = 0; i < n; i++)
    {
        if (code[i] == '{')
        s.push(code[i]);

        else if (code[i] == '(')
        s.push(code[i]);

        else if (code[i] == '[')
        s.push(code[i]);

        else if (code[i] == '}' && s.top == '{')
        s.pop();

        else if (code[i] == ']' && s.top == '[')
        s.pop();

        else if (code[i] == ')' && s.top == '(')
        s.pop();
    }
    cout<<s.len;

    if (s.len == 0)
    return true;

    else
    return false;
}

int main(){
    string name;

    cout<<"Check parenthesis balance in file.\nName of file you want to check for: ";
    cin>>name;
    if(check_file(name))
    cout<<"The file is balanced.";

    else
    cout<<"The file is not balanced.";


    return 0;
}
