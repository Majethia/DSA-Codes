#include <iostream>
#include <string>

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

    void print_in_detail(){
        Node* l;
        l = Head;
        for (int i = 0; i < len; i++){
            cout<<"Name: "<<l->name<<", "<<"Phone No: "<<l->prn_num<<" --> ";
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

    friend int length(linkedList &lst);
};


int length(linkedList &lst){
    return lst.len;
}


class hash_table{
    public:
		int n;
		linkedList table[100];
        hash_table(int size){
        	n = size;
        }
        
        int hash_func_modulo(int x) {
        	return (x % n);
    	}

		int hash_func_digit_extraction(int x){
			return (x % 100);
		}
    	
    	void add(int x, string nam){
    		int hash_value = hash_func_modulo(x);
    		table[hash_value].append(x, nam);
		}

		int search(int x){
			int hash_value = hash_func_modulo(x);
			return table[hash_value].find(x);
		}
};


int main(){
    int n;
    cout<<"Length of array: ";
    cin>>n;
    hash_table ht(n);
    for(int i = 0; i < n; i++)
    {
    	int input;
    	cout<<"Phone No. "<<i+1<<": ";
    	cin>>input;
		string name;
		cout<<"Name: ";
		cin>>name;
    	ht.add(input, name);
	}
	cout<<"\n\nThe table:\n";
	for(int i = 0; i < n; i++)
	{
		cout<<"table no. "<<i<<"\n";
		ht.table[i].print_in_detail();
		cout<<"\n-------------\n";
	}

	int no;
	cout<<"Enter number to search: ";
	cin>>no;
	int res = ht.search(no);
	cout<<no<<" is located in hashtable at position: "<<ht.hash_func_modulo(no)<<","<<res;
	
	return 0;
}


