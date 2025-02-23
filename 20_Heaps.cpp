#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

// Heap is a special Tree-based Data Structure that has the following properties.
// 1. It is a Complete Binary Tree.
// 2. It either follows max heap or min heap property.
// Max Heap = value of the node must be the greatest among all its descendant nodes
// Min Heap = value of the node must be the smallest among all its descendant nodes

class heap{
    private:
    int size;
    int* arr;
    int curPos;
    const int root=1;
    void heapifyUtil(int idx){
        int largestValIdx=idx;
        int left=leftChild(idx), right=rightChild(idx);
        
        if(left<=curPos && arr[largestValIdx]<arr[left]){
            largestValIdx=left;
        }
        if(right<=curPos && arr[largestValIdx]<arr[right]){
            largestValIdx=right;
        }
        if(largestValIdx!=idx){
            swap(arr[idx],arr[largestValIdx]);
            heapifyUtil(largestValIdx);
        }
    }
    public:
    heap(int size=50){
        this->size=size;
        arr=new int[this->size];
        curPos=0;
        arr[root]=-1;
    }
    heap(int arr[],int size){
        this->arr=arr;
        size=size+10;
        curPos=5;
    }
    ~heap(){
        delete [] arr;
        cout<<"Memory Freed"<<endl;
    }
    // Return root index
    int getRoot(){
        return this->root;
    }
    //Insertion 
    bool insertNodeMaxHeap(int val){
        if(curPos+1>=size){
            return false;
        }
        int idx=++curPos;
        arr[idx]=val;
        while(idx>0){
            int parent=idx/2;
            if(arr[idx]>arr[parent]){
                swap(arr[parent],arr[idx]);
                idx=parent;
            }else{
                break;
            }
        }
        return true;
    }
    // Deletion
    int deleteRoot(){
        if(curPos<=0){
            cout<<"heap is empty ";
            return INT_MIN;
        }
        int deletedVal=arr[root];
        arr[root]=arr[curPos--];
        int idx=root;
        while(idx<curPos){
            int leftChildIdx=idx*2;
            int rightChildIdx=leftChildIdx+1;
            if(leftChildIdx < curPos && arr[leftChildIdx] > arr[idx])
            {
                swap(arr[idx],arr[leftChildIdx]);
                idx=leftChildIdx;
            }
            else if(rightChildIdx < curPos && arr[rightChildIdx] > arr[idx])
            {
                swap(arr[idx],arr[rightChildIdx]);
                idx=rightChildIdx;
            }
            else{
                break;
            }
        }
        return deletedVal;
    }
    // Returns left child
    int leftChild(int parentIdx){
        return parentIdx*2;
    }
    // Returns right child
    int rightChild(int parentIdx){
        return (parentIdx*2)+1;
    }
    // Print Heap
    void printHeap(){
        if(curPos<=0){
            return;
        }
        for(int i=1;i<=curPos;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<"Curpos : "<<curPos<<endl;
    }
    // Print Heap Leafs
    void printLeafs(){
        for(int i=(curPos/2)+1;i<=curPos;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void heapify(){
        for(int i=curPos/2;i>=1;i--){
            heapifyUtil(i);
        }
    }
};


int main(){
    heap h;
    h.insertNodeMaxHeap(1);
    h.printHeap();
    h.insertNodeMaxHeap(2);
    h.printHeap();
    h.insertNodeMaxHeap(3);
    h.printHeap();
    h.insertNodeMaxHeap(4);
    h.printHeap();
    h.insertNodeMaxHeap(5);
    h.printHeap();
    cout<<"Leafs are : ";
    h.printLeafs();

    cout<<"Left Child "<<h.leftChild(1)<<endl;
    cout<<"Right Child "<<h.rightChild(1)<<endl;

    // cout<<"Deleted Root is : "<<h.deleteRoot()<<endl;
    // h.printHeap();
    // cout<<"Deleted Root is : "<<h.deleteRoot()<<endl;
    // h.printHeap();
    // cout<<"Deleted Root is : "<<h.deleteRoot()<<endl;
    // h.printHeap();
    // cout<<"Deleted Root is : "<<h.deleteRoot()<<endl;
    // h.printHeap();
    // cout<<"Deleted Root is : "<<h.deleteRoot()<<endl;
    // h.printHeap();
    // cout<<"Deleted Root is : "<<h.deleteRoot()<<endl;   
    // h.printHeap();

    h.heapify();
    h.printHeap();

    int maxheap[]={-1,1,2,3,4,5};
    heap h2(maxheap,5);
    h2.printHeap();
    h2.heapify();
    h2.printHeap();
    
    return 0;
}