#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void selectionSort(vector<int> arr){
    for(int i=0;i<arr.size()-1;i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[i]){
                int temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }   
    }
    printArray(arr);
}
void bubbleSort(vector<int> arr){
    int i=1;
    while(i<arr.size()){
        for(int j=0;j<arr.size()-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        i++;
    }
    printArray(arr);
}
void insertionSort(vector<int> arr){
    for(int i=1;i<arr.size();i++){
        int cur=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>cur){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=cur;
    }
    printArray(arr);
}

int main(){
    vector<int> vec={6,4,3,16,4,2};
    cout<<"\nSelection Sort:\n";
    selectionSort(vec);
    cout<<"\nBubble Sort:\n";
    bubbleSort(vec);
    cout<<"\nInsertion Sort:\n";
    insertionSort(vec);
    cout<<"\n";
    return 0;
}