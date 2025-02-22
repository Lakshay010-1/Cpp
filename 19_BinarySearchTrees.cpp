#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// BST is a hierarchical structure that follows all properties of binary tree and for every nodes,
// its left subtree contains values less than the node and
// the right subtree contains values greater than the node.

class BinarySearchTree{
    public:
    ~BinarySearchTree(){
        delete mainRoot;
        cout<<endl<<"Tree Deleted"<<endl;
    }
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
        }
    };
    Node* getRoot(){
        return mainRoot;
    }
    //Time Complexity=0(n.logn), Space Complexity=0(n.logn)     -> for balanced BST
    //Time Complexity=0(n^2), Space Complexity=0(n^2)           -> for skewed BST
    Node* insertIntoBST(Node* root,vector<int> elements){
        for(int i=0;i<elements.size();i++){
            root=insertIntoBSTUtil(root,elements[i]);
        }
        return root;
    }
    //Time Complexity=0(n), Space Complexity=0(n)
    void inOrderTraversal(Node *root){
        if(root==NULL){
            return;
        }
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);
    }
    //Time Complexity=0(n), Space Complexity=0(n)
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
    //Time Complexity=0(logn), Space Complexity=0(logn)
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
    //Time Complexity=0(logn), Space Complexity=0(1)
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
    //Time Complexity=0(logn), Space Complexity=0(1)
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
    //Time Complexity=0(logn), Space Complexity=0(logn)
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
    //Time Complexity=0(n), Space Complexity=0(n)
    void freeMemory(Node* root){
        if(root==NULL){
            return;
        }
        freeMemory(root->left);
        freeMemory(root->right);
        delete root;
    }
    private:
    Node* mainRoot;
    //Time Complexity=0(logn), Space Complexity=0(logn)     -> for balanced BST
    //Time Complexity=0(n), Space Complexity=0(n)           -> for skewed BST
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

    // Construct a BST
    vector<int> elements={3,2,7,4,1,5,8,6,9};
    root=bst->insertIntoBST(root,elements);

    // Traversal
    cout<<"\nIn-order Traversal : ";
    bst->inOrderTraversal(root);
    cout<<endl;
    cout<<"Level Order Traversal : ";
    bst->levelOrderTraversal(root);

    //Search Target
    int target=8;
    cout<<endl<<"is "<<target<<" present : "<<bst->searchInBST(root,target)<<endl<<endl;

    // Delete Node
    int deleteTarget=3;
    if(bst->searchInBST(root,deleteTarget)){
        bst->deleteNode(root,deleteTarget);
        cout<<deleteTarget<<" deleted"<<endl;
        bst->inOrderTraversal(root);
        cout<<endl;
    }

    //Freeing Memory
    bst->freeMemory(root);
    delete bst;

    return 0;
}