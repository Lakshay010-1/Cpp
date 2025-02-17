#include <iostream>
using namespace std;

// Linked list is a linear data structure, defined as a collection of nodes.

class SinglyLinkedList{
    private:
    class SNode{
        public:
        int data;
        SNode *next;
        SNode(){}
        SNode(int d){
            this->data = d;
            this->next = NULL;
        }
        ~SNode(){
            int value=this->data;
            cout<<"Deleted node value is "<<value<<endl;
        }
    };
    SNode* head=NULL;
    SNode*tail=NULL;
    public:
    int getHead(){
        return (head==NULL)?-1:head->data;
    }
    int getTail(){
        return (tail==NULL)?-1:tail->data;
    }
    void insertAtHead(int value){
        SNode *newNode = new SNode(value);
        if(head!=NULL){
            newNode->next = head;
        }else{
            tail=newNode;
        }
        head = newNode;
    }
    void insertAtTail(int value){
        SNode *newNode = new SNode(value);
        if(tail!=NULL){
            tail->next = newNode;
        }else{
            head=newNode;
        }
        tail = newNode;
    }
    void insertAtPos(int pos, int value){
        if (pos <= 1 || head==NULL){
            insertAtHead(value);
        }
        else{
            SNode *temp = head;
            int count = 1;
            while (temp->next != NULL && count + 1 < pos){
                count++;
                temp = temp->next;
            }
            if(temp->next==NULL){
                insertAtTail(value);
            }else{
                SNode *newNode = new SNode(value);
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
    int deleteFromPos(int pos){
        int posValue=-1;
        if(head==NULL && tail==NULL){
            return posValue;
        }
        if(pos<=1){
            SNode* temp=head;
            posValue=head->data;
            head=head->next;
            if(head==NULL){
                tail=NULL;
            }
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
    void print(){
        SNode *temp = head;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;        
        cout<<"Head : "<<this->getHead()<<endl;
        cout<<"Tail : "<<this->getTail()<<endl;
    }
};

class DoublyLinkedList{
    private:
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
    DNode* head=NULL;
    DNode* tail=NULL;
    public:
    int getHead(){
        return (head==NULL)?-1:head->data;
    }
    int getTail(){
        return (tail==NULL)?-1:tail->data;
    }
    void insertAtHead(int value){
        DNode* newNode=new DNode(value);
        if(head!=NULL){
            newNode->next=head;
            head->prev=newNode;
        }else{
            tail=newNode;
        }
        head=newNode;
    }
    void insertAtTail(int value){
        DNode* newNode=new DNode(value);
        if(tail!=NULL){
            tail->next=newNode;
            newNode->prev=tail;
        }else{
            head=newNode;
        }
        tail=newNode;
    }
    void insertAtPos(int pos,int value){
        if(pos<=1 || head==NULL){
            insertAtHead(value);
        }else{
            DNode* temp=head;
            int count=1;
            while (temp->next != NULL && count+1<pos){
                count++;
                temp=temp->next;
            }
            if(temp->next==NULL){
                insertAtTail(value);
            }else{
                DNode* newNode=new DNode(value);
                temp->next->prev=newNode;
                newNode->next=temp->next;
                newNode->prev=temp;
                temp->next=newNode;
            }
            
        }
    }
    int deleteFromPos(int pos){
        int posValue=-1;
        if(head==NULL && tail==NULL){
            return posValue;
        }
        if(pos<=1){
            DNode* temp=head;
            posValue=temp->data;
            head=head->next;
            if(head==NULL){
                tail=NULL;
            }else{
                head->prev=NULL;
            }
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
            if (cur->prev != NULL) {
                cur->prev->next = cur->next;
            } else {
                head = cur->next;
            }            
            if(cur->next!=NULL){
                cur->next->prev = cur->prev;
            }else{
                tail=cur->prev;
            }
            cur->next=NULL;
            delete cur;
        }
        return posValue;
    }
    void print(){
        DNode* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        cout<<"Head : "<<this->getHead()<<endl;
        cout<<"Tail : "<<this->getTail()<<endl;
    }
    void printRev(){
        DNode* temp=tail;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
        cout<<endl;
        cout<<"Head : "<<this->getHead()<<endl;
        cout<<"Tail : "<<this->getTail()<<endl;
    }
};

class SinglyCircularLinkedList{
    private:
    class CNode{
        public:
        int data;
        CNode* next;
        CNode(){}
        CNode(int d){
            this->data=d;
            this->next=NULL;
        }
        ~CNode(){
            cout<<"Deleted Node value is : "<<this->data<<endl;
        }
    };
    CNode* tail=NULL;
    public:
    int getHead(){
        return (tail==NULL)?-1:tail->next->data;
    }
    int getTail(){
        return (tail==NULL)?-1:tail->data;
    }
    void insertAtHead(int value){
        CNode* newNode=new CNode(value);
        if(tail==NULL){
            tail=newNode;
            tail->next = tail;
        }else{
            newNode->next=tail->next;
            tail->next=newNode;
        }
    }
    void insertAtTail(int value){
        CNode* newNode=new CNode(value);
        if(tail==NULL){
            tail=newNode;
        }else{
            newNode->next=tail->next;
        }
        tail->next=newNode;
        tail=newNode;
    }
    void insertAtPos(int pos, int value){
        if (pos <= 1 || tail==NULL){
            insertAtHead(value);
        }
        else{
            CNode *temp = tail;
            int count = 0;
            bool tailEncountered=false;
            while (!tailEncountered && count+1  < pos){
                count++;
                temp = temp->next;                
                if(temp==tail){
                    tailEncountered=true;
                }
            }
            if(count + 1 < pos && temp == tail){
                insertAtTail(value);
            }else{
                CNode *newNode = new CNode(value);
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
    int deleteFromPos(int pos){
        int posValue=-1;
        if(tail==NULL){
            return posValue;
        }
        int count=1;
        CNode* temp=tail;
        while(count+1 < pos && temp->next != tail){
            count++;
            temp=temp->next;
        }
        CNode* delNode=temp->next;
        posValue=delNode->data;

        if(delNode==tail){
            tail=(tail==tail->next)?NULL:temp;
        }
        temp->next=delNode->next;

        delete delNode;
        return posValue;
    }
    void print(){
        if (tail == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        CNode* temp=tail->next;
        bool tailEncountered=false;
        while(!tailEncountered){
            cout<<temp->data<<" ";
            if(temp==tail){
                tailEncountered=true;
            }
            temp=temp->next;
        }
        cout<<endl;
        cout<<"Head : "<<this->getHead()<<endl;
        cout<<"Tail : "<<this->getTail()<<endl;
    }
};

int main(){

    cout<<"\n\nSingly LinkedList : "<<endl;
    SinglyLinkedList sll;
    sll.insertAtHead(2);
    sll.print();
    sll.insertAtHead(1);
    sll.print();
    sll.insertAtTail(4);
    sll.insertAtTail(5);
    sll.print();
    sll.insertAtPos(3,3);
    sll.print();
    cout<<sll.deleteFromPos(3)<<endl;
    sll.print();

    cout<<"\n\nDoubly LinkedList : "<<endl;
    DoublyLinkedList dll;
    dll.insertAtHead(2);
    dll.print();
    dll.insertAtHead(1);
    dll.print();
    dll.insertAtTail(4);
    dll.insertAtTail(5);
    dll.print();
    dll.insertAtPos(3,3);
    dll.print();
    cout<<dll.deleteFromPos(3)<<endl;
    dll.print();
    dll.printRev();

    cout<<"\n\nSingly Circular LinkedList : "<<endl;
    SinglyCircularLinkedList scll;
    scll.insertAtHead(2);
    scll.print();
    scll.insertAtHead(1);
    scll.print();
    scll.insertAtTail(4);
    scll.insertAtTail(5);
    scll.print();
    scll.insertAtPos(3,3);
    scll.print();
    cout<<scll.deleteFromPos(3)<<endl;
    scll.print();

    return 0;
}