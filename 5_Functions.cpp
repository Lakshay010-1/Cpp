#include<iostream>
#include<ctime>
using namespace std;

int globalVar=21;                                   //Global Scope

// greet() function is overloaded
void greet(){
    cout<<"Namaste"<<endl;
    int localVar=12;                                //Local Scope
}

void greet(int curHour){                            //Parameters
    if(curHour>4 && curHour<12){
        cout<<"Good Morning"<<endl;
    }else if(curHour>=12 && curHour<17){
        cout<<"Good Afternoon"<<endl;
    }else if(curHour>=17 && curHour<=19){
        cout<<"Good Evening"<<endl;
    }else{
        cout<<"Good Night"<<endl;
    }
}

void yourIQ(int iq=141){                            //Default Parameter
    cout<<"Your iq is : "<<iq<<endl;
}

void swapV(int a,int b){                            //Pass By Value - Copy of argument is passed to the function
    a+=b;
    b=a-b;
    a=a-b;
}

void swapR(int& a,int& b){                          //Pass By Reference - Refernce of argument is passed to the function
    a+=b;
    b=a-b;
    a=a-b;
}

// Recursion
int fibonacci(int n=5){
    if(n<=0){
        return 0;
    }else if(n==1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}

//Inline Function
inline int getMax(int& a,int& b){
    return (a>b)?a:b;
}

int main(){
    greet();
    time_t timestamp=time(&timestamp);
    struct tm datetime= *localtime(&timestamp);
    greet(datetime.tm_hour);                        //Arguments
    yourIQ();
    int a=1,b=9;
    cout<<a<<" "<<b<<endl;
    swapV(a,b);
    cout<<a<<" "<<b<<endl;
    swapR(a,b);
    cout<<a<<" "<<b<<endl;
    cout<<"fibo"<<fibonacci(6)<<endl;
    int n1=4,n2=9;
    cout<<getMax(n1,n2)<<endl;
    return 0;
}

