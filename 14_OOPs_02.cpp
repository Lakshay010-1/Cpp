#include<iostream>
#include<vector>
using namespace std;

//Pillars of OOPs

//Encapsulation - Encapsulation is the process or method to contain the information and to make sure that "sensitive" data is hidden from users and increase security of data.
class Account{    
    private:
    int id;
    string password;

    public: 
    void setId(int i){
        this->id=i;
    }
    int getId(){
        return this->id;
    }
    void setPassword(string p){
        this->password=p;
    }
    string getPassword(){
        return this->password;
    }
};

//Inheritance - Inheritance is useful for code reusability (reuse attributes and methods) of an existing class when you create a new class
/*
class  derived_class_name : access-specifier  base_class_name
{
       //    body ....
};

*/
// Modes of Inheritance:
// (i).public - derived subclass from a public base class. Then the public member of the base class will become public in the derived class and
//                                                                  protected members of the base class will become protected in the derived class and
//                                                                  private members of the base class will be inaccessible in derived class.
// (ii).protected - derived subclass from a Protected base class. Then both public members and protected members of the base class 
//                                                                          will become protected in the derived class and
//                                                                          private members of the base class will be inaccessible in derived class.
// (iii).private - derived subclass from a Private base class. Then both public members and protected members of the base class
//                                                                        will become private in the derived class and
//                                                                        private members of the base class will be inaccessible in derived class.

//Types of Inheritance
class Animal{
    private:
    int age;
    string breed;

    protected:
    void setBreed(string b){
        this->breed=b;
    }

    public:
    void setAge(int a){
        this->age=a;
    }
    int getAge(){
        return this->age;
    }
    string getBreed(){
        return this->breed;
    }
    void breathe(){
        cout<<"Breathing..."<<endl;
    }
    virtual void eats(){
        cout<<"Eats..."<<endl;
    };
    void sleep(){
        cout<<"Sleeping..."<<endl;
    }
};
// (i). Single-Level Inheritance
class Zebra:public Animal{
    public:
    Zebra(){
        this->setBreed("Zebra");
    }
    void eats(){
        cout<<"Eats grass"<<endl;
    }    
};
// (ii). Hierarchical Inheritance
class Lion:public Animal{
    public:
    Lion(){
        this->setBreed("Lion");
    }
    void eats(){
        cout<<"Eats Animals"<<endl;
    }
};
// (iii). Multiple Inheritance
class ZebraLion:public Zebra,public Lion{           //Note the order
    public:
    ZebraLion(){
        this->Zebra::setBreed("ZebraLion");         //Resolve ambiguity by specifying the class with scope resolution operator
    }
};
// (iv). Multi-Level Inheritance
class MountainLion:public Lion{
    public:
    MountainLion(){
        this->setBreed("MountainLion");
    }
};
// (v). Hybrid Inheritance
class ZebraMountainLion:public ZebraLion,public MountainLion{
    ZebraMountainLion(){
        this->Zebra::setBreed("ZebraMountainLion");
    }
};

//Polymorphism - Polymorphism means having many forms.
//               In simple words, polymorphism is the ability of a message to be displayed in more than one form.

//Types of Polymorphism:
// (i). Compile-time Polymorphism - achieved by function overloading or operator overloading 
//                                  {also known as "early binding" and "static polymorphism"}
class Num{
    public:
    int value;
    Num(){
        value=0;
    }
    // Function Overloading
    int increment(){
        this->value=this->value+1;
        return this->value;
    }
    int increment(int num){
        this->value=this->value+num;
        return this->value;
    }
    virtual int increment(char c){
        this->value=c+this->value;
        return this->value;
    };
    // Operator Overloading [Operators that cannot be overloaded are {(::),(.),(?:),(sizeof),(typeid),(.*),(new),(delete)}]
    int operator+ (Num& b){
        this->value=this->value+b.value;
        return this->value;
    }
};
// (ii). Runtime Polymorphism - achieved by Function Overriding 
//                              {also known as "late binding" and "dynamic polymorphism"}
class Num2:public Num{
    public:
    Num2(){
        value=2;
    }
    // Function Overriding
    int increment(){
        this->value=this->value+2;
        return this->value;
    }
    int increment(int num){
        this->value=this->value+num+2;
        return this->value;
    }
    //Virtual Function Overriding
    int increment(char c){
        this->value=this->value+c+2;
        return this->value;
    }
};


//Abstraction - Data abstraction refers to providing only essential information about the data to the outside world,
//              ignoring unnecessary details or implementation
class Organisation{
    private:
    vector<string> investors;
    public:
    int profit;
    Organisation(){
        profit=10000;
    }
    int getProfits(){
        return this->profit;
    }
};

int main(){
    // Encapsulation
    Account emp1;
    emp1.setId(1);
    emp1.setPassword("password");
    cout<<"ID - "<<emp1.getId()<<endl;
    

    // Polymorphism
    // (i). Compile Polymorphism
    Num n1,n2;
    n1.value=10;
    n2.value=100;
    cout<<"n1 value - "<<n1.value<<endl;
    n1.increment(5);
    cout<<"n1 value - "<<n1.value<<endl;
    n1+n2;
    cout<<"n1 value - "<<n1.value<<endl;

    // (ii). RunTime Polymorphism
    Num2 b;
    Num* a=&b;
    cout<<"(Virtual Function Overrided) a value is - "<<a->increment('a')<<endl;

    // Abstraction
    Organisation og;
    cout<<"Profits are "<<og.getProfits()<<" Ruppees"<<endl;
    return 0;
}