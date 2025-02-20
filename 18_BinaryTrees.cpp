#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class BinaryTree{
    public:
    class Node{
        public:
        int data;
        Node *left, *right;
        Node():data(),left(nullptr),right(nullptr){}
        Node(int d){
            this->data=d;
            this->left=NULL;
            this->right=NULL;
        }
        ~Node(){
            delete left;
            delete right;
            cout<<"Node deleted"<<endl;
        }
    };
    BinaryTree():root(nullptr){}
    BinaryTree(int value){
        root=new Node(value);
    }
    ~BinaryTree(){
        delete root;
        cout<<"Tree deleted"<<endl;
    }
    Node* getRoot(){
        return root;
    }
    Node* buildTree(Node *root){
        int val;
        cout<<"Enter element value (-1 for NULL) : "<<endl;
        cin>>val;
        
        if(val==-1){
            return NULL;
        }
        root=new Node(val);
        cout<<"Enter element value to insert in left of "<<root->data<<endl;
        root->left=buildTree(root->left);
        cout<<"Enter element value to insert in right of "<<root->data<<endl;
        root->right=buildTree(root->right);
        return root;
    }
    Node* buildTreePre(Node* root,vector<int> nodes,int &idx){
        if(idx>=nodes.size()){
            return NULL;
        }
        if(nodes[idx]==-1){
            idx++;
            return NULL;
        }
        root=new Node(nodes[idx]);
        idx++;
        root->left=buildTreePre(root->left,nodes,idx);
        root->right=buildTreePre(root->right,nodes,idx);
        return root;
    }
    Node* buildTreeLevel(Node* root){
        int val;
        queue<Node*> q;
        cout<<"Enter root value : "<<endl;
        cin>>val;
        root=new Node(val);
        Node* temp=root;
        q.push(temp);
        while(!q.empty()){
            Node* cur=q.front();
            q.pop();
            cout<<"Enter element value(-1 for NULL) to insert in left of "<<cur->data<<endl;
            cin>>val;
            if(val!=-1){
                cur->left=new Node(val);
                q.push(cur->left);
            }
            cout<<"Enter element value(-1 for NULL) to insert in right of "<<cur->data<<endl;
            cin>>val;
            if(val!=-1){
                cur->right=new Node(val);
                q.push(cur->right);
            }
        }
        return root;
        
    }
    void morrisTraversal(Node* root){
        // In-Order traversal
        Node* cur=root;
        while(cur!=NULL){
            // If no left child, visit this node and go right
            if(cur->left==NULL){
                cout<<cur->data<<" ";
                cur=cur->right;
            }else{
            // Find the inorder predecessor of curr
                Node* prev=cur->left;
                while(prev->right!=nullptr && prev->right!=cur){
                    prev=prev->right;
                }
                // Make curr the right child of its inorder predecessor
                if(prev->right==nullptr){
                    prev->right=cur;
                    cur=cur->left;
                }else{
                // Revert the changes made in the tree structure
                    prev->right=nullptr;
                    cout<<cur->data<<" ";
                    cur=cur->right;
                }
            }
        }
    }
    void preOrderTraversal(Node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
    void inOrderTraversal(Node *root){
        if(root==NULL){
            return;
        }
        inOrderTraversal(root->left);
        cout<<root->data<<" ";
        inOrderTraversal(root->right);

    }
    void postOrderTraversal(Node *root){
        if(root==NULL){
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
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
    void deleteTree(Node* root){
        if(root==NULL){
            return;
        }
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
    private:
    Node* root;    
};

int main(){
    BinaryTree *bt=new BinaryTree();
    vector<int> elements={1,2,4,-1,-1,-1,3,-1,5,-1,-1};
    int idx=0;
    BinaryTree::Node* root=bt->getRoot();
    // root=bt->buildTree(root);
    // root=bt->buildTreeLevel(root);
    root=bt->buildTreePre(root,elements,idx);
    cout<<root->data<<endl;    
    cout<<"\nMorris Traversal:"<<endl;
    bt->morrisTraversal(root);
    cout<<"\nLevel-Order Traversal:"<<endl;
    bt->levelOrderTraversal(root);
    cout<<"Pre-Order Traversal:"<<endl;
    bt->preOrderTraversal(root);
    cout<<"\nIn-Order Traversal:"<<endl;
    bt->inOrderTraversal(root);
    cout<<"\nPost-Order Traversal:"<<endl;
    bt->postOrderTraversal(root);
    cout<<endl;

    bt->deleteTree(root);
    delete bt;
    return 0;
}