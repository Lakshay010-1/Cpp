#include<iostream>
#include<vector>
#include<list>
using namespace std;

// HashMap is a data structure in which the elements are stored in key-value pairs
// such that every key is mapped to a value using a hash function.

template<typename K,typename V>
struct UnorderedMap{
    private:
    int bucketCapacity;
    int bucketSize;
    vector<list<pair<K,V>>> buckets;
    
    // Hash Function - map a key to a unique index
    // Time Complexity=0(1), Space Complexity=0(1)
    size_t hashFun(K key){
        return hash<K>{}(key) % bucketCapacity;
    }
    
    // rehash to resize a hash table when it becomes too full, in order to maintain efficient operations.
    // Time Complexity=0(n), Space Complexity=0(n)
    void rehash(){
        vector<list<pair<K,V>>> oldBucket=move(buckets);
        int oldCap=bucketCapacity;
        bucketCapacity*=2;
        buckets.clear();
        buckets.resize(bucketCapacity);
        bucketSize=0;
        for(size_t i=0;i<oldCap;i++){
            for(const auto& pair:oldBucket[i]){
                insert(pair.first,pair.second);
            }            
        }
    }
    
    public:
    UnorderedMap(int capacity=4):bucketCapacity(capacity), bucketSize(0), buckets(capacity){}
    ~UnorderedMap(){cout<<"Memory Freed";}
    
    // check if map is empty or not
    // Time Complexity=0(1), Space Complexity=0(1)
    bool empty(){
        return bucketSize==0;
    }

    // Insert key-value
    // Time Complexity=0(1), Space Complexity=0(1)
    // Time Complexity=0(n) in worst case
    void insert(K key,V value){
        size_t bucketIdx=hashFun(key);
        for (auto& pair : buckets[bucketIdx]) {
            if (pair.first == key) {
                remove(key);
                return;
            }
        }
        buckets[bucketIdx].emplace_back(key, value); // Insert new key
        bucketSize++;
        double lambda=(double)bucketSize/bucketCapacity;
        if(lambda>2.0){
            rehash();
        }
    }

    // Search key
    // Time Complexity=0(1), Space Complexity=0(1)
    // Time Complexity=0(n) in worst case
    bool search(K key){
        size_t bucketIdx=hashFun(key);
        for(const auto&pair : buckets[bucketIdx]){
            if(pair.first==key){
                return true;
            }
        }
        return false;
    }

    // Get value by key
    // Time Complexity=0(1), Space Complexity=0(1)
    // Time Complexity=0(n) in worst case
    V get(K key) {
        if(search(key)){
            size_t bucketIdx = hashFun(key);
            for (const auto& pair : buckets[bucketIdx]) {
                if (pair.first == key) {
                    return pair.second;
                }
            }
        }
        throw runtime_error("Key not found");
    }

    // Remove key-value
    // Time Complexity=0(1), Space Complexity=0(1)
    // Time Complexity=0(n) in worst case
    void remove(K key) {
        size_t index = hashFun(key);
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it);
                bucketSize--;
                return;
            }
        }
    }

    // Display all key-value pairs
    // Time Complexity=0(n), Space Complexity=0(1)
    void display() {
        if(bucketSize==0){
            cout<<"map is empty"<<endl;
            return;
        }
        cout<<"key => value : "<<endl;
        for (size_t i = 0; i < bucketCapacity; i++) {
            for (const auto& pair : buckets[i]) {
                cout << "[" << pair.first << " => " << pair.second << "], ";
            }
            cout<<endl;
        }
    }
};

int main(){
    
    UnorderedMap<int,int> *map=new UnorderedMap<int,int>(2);

    // empty()
    cout<<"is map empty : "<<map->empty()<<endl;

    // display()
    map->display();
    cout<<endl;

    // insert()
    map->insert(1,1);
    map->insert(5,5);
    map->insert(2,2);
    map->insert(3,3);
    map->insert(4,4);
    map->display();
    cout<<endl;

    // remove()
    map->remove(5);
    map->display();
    cout<<endl;

    // get()
    int key=2;
    if(map->search(key)){
        cout<<"value of key "<<key<<" is : "<<map->get(key)<<endl;
    }else{
        cout<<"Key is not found!"<<endl;
    }

    //Freeing Memory
    cout<<endl;
    delete map;

    return 0;
}