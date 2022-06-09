#include <iostream>
#include <vector>

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

    void print(){
        Node* l;
        l = Head;
        for (int i = 0; i < len; i++){
            cout<<l->data<<"->";
            l = l->link;
        }
    }

    friend int length(linkedList &lst);
};

int length(linkedList &lst){
    return lst.len;
}

class edge{
    public:
        int v1;
        int v2;
    edge(int vv1, int vv2){
        v1 = vv1;
        v2 = vv2;
    }
};

class graph{
    public:
        vector<int> vertices;
        vector<edge> edges;
        int s;

        graph(vector<int> v, vector<edge> e){
            vertices = v;
            edges = e;
            s = vertices.size(); 
        }


        void convert_to_adjency_matrix(){
            vector<vector<int>> matrix;
            for (int i = 0; i < s; i++){
                vector<int> temp;
                matrix.push_back(temp);
                for (int j = 0; j < s; j++){
                    matrix[i].push_back(0);
                }
            }
            for (int i = 0; i < edges.size(); i++){
                matrix[edges[i].v1][edges[i].v2] = 1;
            }
            for (int i = 0; i < vertices.size(); i++){
                for (int j = 0; j < vertices.size(); j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<"\n";
            }
        }

        void convert_to_adjency_list(){
            vector<linkedList> l;
            for (int i = 0; i < s; i++){
                linkedList temp;
                temp.append(vertices[i]);
                l.push_back(temp);
            }
            for (int i = 0; i < s; i++){
                for (int j = 0; j < edges.size(); j++){
                    if (edges[j].v1 == l[i].Head->data){
                        l[i].append(edges[j].v2);
                    }    
                }
            }
            for (int i = 0; i < s; i++){
                l[i].print();
                cout<<"\n";
            }
        }
};

int main(){
    vector<int> ver = {0, 1, 2, 3};
    vector<edge> ed = {edge(0, 1), edge(0,2), edge(0, 3), edge(1, 2), edge(2, 3), edge(3, 0)};
    graph g(ver, ed);

    g.convert_to_adjency_matrix();
    cout<<"\n\n";
    g.convert_to_adjency_list();

    return 0;
}

