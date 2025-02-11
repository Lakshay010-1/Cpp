#include<iostream>
using namespace std;

// Pointers are special variables that stores address of other variables.
// &-get the memory address of a variable
// *-stores the memory address as its value

class Person{
    public:
    void setName(string n){
        name=n;
    }
    string getName(){
        return name;
    }
    void setLevel(int l){
        level=l;
    }
    int getLevel(){
        return level;
    }
    private:
    string name;
    int level;
};

int main(){
    int var=2;

    int* ptr=&var;
    int** ptr2=&ptr;                                                //Pointer-to-Pointer
    int ptrVal=*ptr;                                                //Dereference
    cout<<ptrVal<<endl;
    int* nullPtr=NULL;                                              //Null Pointer
    cout<<nullPtr<<endl;

    //Arrow operator -  "->" is used to access the members of an object or struct when working with pointer to an object
    //Dot operator - "."-dot operator is used to access class, structure, or union members
    Person* p1=new Person();
    //Approach-1). Using Dot operator
    (*p1).setName("ABC");
    cout<<"Person Name is : "<<(*p1).getName()<<endl;
    //Approach-2). Using Arrow operator
    p1->setLevel(9);
    cout<<"Person Name is : "<<p1->getLevel()<<endl;

    // Array Pointer
    int arr[]={1,2,3,4,5,6};
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;

    // Pointer Arithmetic
    // (i). Increment/Decrement
    int* arrPtr=arr;
    arrPtr++;
    cout<<*arrPtr<<endl;
    arrPtr--;
    cout<<*arrPtr<<endl;

    // (ii).Add/Subtract Number
    cout<<*(arrPtr+2)<<endl;
    cout<<*(arrPtr-1)<<endl;

    // (iii).Subtract Pointer
    int* a=arrPtr;
    int* b=a+3;
    int subPtr=b-a;

    // (iv). Compare Pointer(<,<=,>,>=,==,!=)
    int isASmaller=a<b;
    cout<<isASmaller<<endl;


    return 0;
}