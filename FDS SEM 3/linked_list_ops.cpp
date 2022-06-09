#include <iostream>

using namespace std;


struct Node{
    int data;
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

    void append(int num){
        nextnode = new Node;
        nextnode->link = NULL;
        temp->data = num;
        temp->link = nextnode;
        temp = nextnode;
        len+=1;
    }

    void insert(int num, int pos){
        if (pos > len){
            cout<<"Index Out Of Range.\n";
            return;
        }
        else if (pos == 0){
            nextnode = new Node;
            nextnode->link = Head;
            nextnode->data = num;
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

        nextnode->data = num;
        nextnode->link = next;
        previous->link = nextnode;
        len += 1;
    }

    void print(){
        Node* l;
        l = Head;
        for (int i = 0; i < len; i++){
            cout<<l->data<<" ";
            l = l->link;
        }
    }

    void del(int num){
        if (num == Head->data){
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
        while (num != next->data){
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
            if (l->data == num){
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
    friend linkedList union_list(linkedList &l1, linkedList &l2);
    friend linkedList intersection_list(linkedList &l1, linkedList &l2);
};

linkedList intersection_list(linkedList &l1, linkedList &l2){
    linkedList a;
    int d[length(l1)];
    Node* l_1, * l_2;
    l_1 = l1.Head;
    l_2 = l2.Head;

    for (int i = 0; i < length(l1); i++)
    {
        d[i] = l_1->data;
        l_1 = l_1->link;
    }

    for (int i = 0; i < length(l2); i++)
    {
        bool add = false;
        for (int j = 0; j < length(l1); j++)
        {
            if (d[j] == l_2->data)
            {
                add = true;
            }
        }
        if (add == true)
        {
            a.append(l_2->data);
        }
        l_2 = l_2->link;
    }
    return a;
}

linkedList union_list(linkedList &l1, linkedList &l2){
    linkedList a;
    Node* l_1, * l_2;
    int d[length(l1)];
    l_1 = l1.Head;
    l_2 = l2.Head;

    for (int i = 0; i < length(l1); i++)
    {
        d[i] = l_1->data;
        a.append(l_1->data);
        l_1 = l_1->link;
    }

    for (int i = 0; i < length(l2); i++)
    {
        bool add = true;
        for (int j = 0; j < length(l1); j++)
        {
            if (d[j] == l_2->data)
            {
                add = false;
            }
            
        }
        if (add == true)
        {
            a.append(l_2->data);
        }
        l_2 = l_2->link;
    }
    return a;
}


int length(linkedList &lst){
    return lst.len;
}

int main(){
    linkedList a, b, c, d;

    a.append(1);
    a.append(2);
    a.append(34);
    a.append(99);
    a.append(100);
    a.append(324);

    b.append(4);
    b.append(2);
    b.append(1);
    b.append(3);
    b.append(101);
    b.append(324);
    b.append(12);

    cout<<"First List: ";
    a.print();
    cout<<"\n";
    cout<<"Second List: ";
    b.print();
    cout<<"\n************\n";
    cout<<"Union: "; 
    c = union_list(a, b);
    c.print();
    cout<<"\n************\n";
    cout<<"Intersection: "; 
    d = intersection_list(a, b);
    d.print();

    return 0;
}

