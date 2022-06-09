#include <iostream>

using namespace std;

struct node {
    int data;
    node *L, *R;
};

bool searchbtree(node *current, int d){
    if (current == NULL){
        return false;
    }

    else if (d == current->data){
        return true;
    }

    else if (d > current->data){
        cout<<"R->";
        return searchbtree(current->R, d);
    }
    cout<<"L->";
    return searchbtree(current->L, d);
}

class BinarySearchTree{
    public:
        node *head;

        BinarySearchTree(){
            head = NULL;
        }

        void append(int data){
            if(head == NULL){
                head = new node;
                head->data = data;
                head->L = NULL;
                head->R = NULL;
                return;
            }

            bool found = false;

            node *currentnode = head;

            while (!found){
                node *nextnode;
                if(data < currentnode->data){
                    if(currentnode->L == NULL){
                        nextnode = new node;
                        nextnode->data = data;
                        nextnode->L = NULL;
                        nextnode->R = NULL;
                        currentnode->L = nextnode;
                        found = true;
                    }
                    else{currentnode = currentnode->L;}
                }
                else{
                    if(currentnode->R == NULL){
                        nextnode = new node;
                        nextnode->data = data;
                        nextnode->L = NULL;
                        nextnode->R = NULL;
                        currentnode->R = nextnode;
                        found = true;
                    }
                    else{currentnode = currentnode->R;}
                }
            }
        }
        
        bool search(int data){
            node *current = head;
            bool f;
            f = searchbtree(current, data);
            return f;
        }

        friend void del(BinarySearchTree b,int data);
        friend void preorder_print(node *btree);
        friend void postorder_print(node *btree);
        friend void inorder_print(node *btree);
        friend bool searchbtree(node *current, int d);
};

void preorder_print(node *btree){
    if (btree == NULL){return;}
    cout<<btree->data<<" ";
    preorder_print(btree->L);
    preorder_print(btree->R);
}

void postorder_print(node *btree){
    if (btree == NULL){return;}
    postorder_print(btree->L);
    postorder_print(btree->R);
    cout<<btree->data<<" ";
}

void inorder_print(node *btree){
    if (btree == NULL){return;}
    inorder_print(btree->L);
    cout<<btree->data<<" ";
    inorder_print(btree->R);
}

void inorder_append(node *btree, BinarySearchTree b){
    if (btree == NULL){return;}
    inorder_append(btree->L, b);
    b.append(btree->data);
    inorder_append(btree->R, b);
}

void del(BinarySearchTree b, int data){
    node *curr = b.head;
    node *prev = NULL;
    while (curr != NULL && curr->data != data){
        prev = curr;
        if(data < curr->data){curr = curr->L;}
        else{curr = curr->R;}
    }
    if (curr == NULL){return;}

    if(data < curr->data){prev->L = NULL;}
    else{prev->R = NULL;}
    inorder_append(curr->L, b);
    inorder_append(curr->R, b);
    }

int main(){
    BinarySearchTree b;
    b.append(10);
    b.append(11);
    b.append(8);
    b.append(7);
    b.append(9);
    b.append(199);
    b.append(100);
    b.append(150);
    b.append(22);

    cout<<"Inorder: ";
    inorder_print(b.head);
    cout<<"\nPreorder: ";
    preorder_print(b.head);
    cout<<"\nPostorder: ";
    postorder_print(b.head);

    int d;
    cout<<"\nSearch Num: ";
    cin>>d;
    bool s;
    s = b.search(d);
    if (s == false) cout<<"Not ";
    cout<<"Found\n";

    cout<<"\nDel Node: ";
    cin>>d;
    del(b, d);

    cout<<"\nAfter deletion:\nInorder: ";
    inorder_print(b.head);
    cout<<"\nPreorder: ";
    preorder_print(b.head);
    cout<<"\nPostorder: ";
    postorder_print(b.head);

    return 0;
}

