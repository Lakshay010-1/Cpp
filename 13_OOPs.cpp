#include<iostream>
#include<string>
using namespace std;

class Person{                                                   //User-Defined Data Type
    //Access modifiers
    //public - 
    // private(default) - 
    //protected - 

    public:
    string name;
    //Class methods - (i). Inside class definition
    int getLevel(){
        return level;
    }
    void setLevel(int level);
    private: 
    int health;
    int level;
};
    //Class methods - (ii). Outside class definition
    void Person::setLevel(int l){                               //"::"-scope resolution operator
        level=l;
    }

int main(){
    Person p1;                                                   //Class member/object/instance
    p1.name="abc";
    cout<<p1.name<<endl;                                         //"."-dot operator is used to access class, structure, or union members
    p1.setLevel(9);
    cout<<p1.getLevel()<<endl;
    return 0;
}