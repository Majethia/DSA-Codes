#include <iostream>

using namespace std;

struct node {
    int data;
    node *L, *R;
    bool right_thread;
};

node* find_inorder_successor(node* n, node* head){
    if (!head){return NULL;}
    node *successor = NULL;
    node *current  = head;
    while (current->data != n->data){
        if(current->data > n->data){
            successor = current;
            current = current->L;
        }
        else {current = current->R;};
    }
    if(current->R){
        node *c = current->R;
        while(c->L) {c = c->L;}
        successor = c;
    }

    return successor;
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
                head->right_thread = false;
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
                        currentnode->right_thread = false;
                        node* thread = find_inorder_successor(currentnode->L, head);
                        if (thread != NULL){
                            currentnode->L->R = thread;
                            currentnode->L->right_thread = true;
                        }
                        found = true;
                    }
                    else{currentnode = currentnode->L;}
                }
                else{
                    if(currentnode->right_thread == true || currentnode->R == NULL){
                        nextnode = new node;
                        nextnode->data = data;
                        nextnode->L = NULL;
                        nextnode->R = NULL;
                        currentnode->R = nextnode;
                        currentnode->right_thread = false;
                        node* thread = find_inorder_successor(currentnode->R, head);
                        if (thread != NULL){
                            currentnode->R->R = thread;
                            currentnode->R->right_thread = true;
                        }
                        found = true;
                    }
                    else{currentnode = currentnode->R;}
                }
            }
        }
};

void inorder_print(node *btree){
    node* current = btree;
    while(current->L != NULL){current = current->L;}
    while (current != NULL){
        cout<<current->data<<" ";
        if (current->right_thread = true){
            current = current->R;
        }
        else{
            while(current->L != NULL){current = current->L;}
        }
    }
}


int main(){
    BinarySearchTree b;
    b.append(9);
    b.append(8);
    b.append(10);
    b.append(11);
    b.append(7);
    b.append(13);
    b.append(1);
    b.append(12);

    cout<<"Inorder: ";
    inorder_print(b.head);
    // cout<<"\nPreorder: ";
    // preorder_print(b.head);
    // cout<<"\nPostorder: ";
    // postorder_print(b.head);

    return 0;
}