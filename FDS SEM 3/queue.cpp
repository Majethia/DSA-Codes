#include <iostream>

using namespace std;


class queue
{
    public:
        int l[200], start, end;

    queue()
    {
        start = 0;
        end = 0;
    }

    void push(int num)
    {
        l[end] = num;
        end += 1;
    }

    void pop()
    {
        start += 1;
    }

    int top()
    {
        return l[start];
    }
};

int main()
{
    queue q;
    q.push(5);
    cout<<q.top()<<"\n";
    q.push(2);
    cout<<q.top()<<"\n";
    q.push(3);
    cout<<q.top()<<"\n";
    q.push(1);
    cout<<q.top()<<"\n";
    q.pop();
    cout<<q.top()<<"\n";
    q.pop();
    cout<<q.top()<<"\n";
    q.pop();
    cout<<q.top()<<"\n";
}
