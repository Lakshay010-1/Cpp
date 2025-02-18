#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

// Stack is a linear data structure that follows LIFO (Last In First Out) Principle.

class Stack{
    private:
    int *arr, top, size;
    public:
    Stack(){}
    Stack(int size){
        this->arr=new int[size];
        this->size=size;
        this->top=0;
    }
    ~Stack(){
        delete [] arr;
        cout<<"Destrcutor called... "<<endl;
    }
    bool push(int element){
        if(top>=size){
            cout<<"Stack Overflow (element = "<<element<<" )"<<endl;
            return false;
        }
        arr[top++]=element;
        return true;
    }
    int pop(){
        if(this->empty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
        return arr[--top];
    }
    int peek(){
        if(this->empty()){
            return INT_MIN;
        }
        return arr[top-1];
    }
    bool empty(){
        return top<=0;
    }
    void print(){
        for(int i=top-1;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<"\nPeek : "<<peek()<<endl;
    }
};

int main(){
    Stack* s=new Stack(5);
    s->pop();
    s->push(10);
    s->push(11);
    s->push(12);
    s->push(13);
    s->push(14);
    s->push(15);
    s->print();
    s->pop();
    s->print();

    delete s;

    return 0;
}