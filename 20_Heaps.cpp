#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

// Heap is a special Tree-based Data Structure that has the following properties.
// 1. It is a Complete Binary Tree.
// 2. It either follows max heap or min heap property.
// Max Heap = value of the node must be the greatest among all its descendant nodes
// Min Heap = value of the node must be the smallest among all its descendant nodes

template<typename K>
class heap{                                         //Max Heap
    private:
    int size;
    K* arr;
    int curPos;
    const int root=1;

    // Returns parent index
    // Time Complexity=0(1), Space Complexity=0(1)
    int parent(int child){
        return child/2;
    }
    
    // Returns left child index
    // Time Complexity=0(1), Space Complexity=0(1)
    int leftChild(int parentIdx){
        return parentIdx*2;
    }

    // Returns right child index
    // Time Complexity=0(1), Space Complexity=0(1)
    int rightChild(int parentIdx){
        return (parentIdx*2)+1;
    }

    // heapifyUtil(idx) arranges the node at idx, and its subtrees accordingly so that the heap property is maintained.
    // Time Complexity=0(logn), Space Complexity=0(logn)
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
        arr=new K[this->size];
        curPos=0;
    }
    heap(K arr[],int size){
        this->arr=arr;
        size=size;
        curPos=size;
    }
    ~heap(){
        delete [] arr;
        cout<<"Memory Freed"<<endl;
    }
    
    //Insertion 
    // Time Complexity=0(logn), Space Complexity=0(1)
    bool insertNode(K val){
        if(curPos>=size){
            return false;
        }
        int idx=++curPos;
        arr[idx]=val;
        while(idx>1){
            int curParent=parent(idx);
            if(arr[idx]>arr[curParent]){
                swap(arr[curParent],arr[idx]);
                idx=curParent;
            }else{
                break;
            }
        }
        return true;
    }

    // Deletion
    // Time Complexity=0(logn), Space Complexity=0(1)
    K deleteRoot(){
        if(curPos<=0){
            return INT_MIN;
        }
        K deletedVal=arr[root];
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

    //Heap Sort
    // Time Complexity=0(n.logn), Space Complexity=0(1).0(logn)=0(logn)
    void heapSort(){
        int tempCurPos=curPos;
        while(curPos>1){
            swap(arr[root],arr[curPos]);
            curPos--;
            heapifyUtil(root);
        }
        curPos=tempCurPos;
    }

    //Heapify
    // Time Complexity=0(n.logn), Space Complexity=0(1).0(logn)=0(logn)
    bool heapify(){
        for(int i=curPos/2;i>=1;i--){
            heapifyUtil(i);
        }
        return true;
    }

    // Print Heap Leafs
    // Time Complexity=0(n), Space Complexity=0(1)
    void printLeafs(){
        cout<<"Leafs : ";
        for(int i=(curPos/2)+1;i<=curPos;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    // Print Heap
    // Time Complexity=0(n), Space Complexity=0(1)
    void printHeap(){
        cout<<"Heap : ";
        if(curPos<=0){
            cout<<"Empty"<<endl;
            return;
        }
        for(int i=1;i<=curPos;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    heap<int> *h=new heap<int>();
    cout<<"Insertion"<<endl;
    h->insertNode(1);
    h->printHeap();
    h->insertNode(2);
    h->printHeap();
    h->insertNode(3);
    h->printHeap();
    h->insertNode(4);
    h->printHeap();
    h->insertNode(5);
    h->printHeap();
    h->printLeafs();

    cout<<"\nDeletion "<<endl;
    cout<<"Deleted Value : "<<h->deleteRoot()<<endl;
    h->printHeap();
    cout<<"Deleted Value : "<<h->deleteRoot()<<endl;
    h->printHeap();
    cout<<"Deleted Value : "<<h->deleteRoot()<<endl;
    h->printHeap();
    cout<<"Deleted Value : "<<h->deleteRoot()<<endl;
    h->printHeap();
    cout<<"Deleted Value : "<<h->deleteRoot()<<endl;
    h->printHeap();
    cout<<"Deleted Value : "<<h->deleteRoot()<<endl;
    h->printHeap();

    int elements[]={-1,1,2,5,4,3};
    h=new heap<int>(elements,5);
    cout<<endl<<"New Elements : ";
    for(int i=1;i<sizeof(elements)/sizeof(elements[0]);i++){
        cout<<elements[i]<<" ";
    }
    cout<<endl;

    cout<<"\nHeapify-ing "<<endl;
    h->heapify();
    h->printHeap();

    cout<<"\nHeap Sort "<<endl;
    h->heapSort();
    h->printHeap();    
    
    cout<<"\nHeapify-ing "<<endl;
    h->heapify();
    h->printHeap();
    cout<<endl;
    
    //Character map heap
    // cout<<endl;
    // heap<char> *hChar=new heap<char>();
    // cout<<"Insertion"<<endl;
    // hChar->insertNode('a');
    // hChar->printHeap();
    // hChar->insertNode('b');
    // hChar->printHeap();
    // hChar->insertNode('c');
    // hChar->printHeap();
    // hChar->insertNode('d');
    // hChar->printHeap();
    // hChar->insertNode('e');
    // hChar->printHeap();
    
    //Freeing Memory
    delete h;
    // delete hChar;

    return 0;
}