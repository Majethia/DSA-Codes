#include <iostream>

using namespace std;

class Student{
    public:
        char name[20], branch[10]; 
        int rollno;

    Student(char n, char b, int r){
        name = n;
        branch = b;
        rollno = r;
    }

};

class club{
    public:
        Student president, secretary, members[100]

    club(Student p, Student s, Student m){
        president = p;
        secretary = s;
        members = m;
    }
};

int main{
    return 0;
}

