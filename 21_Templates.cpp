#include<iostream>
using namespace std;

//Generics in C++ are implemented using templates, which allow writing flexible and reusable code.
//Templates enable functions and classes to operate with generic types without specifying a particular data type in advance.
    //i.e. template<typename T> or template<class T> where 
        //       template --> Indicates that the following declaration is a template.
        // typename/class --> Specifies that 'T' is a placeholder for a type.
        //              T --> Represents a generic data type means the template type parameter.

// Function Templates
template <typename T=int>               // default value for template argument
T addition(T num1,T num2){
    return num1+num2;
}

// Multiple Type Parameter Template 
template <typename A,typename B>
A subtract(A n1,B n2){
    return abs(n1-n2);
}

// Class Templates
template <typename K>                
class Calculator{
    public:
    ~Calculator(){
        cout<<"Memory Freed"<<endl;
    }
    K division(K n1,K n2){
        return n1/n2;
    }
    K multiply(K n1,K n2){
        return n1*n2;
    }
};

//Specialization Templates - Specialization for 'bool'
template<> 
class Calculator<bool>{
    public:
    ~Calculator(){
        cout<<"Memory Freed"<<endl;
    }
    bool andB(bool a,bool b){
        return a&&b;
    }
    bool orB(bool a,bool b){
        return a||b;
    }
};

int main(){
    // Function Templates
    float sum=addition<float>(1.5,9.9);
    cout<<"sum is : "<<sum<<endl;

    // Multiple Type Parameter Template 
    float diff=subtract<float,int>(9.9,5);
    cout<<"difference is : "<<diff<<endl;

    // Class Templates
    Calculator<int> *calculator=new Calculator<int>();
    int div=calculator->division(9,2);
    int product=calculator->multiply(11,8);
    cout<<"division is : "<<div<<endl;
    cout<<"product is : "<<product<<endl;
    
    // Specialization Templates
    Calculator<bool> *calculatorBool=new Calculator<bool>();
    int andBool=calculatorBool->andB(true,false);
    int orBool=calculatorBool->orB(true,false);
    cout<<"and is : "<<andBool<<endl;
    cout<<"or is : "<<orBool<<endl;

    //Freeing Memory
    delete calculator;
    delete calculatorBool;
    
    return 0;
}