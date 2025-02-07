#include<iostream>
#include<vector>
#include<array>
#include<bits/stdc++.h>
using namespace std;

int main(){
    /* Array */
    // Single-Dimensional Arrays
    int id[]={1,2,4,5,6,7,8,68};
    for(int i=0;i<sizeof(id)/sizeof(id[0]);i++){
        cout<<id[i]<<" ";
    }
    cout<<endl;

    // Multi-Dimensional Arrays
    int alpha[][5]={{1,2,3,4,5},{6,7,8,9,10}};
    for(int i=0;i<sizeof(alpha)/sizeof(alpha[0]);i++){
        for(int j=0;j<sizeof(alpha[i])/sizeof(alpha[i][0]);j++){
            cout<<alpha[i][j]<<" ";
        }
        cout<<endl;
    }
    /*STL Array */
    array<int,5> stlArray={1,2,4,5,6};
    int stlArrSize=stlArray.size();
    int eleAt1=stlArray[1];
    int eleAt2=stlArray.at(2);
    bool isEmptyStl=stlArray.empty();
    int firstStl=stlArray.front();
    int lastStl=stlArray.back();

    /* Vectors (vector is like a resizable array.) */
    cout<<"Vectors"<<endl;
    //Intialization
    vector<int> vec2={11,22,33,44,55};                                 //Intialization of Vector with values
    vector<int> vec(5,-1);                                             //Intialization of Vector with intital size(first parameter) and value(second parameter)
    // Access Elements
    cout<<vec[0]<<endl;
    cout<<vec.at(1)<<endl;
    cout<<vec.front()<<" "<<vec.back()<<endl;
    // Remove Elements
    vec.pop_back();
    // Add Elements
    vec.push_back(66);
    // Vector Length
    int length=vec.size();
    // Vector Capacity
    int capacity=vec.capacity();
    // Check if vector is empty {returns 1 (true) if the vector is empty and 0 (false) if it contains elements}
    bool isEmpty=vec.empty();
    for(int i=0;i<length;i++){
        cout<<vec[i]<<" ";
    }

    //Binary Search TC=0(logn) SC=0(1)
    vector<int> elements={1,2,4,5,6,3,7};
    sort(elements.begin(),elements.end());
    int left=0,right=elements.size();
    int targetIdx=-1, target;
    cout<<"\nEnter element value to search in the array : "<<endl;
    cin>>target;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(elements[mid]==target){
            targetIdx=mid;
            break;
        }else if(elements[mid]>target){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    cout<<"target index is: "<<targetIdx<<endl;

    return 0;
}