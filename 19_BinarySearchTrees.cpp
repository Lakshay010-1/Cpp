#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class BinarySearchTree{
    public:
    class Node{
        public:
        int data;
        Node *left,*right;
        Node(){}
        Node(int d){
            this->data=d;
            this->left=nullptr;
            this->right=nullptr;
        }
        ~Node(){
            delete left;
            delete right;
            cout<<"Node Deleted..."<<endl;
        }
    };
    Node* getRoot(){
        return mainRoot;
    }
    Node* insertIntoBST(Node* root,vector<int> elements){
        for(int i=0;i<elements.size();i++){
            root=insertIntoBSTUtil(root,elements[i]);
        }
        return root;
    }
    void inOrderTraversal(Node *root){
        if(root==NULL){
            return;
        }
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);
    }
    void levelOrderTraversal(Node *root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* cur=q.front();
            q.pop();
            if(cur==NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                cout<<cur->data<<" ";
                if(cur->left!=NULL){
                    q.push(cur->left);
                }
                if(cur->right!=NULL){
                    q.push(cur->right);
                }
            }
        }
        cout<<endl;
    }
    bool searchInBST(Node* root,int target){
        if(root==nullptr){
            return false;
        }
        if(root->data==target){
            return true;
        }
        if(root->data>target){
            return searchInBST(root->left,target);
        }else{
            return searchInBST(root->right,target);
        }
    }
    Node* minVal(Node* root){
        if(root==NULL){
            return new Node(-1);
        }
        Node* temp=root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
    Node* maxVal(Node* root){
        if(root==NULL){
            return new Node(-1);
        }
        Node* temp=root;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        return temp;
    }
    Node* deleteNode(Node* root,int value){
        if(root==nullptr){
            return root;
        }

        if(root->data==value){

            if(root->left==NULL && root->right==NULL){              // No Child
                delete root;
                return NULL;

            }else if(root->left!=NULL && root->right==NULL){        // 1 Child - Left Child
                Node* leftChild=root->left;
                delete root;
                return leftChild;

            }else if(root->right!=NULL && root->left==NULL){        // 1 Child - Right Child
                Node* rightChild=root->right;
                delete root;
                return rightChild;

            }else{                                                  // 2 Child

                // Approach-1. Find the min value node from the right subtree and replace the value of the root with the min value and 
                //             delete the min value node from the right subtree
                int minRightVal=minVal(root->right)->data;
                root->data=minRightVal;
                root->right=deleteNode(root->right,minRightVal);

                // Approach-2. Find the max value node from the left subtree and replace the value of the root with the max value and 
                //             delete the max value node from the left subtree
                // int maxLeftVal=maxVal(root->left)->data;
                // root->data=maxLeftVal;
                // root->left=deleteNode(root->left,maxLeftVal);

                return root;
            }
        }else if(root->data>value){
            root->left=deleteNode(root->left,value);
            return root;
        }else{
            root->right=deleteNode(root->right,value);
            return root;
        }
    }
    private:
    Node* mainRoot;
    Node* insertIntoBSTUtil(Node* root,int value){
        if(root==nullptr){
            root=new Node(value);
            return root;
        }
        if(root->data>value){
            root->left=insertIntoBSTUtil(root->left,value);
        }else{
            root->right=insertIntoBSTUtil(root->right,value);
        }
        return root;
    }
};

int main(){
    BinarySearchTree *bst=new BinarySearchTree();
    BinarySearchTree::Node *root=bst->getRoot();
    vector<int> elements={3,2,7,4,1,5,8,6,9};
    root=bst->insertIntoBST(root,elements);
    bst->inOrderTraversal(root);
    int target=8;
    cout<<endl<<"is "<<target<<" present : "<<bst->searchInBST(root,target)<<endl;
    bst->deleteNode(root,3);
    bst->inOrderTraversal(root);
    return 0;
}