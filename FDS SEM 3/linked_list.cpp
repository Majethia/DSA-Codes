#include <iostream>
#include<cstring>

using namespace std;


struct Node{
    string name;
    int prn_num;
    Node* link;
};


class linkedList{
    private:
        Node* nextnode;
        int len;

    public:
        Node* Head;
        Node *temp;

    linkedList(){
        nextnode = new Node;
        nextnode->link = NULL;
        temp = nextnode;
        Head = nextnode;
        len = 0;
    }

    void append(int num, string Name){
        nextnode = new Node;
        nextnode->link = NULL;
        temp->prn_num = num;
        temp->name = Name;
        temp->link = nextnode;
        temp = nextnode;
        len+=1;
    }

    void insert(int num, string Name, int pos){
        if (pos > len){
            cout<<"Index Out Of Range.\n";
            return;
        }
        else if (pos == 0){
            nextnode = new Node;
            nextnode->link = Head;
            nextnode->prn_num = num;
            nextnode->name = Name;
            Head = nextnode;
            len += 1;
            return;
        }

        Node* next;
        Node* previous;
        nextnode = new Node;
        next = Head->link;
        previous = Head;

        for (int i = 0; i < pos-1; i++){
            previous = next;
            next = next->link;
        }

        nextnode->prn_num = num;
        nextnode->name = Name;
        nextnode->link = next;
        previous->link = nextnode;
        len += 1;
    }

    void print_in_detail(){
        Node* l;
        l = Head;
        for (int i = 0; i < len; i++){
            cout<<"Name: "<<l->name<<"\n"<<"PRN NO: "<<l->prn_num<<"\n";
            l = l->link;
        }
    }

    void print(){
        Node* l;
        l = Head;
        for (int i = 0; i < len; i++){
            cout<<l->prn_num<<" ";
            l = l->link;
        }
    }

    void del(int num){
        if (num == Head->prn_num){
            Head = Head->link;
            len -= 1;
            return;
        }

        Node* next;
        Node* current;
        Node* previous;
        next = Head->link;
        previous = Head;
        int count;
        while (num != next->prn_num){
            count += 1;
            previous = next;
            next = next->link;
            if (count >= len){
                return;
            }
        }

        previous->link = next->link;
        len -= 1;
    }

    int find(int num){
        Node* l;
        l = Head;
        for (int i = 0; i < len; i++){
            if (l->prn_num == num){
                return i;
            }
            l = l->link;
        }
        return -1;
    }

    void reverse(){
        Node *current = Head;
        Node *prev = NULL, *next = NULL;
 
        while (current->link != NULL) {
            next = current->link;
            current->link = prev;
 
            prev = current;
            current = next;
        }
        Head = prev;
    }

    friend int length(linkedList &lst);
};

int length(linkedList &lst){
    return lst.len;
}

int main(){
    linkedList a;

    string n1, n2, n3;
    n1 = "asfafa";
    n2 = "wasasdasd";
    n3 = "asdasd";
    a.append(1, n1);
    a.append(2, n1);
    a.append(34, n1);
    a.append(99, n2);
    a.append(100, n2);
    a.append(324, n2);

    cout<<"Initial List\n";
    a.print();
    cout<<"\n\n";

    a.insert(19, n3, 3);
    a.insert(20, n3, 5);

    cout<<"Insert Elements in List\n";
    a.print();
    cout<<"\n\n";

    a.del(2);

    cout<<"Delete Elements in List\n";
    a.print();
    cout<<"\n\n";

    cout<<"Find Elements in List\nElement 34 found at pos "<<a.find(34);
    cout<<"\n\n";

    a.reverse();
    cout<<"Reversed List\n";
    a.print();
    cout<<"\n\n";

    return 0;
}

