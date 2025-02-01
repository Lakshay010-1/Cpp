#include<iostream>
using namespace std;

// Pointers are special variables that stores address of other variables.
// &-get the memory address of a variable
// *-stores the memory address as its value

int main(){
    int var=2;

    int* ptr=&var;
    int** ptr2=&ptr;                                                //Pointer-to-Pointer
    int ptrVal=*ptr;                                                //Dereference
    cout<<ptrVal<<endl;
    int* nullPtr=NULL;                                              //Null Pointer
    cout<<nullPtr<<endl;

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