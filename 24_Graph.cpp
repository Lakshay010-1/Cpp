#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

// Graphs are non-linear data structures, defined as a collection of vertices and edges

template<typename T>
class GraphM{
    private:
    // Adjacency Matrix
    T **edges;
    int direction;
    int totalNodes;
    public:
    GraphM():direction(0),edges(nullptr),totalNodes(0){}
    GraphM(int n,int direction=0){
        this->totalNodes=n+1;
        this->direction=direction;
        edges=new T*[n];
        fill(edges[0],edges[0]+n,0);
    }
    ~GraphM(){
        for(int i=0;i<totalNodes;i++){
            delete [] edges[i];
        }
        delete edges;
        cout<<"Memory Freed"<<endl;
    }
    void printEdges(){
        for(int i=0;i<totalNodes;i++){
            cout<<i<<" -> ";
            for(int j=0;j<totalNodes;j++){
                if(edges[i][j]==1){
                    cout<<j<<", ";
                }
            }
            cout<<endl;
        }
    }
    bool addEdge(T i,T j){
        if(i>totalNodes || j>totalNodes){
            return false;
        }
        edges[i][j]=1;
        if(direction==1){
            edges[j][i]=1;
        }
        return true;
    }
};

template<typename T>
class GraphL{
    private:
    // Adjacency List
    unordered_map<T,list<T>> edges;
    int direction;

    //Breath-First Search
    // Time Complexity=0(V+E), Space Complexity=0(V)
    void bfsTraversalUtil(T src,unordered_map<T,bool> &vis){
        queue<T> q;
        q.push(src);

        while(!q.empty()){
            T cur=q.front();
            q.pop();

            if(!vis[cur]){
                vis[cur]=true;
                cout<<cur<<", ";
                for(T dest:edges[cur]){
                    q.push(dest);
                }
            }
        }
    }
    
    // Depth-First Search
    // Time Complexity=0(V+E), Space Complexity=0(V)
    void dfsTraversalUtil(T cur,unordered_map<T,bool> &vis){
        vis[cur]=true;
        cout<<cur<<", ";
        for(T dest:edges[cur]){
            if(!vis[cur]){
                dfsTraversalUtil(dest,vis);
            }
        }        
    }
    
    // Detect Cycle in a Bi-directed graph using BFS
    // Time Complexity=0(V+E), Space Complexity=0(V)
    bool detectCycleBfsBi(T src,unordered_map<T,bool> &vis){
        unordered_map<T, T> parent;
        queue<T> q;

        vis[src]=true;
        parent[src]=-1;
        q.push(src);
        while(!q.empty()){
            T cur=q.front();
            q.pop();
            for(T neighbour:edges[cur]){
                if(vis[neighbour]){
                    if(parent[cur]!=neighbour){
                        return true;
                    }
                }else{
                    vis[neighbour]=true;
                    q.push(neighbour);
                    parent[neighbour]=cur;
                }
            }
        }
        return false;
    }
    
    // Detect Cycle in a Uni-directed graph using BFS
    // Time Complexity=0(V+E), Space Complexity=0(V)
    bool detectCycleBfsUni(){
        int n=edges.size();
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(T neighbour:edges[i]){
                indegree[neighbour]++;
            }
        }

        queue<T> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            count++;

            for(T neighbour:edges[cur]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        return count!=n;
    }  
    
    // Detect Cycle in a Bi-directed graph using DFS
    // Time Complexity=0(V+E), Space Complexity=0(V)
    bool detectCycleDfsBi(T src,unordered_map<T,bool> &vis,T parent){
        vis[src]=true;
        for(T neighbour:edges[src]){
            if (!vis[neighbour]) {
                if (detectCycleDfsBi(neighbour, vis, src)) {
                    return true;
                }
            } else if (neighbour != parent) {
                return true;
            }
        }
        return false;
    }
    
