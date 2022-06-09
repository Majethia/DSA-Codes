#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack
{
public:
    char l[200], top;
    int len;

    Stack()
    {
        len = 0;
    }

    void push(char c)
    {
        l[len] = c;
        len += 1;
        top = c;
    }

    void pop()
    {
        len -= 2;
        top = l[len];
        len += 1;
    }
};

int priority(char c)
{
    if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infix_postfix(string s)
{
    Stack st;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c >= 'a' && c <= 'z')
            cout<<c;

        else if (c == '(')
            st.push(c);

        else if (c == ')')
        {
            while (st.top != '(')
            {
                cout<<st.top;
                st.pop();
            }
            st.pop();
        }

        else
        {
            while ((st.len > -1) && (priority(c) <= priority(st.top)))
            {
                cout<<st.top;
                st.pop();
            }
            st.push(c);
        }
    }

    while (st.len > -1)
    {
        cout<<st.top;
        st.pop();
    }
}

int main()
{
    cout<<"The Expression: ";
    string exp;
    cin>>exp;
    infix_postfix(exp);
    return 0;
}
