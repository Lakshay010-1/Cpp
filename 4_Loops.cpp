#include<iostream>
using namespace std;

int main(){
    // while loop
    cout<<"While loop"<<endl;
    int i=0;
    while(i<5){
        cout<<i<<" ";
        i++;
    }

    // do-while loop
    cout<<"\n\n"<<"Do-while Loop"<<endl;
    i=5;
    do{
        cout<<i<<" ";
        i++;
    }while(i<5);

    // for loop
    cout<<"\n\n"<<"for Loop"<<endl;
    for(int idx=0;idx<5;idx++){
        cout<<idx<<" ";
    }

    // for-each loop
    cout<<"\n\n"<<"for-each Loop"<<endl;
    int arr[]={10,20,30,40,50};
    for(int val:arr){
        cout<<val<<" ";
    }

    // break
    cout<<"\n\n"<<"break"<<endl;
    for (int i = 0; i < 10; i++) {
        if (i == 4) {
            break;
        }
        cout << i << " ";
    }

    // continue
    cout<<"\n\n"<<"continue"<<endl;
    for (int i = 0; i < 10; i++) {
        if (i == 4) {
            continue;
        }
        cout << i << " ";
    }
    cout<<"\n";


    return 0;
}