    // Detect Cycle in a Uni-directed graph using DFS
    // Time Complexity=0(V+E), Space Complexity=0(V)
    bool detectCycleDfsUni(T src,unordered_map<T,bool> &vis,unordered_map<T,bool> &dfsStack){
        vis[src]=true;
        dfsStack[src]=true;
        for(T neighbour:edges[src]){
            if(!vis[neighbour]){
                if(detectCycleDfsUni(neighbour,vis,dfsStack)){
                    return true;
                }
            }else if( dfsStack[neighbour]){
                return true;
            }
        }
        dfsStack[src]=false;
        return false;
    }

    public:
    GraphL(int dir=0){
        this->direction=dir;
    }
    ~GraphL(){
        edges.clear();
        cout<<"Memory Freed"<<endl;
    }
    
    // Print graph type
    // Time Complexity=0(1), Space Complexity=0(1)
    void getGraphType(){
        cout<<((direction==0)?"Uni":"Bi")<<"-Directed Graph"<<endl;
    }

    // Add Edge in a graph
    // Time Complexity=0(1), Space Complexity=0(1)
    bool addEdge(T i,T j){
        edges[i].push_back(j);
        if(direction==1 && i!=j){
            edges[j].push_back(i);
        }
        return true;
    }
    
    // Print Edges in the graph
    // Time Complexity=0(V+E), Space Complexity=0(1)
    void printEdges(){
        cout<<"Edges : "<<endl;
        for(auto edge:edges){
            cout<<edge.first<<" -> ";
            for(T dest:edge.second){
                cout<<dest<<", ";
            }
            cout<<endl;
        }
    }
    
    // BFS Dis-connected components
    // Time Complexity=0(V+E), Space Complexity=0(V)
    void bfsTraversal(){
        unordered_map<T,bool> vis;
        for(int i=0;i<edges.size();i++){
            if(!vis[i]){
                bfsTraversalUtil(i,vis);
            }
        }
        cout<<"end"<<endl;
    }
    
    // DFS Dis-connected components
    // Time Complexity=0(V+E), Space Complexity=0(V)
    void dfsTraversal(){
        unordered_map<T,bool> vis;
        for(int i=0;i<edges.size();i++){
            if(!vis[i]){
                dfsTraversalUtil(i,vis);
            }
        }
        cout<<"end"<<endl;
    }
    
    // Detect Cycle using BFS
    // Time Complexity=0(V+E), Space Complexity=0(V)
    bool detectCycleBfs(){
        if(direction==1){
            unordered_map<T,bool> vis;
            for(int i=0;i<edges.size();i++){
                if(!vis[i]){
                    if(detectCycleBfsBi(i,vis)){
                        return true; 
                    }
                }
            }
        }else{
            return detectCycleBfsUni();
        }
        return false;
    }
    
    // Detect Cycle using DFS
    // Time Complexity=0(V+E), Space Complexity=0(V)
    bool detectCycleDfs(){
        unordered_map<T,bool> vis;
        for(int i=0;i<edges.size();i++){
            if(!vis[i]){
                bool con;
                if(direction==0){
                    unordered_map<T,bool> dfsStack;
                    con=detectCycleDfsUni(i,vis,dfsStack);
                }else{
                    con=detectCycleDfsBi(i,vis,-1);
                }
                if(con){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    // direction :- 0 = uni-directional(default), 1 = bi-directional
    int direction=0;

    GraphL<int> *graph=new GraphL<int>(direction);
    int edges[][2]={{0,1},{1,2},{0,2}};
    for(int i=0;i<sizeof(edges)/sizeof(edges[i]);i++){
        graph->addEdge(edges[i][0],edges[i][1]);
    }
    graph->getGraphType();
    graph->printEdges();
    cout<<"\nBFS : ";
    graph->bfsTraversal();
    cout<<"\nDFS : ";
    graph->dfsTraversal();
    cout<<"\nis there cycle(BFS): ";
    cout<<graph->detectCycleBfs()<<endl;
    cout<<"\nis there cycle(DFS): ";
    cout<<graph->detectCycleDfs()<<endl;
    
    cout<<endl;
    delete graph;
    return 0;
}