#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//A binary tree is a tree-based hierarchical data structure where each node can have at most two children

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
    //Time Complexity=0(n), Space Complexity=0(n)
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
    //Time Complexity=0(n), Space Complexity=0(n)
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
    //Time Complexity=0(n), Space Complexity=0(n)
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
    //Time Complexity=0(n), Space Complexity=0(1)
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
    //Time Complexity=0(n), Space Complexity=0(n)
    void preOrderTraversal(Node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
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
    void postOrderTraversal(Node *root){
        if(root==NULL){
            return;
        }
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout<<root->data<<" ";
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
    //Time Complexity=0(n), Space Complexity=0(n)
    pair<bool,Node*> searchTarget(Node* root,int target){
        pair<bool,Node*> res=make_pair(false,nullptr);
        if(root==NULL){
            return res;
        }
        if(root->data==target){
            res=make_pair(true,root);
            return res;
        }
        res=searchTarget(root->left,target);
        if(res.first==false){
            res=searchTarget(root->right,target);
        }
        return res;
    }
    //Time Complexity=0(n), Space Complexity=0(n)
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
    BinaryTree::Node* root=bt->getRoot();

    ////Construct a binary tree.
    //Approach-1
    // root=bt->buildTree(root);
    //Approach-2
    // root=bt->buildTreeLevel(root);
    //Approach-3
    vector<int> elements={1,2,4,-1,-1,-1,3,-1,5,-1,-1};
    int idx=0;
    root=bt->buildTreePre(root,elements,idx);
    cout<<root->data<<endl;    
    
    //Search Target
    int target=1;
    pair<bool,BinaryTree::Node*> res=bt->searchTarget(root,target);
    cout<<"\nis "<<target<<" present : "<<res.first<<endl;
    if(res.first){
        cout<<res.second->data<<endl;
    }

    //Traversals
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

    //Freeing Memory
    bt->deleteTree(root);
    delete bt;

    return 0;
}