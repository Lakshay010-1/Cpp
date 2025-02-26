// STL is Standard Template Library (contains containers and algorithms)
#include <iostream>
#include<vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include<algorithm>
using namespace std;

int main()
{
    // Containers    
    // 1. Vector - Stores elements like an array but can dynamically change in size.
    //             Adding and removing of elements are usually done at the end. Elements can be accessed by index.

    
    // 2. List - list is similar to a vector in that it can store multiple elements of the same type and dynamically grow in size,
    //           However, two major differences between lists and vectors are:
    //             (i).You can add and remove elements from both the beginning and at the end of a list, 
    //                 while vectors are generally optimized for adding and removing at the end.
    //            (ii).Unlike vectors, a list does not support random access, meaning you cannot directly jump to a specific index, 
    //                 or access elements by index numbers.   
    list<int> rowList;
    rowList={3,4,17,3};
    //Accessing Element
    int rowListFront=rowList.front();
    int rowListBack=rowList.back();
    // Change value
    rowList.front()=1;
    rowList.back()=9;
    // Inserting Element
    rowList.push_front(0);
    rowList.push_back(99);
    // Removing Element
    rowList.pop_front();
    rowList.pop_back();
    rowList.erase(rowList.begin());   //takes two values as range first is for the begining and second for the end(end is not included)
    int rowListSize=rowList.size();
    int rowListIsEmpty=rowList.empty();


    // 3. Stack - stack stores multiple elements in a specific order, called LIFO.
    //            Unlike vectors, elements in the stack are not accessed by index numbers. 
    //            Since elements are added and removed from the top, you can only access the element at the top of the stack.
    deque<int> books={2,36,4,63,1,23};
    stack<int> bookStack2;                  //stack container is an adapter that uses another container (like deque by default) to store the elements
    stack<int> bookStack;
    // Inserting Element
    bookStack.push(9);
    // Accessing Element
    int topValue=bookStack.top();
    // Changing Element Value
    bookStack.top()=11;
    // Remove Element
    bookStack.pop();
    int BooksSize=bookStack.size();
    int BooksIsEmpty=bookStack.empty();


    // 4. Queue - queue stores multiple elements in a specific order, called FIFO.
    // Unlike vectors, elements in the queue are not accessed by index numbers. Since queue elements are added at the end and removed from the front, you can only access an element at the front or the back.
    queue<int> lineQueue;
    // Inserting Element
    lineQueue.push(1);
    lineQueue.push(9);
    // Accessing Element
    int lineFront=lineQueue.front();
    int lineBack=lineQueue.back();
    // Changing Element Value
    lineQueue.front()=11;
    lineQueue.back()=9;
    // Remove Element
    lineQueue.pop();
    int lineSize=lineQueue.size();
    int lineIsEmpty=lineQueue.empty();


    // 5. Deque - A double-ended queue/deque is flexible, as elements can be added and removed from both ends. 
    //            You can also access elements by index numbers.
    deque<int> row;
    row={2,3,6};
    //Accessing Element
    int atIdx1=row.at(1);
    int atIdx2=row[2];
    int frontEle=row.front();
    int backEle=row.back();
    // Inserting Element
    row.push_front(1);
    row.push_back(9);
    // Removing Element
    row.pop_front();
    row.pop_back();
    row.erase(row.begin(),row.begin()+1);   //takes two values as range first is for the begining and second for the end(end is not included)
    int rowSize=row.size();
    int rowIsEmpty=row.empty();


    // 6. Priority Queue - Priority queue is specifically designed such that the elements are in increasing(by default) or decreasing order
    //                     (hence we can see that each element of the queue has a priority {fixed order}).
    //                     STL Priority Queues are built on the top of the max heap and use an array or vector as an internal structure.
    //                     It is the implementation of Heap Data Structure.
    priority_queue<int> pq;                                         //Max-Heap
    priority_queue<int,vector<int>,greater<int>> pqMinHeap;         //Min-Heap
    // std::priority_queue is not a container in itself but a container adopter. It wraps other containers like vector,etc.
    // Adding Element
    pq.push(1);
    pq.push(9);
    pq.push(5);
    pq.push(8);
    // Removing Element
    pq.pop();
    // Accessing Element
    int pqTopValue=pq.top();
    int pqSize=pq.size();
    int pqIsEmpty=pq.empty();


    // 7. Set - set stores unique elements and sorted automatically in ascending order(the order can be changed),
    //          Elements can be added or removed, but the value of an existing element cannot be changed.
    //          Elements cannot be accessed by index numbers, because the order is based on sorting and not indexing.
    set<int> members={1,2,63,7,4,71,3,34};                                        //Ascending Order
    set<int, greater<int>> students={1,2,63,7,4,71,3,34};                         //Descending Order
    //Adding Element
    members.insert(21);
    //Removing Element
    members.erase(71);    
    // Check if element exists
    bool memberExists=members.count(21);
    // find()
    //If the element is found, it returns an iterator to its position in the set.
    //If the element is not found, then it returns the iterator to the end.
    set<int>::iterator itr=members.find(21);
    // Remove all elements
    members.clear();
    int membersSetSize=members.size();
    int membersIsEmpty=members.empty();
    
    
    // 8. Map - map stores unique elements in "key/value" pairs.
    //          Elements are accessible by keys (not index), and each key is unique.
    //          Access key and value in a for-each loop using .first to access key and .second to access value

    // (i).Ordered map - Elements are automatically sorted in ascending order by their keys.
    //                   Implemented using Self-Balancing BST
    //                   Time Complexity for Search, Insert, Delete = 0(logn)
    map<string,int> people={{"XYZ",1},{"ABC",2},{"MNO",3}};
    // Accessing Element
    int abcValue=people["ABC"];
    int mnoValue=people.at("MNO");
    // Changing Element Value
    people.at("XYZ")=4;
    //Adding Element
    // if duplicate key is added it will be ignored, and map will keep the first one's value.
    people["DEF"]=5;
    people.insert({"FIJ",8});
    //Removing Element
    people.erase("DEF");
    //Check if the key exists or not
    bool defExists=people.count("DEF");
    // Remove all Elements
    people.clear();

    // (ii). Un-Ordered map - Elements are randomly arranged(no order).
    //                        Implemented using Hash Table
    //                        Time Complexity for search, insert, delete = 0(1) { In worst case it's 0(n) }
    unordered_map<string,int> people2={{"XYZ",1},{"ABC",2},{"MNO",3}};
    // Accessing Element
    int abcValue=people2["ABC"];
    int mnoValue=people2.at("MNO");
    // Changing Element Value
    people2.at("XYZ")=4;
    //Adding Element
    // if duplicate key is added, map will update the key's value.
    people2["ABC"]=5;
    people2.insert({"FIJ",8});
    //Removing Element
    people2.erase("ABC");
    //Check if the key exists or not
    bool defExists=people2.count("DEF");
    //Check if map is empty or not
    bool isEmpty=people2.empty();
    // Remove all Elements
    people2.clear();


    // Iterators
    // Iterators are used to access and iterate through elements of data structures (vectors, sets, etc.), by "pointing" to them.
    // begin(), rbegin(), end() and rend() are functions that belong to data structures
    // begin() returns an iterator that points to the first element of the data structure.
    // end() returns an iterator that points to one position after the last element.
    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
    // Create a vector iterator called "it" and Loop through the vector with the iterator
    vector<string>::iterator it;
    for (it = cars.begin(); it != cars.end(); ++it) {
        cout << *it << "\n";
    }


    // Algorithms = Algorithms are used to solve problems by sorting, searching, and manipulating data structures.

    vector<int> vec={3,46,21,63,4,1,6};
    //binary Search
    bool isNumExists=binary_search(vec.begin(),vec.end(),21);
    // sort
    sort(vec.begin(),vec.end());                                        //ascending order
    // sort(vec.rbegin(),vec.rend());                                      //descending order
    //lower bound - To search for the first element that is lesser than a specific value, you can use the lower_bound()
    auto lowerBound=lower_bound(vec.begin(),vec.end(),21);
    // upper bound - To search for the first element that is greater than a specific value, you can use the upper_bound()
    auto upperBound=upper_bound(vec.begin(),vec.end(),21);
    //rotate(reverse the array/vector)
    rotate(vec.begin(),vec.begin()+2,vec.end());
    // min/max element
    auto minimumVal=min_element(vec.begin(),vec.end());
    auto maximumVal=max_element(vec.begin(),vec.end());
    vector<int> copiedElements;
    //fill()
    fill(copiedElements.begin(),copiedElements.end(),89);
    // copy()
    copy(vec.begin(),vec.end(),copiedElements.begin());
    
    string str="abcd";
    reverse(str.begin(),str.end());


    return 0;
}