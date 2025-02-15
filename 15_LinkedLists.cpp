// Linked list is a linear data structure, defined as a collection of nodes.
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){}
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};

void addFirst(Node* &head,int value){
    Node* newNode=new Node(value);
    newNode->next=head;
    head=newNode;
}
void printLL(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head=new Node(6);
    cout<<head->data<<endl;
    cout<<head->next<<endl;
    addFirst(head,5);
    addFirst(head,4);
    printLL(head);
    return 0;
}