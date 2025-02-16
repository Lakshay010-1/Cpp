// Linked list is a linear data structure, defined as a collection of nodes.
#include <iostream>
using namespace std;

class SNode{
public:
    int data;
    SNode *next;
    SNode() {}
    SNode(int d){
        this->data = d;
        this->next = NULL;
    }
    ~SNode(){
        int value=this->data;
        cout<<"Deleted node value is "<<value<<endl;
    }
};
class DNode{
    public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(){}
    DNode(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;        
    }
    ~DNode(){
        int value=this->data;
        cout<<"Deleted node value is "<<value<<endl;
    }
};

void insertAtHead(SNode *&head, SNode *&tail, int value){
    SNode *newNode = new SNode(value);
    if(head!=NULL){
        newNode->next = head;
    }else{
        tail=newNode;
    }
    head = newNode;
}
void insertAtHead(DNode *&head, DNode *&tail, int value){
    DNode* newNode=new DNode(value);
    if(head!=NULL){
        newNode->next=head;
        head->prev=newNode;
    }else{
        tail=newNode;
    }
    head=newNode;
}

void insertAtTail(SNode *&head, SNode *&tail, int value){
    SNode *newNode = new SNode(value);
    if(tail!=NULL){
        tail->next = newNode;
    }else{
        head=newNode;
    }
    tail = newNode;
}
void insertAtTail(DNode *&head, DNode *&tail, int value){
    DNode* newNode=new DNode(value);
    if(tail!=NULL){
        tail->next=newNode;
        newNode->prev=tail;
    }else{
        head=newNode;
    }
    tail=newNode;
}

void insertAtPos(SNode *&head, SNode *&tail, int pos, int value){
    if (pos <= 1){
        insertAtHead(head, tail, value);
    }
    else{
        SNode *temp = head;
        int count = 1;
        while (temp->next != NULL && count + 1 < pos){
            count++;
            temp = temp->next;
        }
        if(temp->next==NULL){
            insertAtTail(head,tail,value);
        }else{
            SNode *newNode = new SNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}
void insertAtPos(DNode* &head,DNode* &tail,int pos,int value){
    if(pos<=1){
        insertAtHead(head,tail,value);
    }else{
        DNode* temp=head;
        int count=1;
        while (temp->next != NULL && count+1<pos){
            count++;
            temp=temp->next;
        }
        if(temp->next==NULL){
            insertAtTail(head,tail,value);
        }else{
            DNode* newNode=new DNode(value);
            temp->next->prev=newNode;
            newNode->next=temp->next;
            newNode->prev=temp;
            temp->next=newNode;
        }
        
    }
}

int deleteFromPos(SNode* &head,SNode* &tail,int pos){
    int posValue=-1;
    if(pos<=1){
        SNode* temp=head;
        posValue=head->data;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }else{
        SNode* cur=head;
        SNode* prev=NULL;
        int count=1;
        while(cur->next!=NULL && count<pos){
            prev = cur;
            cur=cur->next;
            count++;
        }
        prev->next=cur->next;
        posValue=cur->data;
        if(cur->next==NULL){
            tail=prev;
        }
        cur->next=NULL;
        delete cur;
    }
    return posValue;
}
int deleteFromPos(DNode* &head,DNode* &tail,int pos){
    int posValue=-1;
    if(pos<=1){
        DNode* temp=head;
        posValue=temp->data;
        head=head->next;
        temp->prev=NULL;
        temp->next=NULL;
        delete temp;        
    }else{
        DNode* cur=head;
        int count=1;
        while(cur->next!=NULL && count<pos){
            cur=cur->next;
            count++;
        }
        posValue=cur->data;
        cur->prev->next=cur->next;
        if(cur->next==NULL){
            tail=cur->prev;
            cur->prev=NULL;
        }
        cur->next=NULL;
        delete cur;
    }
    return posValue;
}

void printLL(SNode *&head){
    SNode *temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void printLL(DNode* &head){
    DNode* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    // Singly Linked List
    SNode *head = NULL;
    SNode *tail = NULL;
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    printLL(head);
    insertAtPos(head, tail, 3, 3);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    printLL(head);
    cout<<deleteFromPos(head,tail,7)<<endl;
    printLL(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;

    // Doubly Linked List

    return 0;
}