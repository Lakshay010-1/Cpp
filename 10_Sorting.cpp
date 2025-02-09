#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
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
    printVector(arr);
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
    printVector(arr);
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
    printVector(arr);
}
void merge(int* arr,int si,int mid,int ei){
    int len1=mid-si+1,len2=ei-mid;
    int* first=new int[len1];
    int* second=new int[len2];
    for(int i=0;i<len1;i++){
        first[i]=arr[i+si];
    }
    for(int i=0;i<len2;i++){
        second[i]=arr[mid+i+1];
    }
    int i=0,j=0,k=si;
    while(i<len1 && j<len2 ){
        if(first[i]>second[j]){
            arr[k++]=second[j++];
        }else{
            arr[k++]=first[i++];
        }
    }
    while(i<len1){
        arr[k++]=first[i++];
    }
    while(j<len2){
        arr[k++]=second[j++];
    }
    delete [] first;
    delete [] second;
}
void mergeSort(int* arr,int si,int ei){
    if(si>=ei){
        return;
    }
    int mid=si+(ei-si)/2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);
    merge(arr,si,mid,ei);
}

int partition(int* arr,int si,int ei){
    int pivot=arr[si];
    int cnt=0;
    for(int i=si+1;i<=ei;i++){
        cnt=(arr[i]<=pivot)?cnt+1:cnt;
    }
    int pivotIdx=si+cnt;
    swap(arr[pivotIdx],arr[si]);
    int i=si, j=ei;
    while(i<pivotIdx && j>pivotIdx){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIdx && pivotIdx<j){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIdx;

}
void quickSort(int* arr,int si,int ei){
    if(si>=ei){
        return;
    }
    int pivotIdx=partition(arr,si,ei);
    quickSort(arr,si,pivotIdx-1);
    quickSort(arr,pivotIdx+1,ei);
}

int main(){
    vector<int> vec={6,4,3,16,4,2};

    cout<<"\nSelection Sort:\n";
    selectionSort(vec);

    cout<<"\nBubble Sort:\n";
    bubbleSort(vec);

    cout<<"\nInsertion Sort:\n";
    insertionSort(vec);

    cout<<"\nMerge Sort:\n";
    int arr[]={6,4,3,16,4,2};
    int arrSize=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,arrSize-1);
    printArray(arr,arrSize);

    cout<<"\nQuick Sort:\n";
    int arr2[]={6,4,3,16,4,2};
    int arrSize2=sizeof(arr2)/sizeof(arr2[0]);
    quickSort(arr2,0,arrSize2-1);
    printArray(arr2,arrSize2);
    cout<<"\n";


    return 0;
}