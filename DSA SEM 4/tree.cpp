#include <iostream>
#include <string>

using namespace std;

struct node
{
    string s;
    node *ptrs[5];
    int top;
};

int main(){
    string n;
    cout<<"Enter Name of Book: ";
    cin>>n;
    node *head = new node;
    head->s = n;
    int chap;
    cout<<"Enter number of chapters in "<<n<<": ";
    cin>>chap;
    head->top = chap;
    for (int i = 0; i < chap; i++){
        string chname;
        cout<<"name of chapter "<<i+1<<": ";
        cin>>chname;
        node *temp = new node;
        temp->s = chname;
        int subsec;
        cout<<"Number of subsections in "<<chname<<": ";
        cin>>subsec;
        temp->top = subsec;
        for (int j = 0; j < subsec; j++)
        {
            string secname;
            cout<<"name of section: "<<j+1<<": ";
            cin>>secname;
            node *temp1 = new node;
            temp1->s = secname;
            temp->ptrs[j] = temp1;
        }
    
        head->ptrs[i] = temp;
    }

    cout<<"\n\nName of Book: "<<head->s<<"\n";
    for (int i = 0; i < chap; i++)
    {
        cout<<"    Chapter Name: "<<head->ptrs[i]->s<<"\n";
        cout<<"        Section names:";
        for (int j = 0; j < head->ptrs[i]->top; j++)
        {
            cout<<" "<<head->ptrs[i]->ptrs[j]->s;
        }
        cout<<"\n";
    }
    
    return 0;
}
