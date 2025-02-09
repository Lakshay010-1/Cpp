#include<iostream>
using namespace std;

int main(){
    // Single-dimensional array
    int n;
    cout<<"Enter n : ";
    cin>>n;
    //int arr[n];                      // bad practice    
    int* nums=new int[n];              // good practice - dynamically memory allocated from heap 
    delete [] nums;                   // after execution make sure to delete/erase dynamically allocated memory

    //Multi-dimensional array
    //Creation 
    int row;
    cout<<"Enter total row count : ";
    cin>>row;
    int** arr=new int*[row];
    int colSize[row];

    // Input value (for jagged array)
    for(int i=0;i<row;i++){
        cout<<"Enter total column count for row "<<i<<" : ";
        cin>>colSize[i];
        arr[i]=new int[colSize[i]];
        cout<<"Enter values of row "<<i<<endl;
        for(int j=0;j<colSize[i];j++){
            cin>>arr[i][j];
        }
    }
    //Output Value
    for(int i=0;i<row;i++){
        for(int j=0;j<colSize[i];j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
        // delete [] arr[i];
    }
    //erasing allocated memory
    for(int i=0;i<row;i++){
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}