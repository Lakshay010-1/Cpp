#include<iostream>
#include<string>
using namespace std;

//User-Defined Data Type
class Person{     
    //Class members are the components that make up a class. They define the properties (data) and behaviors (functions) of an object.
    //Access specifiers define how the members (attributes and methods) of a class can be accessed.
    //public - members are accessible from outside the class.
    //private(default) - members cannot be accessed from outside the class.
    //protected - members cannot be accessed from outside the class, however, they can be accessed in inherited classes.
    
    private: 
    int health;                                             
    int level;
    public:
    //variables declared as static are initialized only once as they are allocated space in separate static storage so, 
    //the static member variables in a class are shared by the objects.
    static string onPlanet;
    string name;                                            
    // The constructor has the same name as the class, //it is always public, and it does not have any return value
    Person(){
        cout<<"Default Constructor called\n";
    }
    Person(int i){
        cout<<"Parameterised Constructor called\n"; 
        level=i;
    }
    //Default Copy Constructor performs a shallow copy
    //(Shallow Copy means that only the pointers will be copied not the actual resources that the pointers are pointing to)
    //User-defined Copy Constructor performs a deep copy
    //(Deep copy means that the pointers (or references) of copied objects point to new copy of the dynamic resource allocated manually in the copy constructor using new operators)
    Person(Person& p){
        cout<<"Copy Constructor called\n";
        level=p.getLevel();
        health=p.health;
    }

    // Destructor is an instance member function that is invoked automatically whenever an object is going to be destroyed
    //for static allocated objects destructor is called automatically, but for dynamically allocated objects we have to call destructor manually
    ~Person(){
        cout<<"Destructor called";
    }

    //Class methods - (i). Inside class definition
    int getLevel(){
        return level;
    }
    int getHealth(){
        return health;
    }
    void setHealth(int h){
        health=h;
    }
    //(ii).Outside Class Method declaration
    void setLevel(int);
};
    //Class methods - (ii). Outside class definition
    void Person::setLevel(int l){                           //"::"-scope resolution operator
        level=l;
    }
    //Static member inintialization
    string Person::onPlanet="Earth";

int main(){
    //static member 
    cout<<"Persons on planet(static member) : "<<Person::onPlanet<<endl;
    //static allocation
    Person p1;                                                   //object/instance
    p1.name="abc";                                               
    p1.setLevel(9);
    cout<<"Name is : "<<p1.name<<"\nLevel is : "<<p1.getLevel()<<endl;

    //dynamic allocation
    Person* p2=new Person();
    Person* p3=new Person(1);
    Person* p4=new Person(p1);
    //Copy Assginment Operator
    p4=p3;
    
    //Approach-1). Using Dot operator
    (*p2).setHealth(5);
    cout<<"Health is : "<<(*p2).getHealth()<<endl;
    //Approach-2). Using Arrow operator
    p2->setLevel(9);
    cout<<"Level is : "<<p2->getLevel()<<endl;


    return 0;
}