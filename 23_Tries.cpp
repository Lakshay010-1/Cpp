#include<iostream>
using namespace std;

// Trie, also known as a prefix tree, is a tree-like data structure used to store a dynamic set of strings.
// It is particularly useful for efficient retrieval of keys in a large dataset of strings.

class Trie{
    private:
    class Node{
        public:
        char data;
        Node* children[26];
        bool endOfWord;
        Node(char c){
            this->data=c;
            this->endOfWord=false;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
        }
    };
    Node* root;
    // Time Complexity=0(length of the word), Space Complexity=0(length of the word)
    void insertUtil(Node* root,string word){
        if(word.length()==0){
            root->endOfWord=true;
            return;
        }
        int curCharIdx=word[0]-'a';
        Node* child;
        if(root->children[curCharIdx]==NULL){
            child=new Node(word[0]);
            root->children[curCharIdx]=child;
        }else{
            child=root->children[curCharIdx];
        }
        insertUtil(child,word.substr(1));
    }
    // Time Complexity=0(length of the word), Space Complexity=0(length of the word)
    bool searchUtil(Node* root,string word){
        if(word.length()==0){
            return root->endOfWord;
        }
        int curCharIdx=word[0]-'a';
        if(root->children[curCharIdx]==NULL){
            return false;
        }
        return searchUtil(root->children[curCharIdx],word.substr(1));
    }
    // Time Complexity=0(length of the word), Space Complexity=0(length of the word)
    bool deleteUtil(Node* root,string word){
        if(word.length()==0){
            root->endOfWord=false;
            return true;
        }
        int curCharIdx=word[0]-'a';
        if(root->children[curCharIdx]==NULL){
            return true;
        }
        return deleteUtil(root->children[curCharIdx],word.substr(1));        
    }
    public:
    Trie(){
        root=new Node('\0');
    }
    bool insert(string word){
        insertUtil(root,word);
        return true;
    }
    bool search(string word){
        return searchUtil(root,word);
    }
    bool deleteWord(string word){
        return deleteUtil(root,word);
    }
};
int main(){
    Trie *trie=new Trie();
    cout<<"is inserted : "<<trie->insert("abcdefg")<<endl;
    cout<<"is present : "<<trie->search("abcdefg")<<endl;
    cout<<"is present : "<<trie->search("abcdef")<<endl;
    cout<<"is deleted : "<<trie->deleteWord("abcdefg")<<endl;
    cout<<"is present : "<<trie->search("abcdefg")<<endl;
    return 0;
}