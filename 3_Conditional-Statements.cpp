#include<iostream>
using namespace std;

int main(){
    int age;
    cout<<"Enter your age: "<<endl;
    cin>>age;

    // if statement
    if (age>18) {
        cout << "Adult" <<endl;
    }

    // if-else statement
    if (age>18) {
        cout << "Adult" <<endl;
    }else{
        cout<<"Child"<<endl;
    }

    // if-elseif-else
    if (age>18) {
        cout << "Adult" <<endl;
    }else if(age>12){
        cout<<"Teenager"<<endl;
    }else{
        cout<<"Child"<<endl;
    }

    // Ternary Operator
    string statusAge=(age>18)?"Adult":"Child";

    // Switch statements
    switch (age){
    case 18:
        cout<<"18 Year Old"<<endl;
        break;
    case 100:
        cout<<"100 Year Old"<<endl;
        break;
    default:
        cout<<"Not 18 or 100 Year Old"<<endl;
    }

    return 0;
}