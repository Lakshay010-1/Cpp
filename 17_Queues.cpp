#include<iostream>
#include<climits>
using namespace std;

// Queue is a linear data structure that follows FIFO (First In First Out) Principle.

class Queue{
    private:
    int *arr, frontIdx, rearIdx, arrSize;
    public:
    Queue():arr(nullptr), frontIdx(-1), rearIdx(-1){}
    Queue(int arrSize){
        arr=new int[arrSize];
        this->arrSize=arrSize;
        frontIdx=-1;
        rearIdx=-1;
    }
    ~Queue(){
        delete [] arr;
        cout<<"Destructor called..."<<endl;
    }
    int front(){
        if(frontIdx==-1){
            return INT_MIN;
        }
        return this->arr[frontIdx];
    }
    int back(){
        if(rearIdx==-1){
            return INT_MIN;
        }
        return this->arr[rearIdx];
    }
    bool empty(){
        return frontIdx==-1;
    }
    int size(){
        if(frontIdx==-1){
            return 0;
        }
        int diff=rearIdx-this->frontIdx;
        return (diff<0)?arrSize+diff+1:diff+1;
    }
    bool push(int value){
        if((rearIdx+1)%arrSize==frontIdx){
            cout<<"Queue is full ( value = "<<value<<" )"<<endl;
            return false;
        }
        if(frontIdx==-1){
            frontIdx=0;
            rearIdx=0;
        }else{
            rearIdx=(rearIdx+1)%arrSize;
        }
        arr[rearIdx]=value;
        return true;
    }
    int pop(){
        if(empty()){
            cout<<"Queue is empty"<<endl;
            return INT_MIN;
        }
        int poppedElement=arr[frontIdx];
        if(frontIdx==rearIdx){
            frontIdx=-1;
            rearIdx=-1;
        }else{
            frontIdx=(frontIdx+1)%arrSize;
        }
        return poppedElement;
    }
    void print(){
        if(this->empty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        int temp=frontIdx;
        while(temp!=rearIdx){
            cout<<arr[temp]<<" ";
            temp=(temp+1)%arrSize;
        }
        cout<<arr[temp]<<endl;
        cout<<"Front : "<<this->front()<<endl;
        cout<<"Back : "<<this->back()<<endl;
    }
};

int main(){
    Queue *q=new Queue(5);
    q->push(1);
    q->push(2);
    q->push(3);
    q->push(5);
    q->push(2);
    q->push(3);
    q->push(5);
    cout<<"size : "<<q->size()<<endl;
    q->print();
    cout<<"Popped element : "<<q->pop()<<endl;
    cout<<"Popped element : "<<q->pop()<<endl;
    cout<<"Popped element : "<<q->pop()<<endl;    
    cout<<"size : "<<q->size()<<endl;
    q->print();
    q->push(7);
    q->push(8);
    q->push(9);
    q->push(8);
    cout<<"size : "<<q->size()<<endl;
    q->print();

    delete q;

    return 0;
}