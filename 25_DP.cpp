#include<iostream>
#include<vector>
using namespace std;

// DP is to store solutions to subproblems so that each is solved only once.
// To make sure that a recursive value is computed only once, we store results of the recursive calls.
// 2 ways to store the results,
//       (i). top down (or memoization)
//      (ii). bottom up (or tabulation)

// Time Complexity=0(n), Space Complexity=0(n)
int fibonacciMemoUtil(int n,vector<int> &dp){
    if(n==0 || n==1){
        return 1;
    }
    if(dp[n]==-1){
        dp[n]=fibonacciMemoUtil(n-1,dp) + fibonacciMemoUtil(n-2,dp);
    }
    return dp[n];
}
int fibonacciMemo(int n){
    vector<int> dp(n+1,-1);
    return fibonacciMemoUtil(n,dp);
}

// Time Complexity=0(n), Space Complexity=0(1)
int fibonacciTab(int n){
    int res=1;
    int prev1=1, prev2=1;
    for(int i=2;i<=n;i++){
        res=prev1+prev2;
        prev1=prev2;
        prev2=res;
    }
    return res;
}

// Time Complexity=0(n*capacity), Space Complexity=0(n*capacity)
int knapsackMemoUtil(vector<pair<int,int>> &items,int idx,int capacity,vector<vector<int>> dp){
    if(idx==0){
        if(items[idx].first<=capacity){
            return items[idx].second;
        }else{
            return 0;
        }
    }
    if(dp[idx][capacity]==-1){
        int include=(items[idx].first<=capacity)?items[idx].second+knapsackMemoUtil(items,idx-1,capacity-items[idx].first,dp):0;
        int exclude=knapsackMemoUtil(items,idx-1,capacity,dp);
        dp[idx][capacity]=max(include,exclude);
    }
    return dp[idx][capacity];
}
int knapsackMemo(vector<pair<int,int>> &items,int capacity){
    int n=items.size();
    vector<vector<int>> dp(n,vector<int>(capacity+1,-1));       // 2-dimensional vector
    return knapsackMemoUtil(items,n-1,capacity,dp);
}

// Time Complexity=0(n*capacity), Space Complexity=0(n*capacity)
int knapsackTab(vector<pair<int,int>> &items,int capacity){
    int n=items.size();
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));

    //base case
    for(int w=items[0].first;w<=capacity;w++){
        dp[0][w]=(items[0].first<=capacity)?items[0].second:0;
    }

    for(int idx=1;idx<n;idx++){
        for(int w=0;w<=capacity;w++){
            int include=(items[idx].first<=w)?items[idx].second+dp[idx-1][w-items[idx].first]:0;
            int exclude=dp[idx-1][w];
            dp[idx][w]=max(include,exclude);
        }
    }

    return dp[n-1][capacity];
}

// Time Complexity=0(n*capacity), Space Complexity=0(capacity)
int knapsackTab2(vector<pair<int,int>> &items,int capacity){
    int n=items.size();
    vector<int> prev(capacity+1,0);
    vector<int> cur(capacity+1,0);

    for(int w=items[0].first;w<=capacity;w++){
        prev[w]=(items[0].first<=capacity)?items[0].second:0;
    }

    for(int idx=1;idx<n;idx++){
        for(int w=0;w<=capacity;w++){
            int include=(items[idx].first<=w)?items[idx].second+prev[w-items[idx].first]:0;
            int exclude=prev[w];
            cur[w]=max(include,exclude);
        }
        prev=cur;
    }
    return prev[capacity];
}

int main(){
    //fibonacci series
    int n=5;
    cout<<"Fibonacci Element at "<<n<<" (Memoization) : "<<fibonacciMemo(n)<<endl;
    cout<<"Fibonacci Element at "<<n<<" (Tabulation) : "<<fibonacciTab(n)<<endl;

    //knapsack
    vector<pair<int,int>> items={{1,5},{2,3},{3,1},{4,8},{5,8}};    // Pair: first-weight, second-value
    int capacity=10;
    cout<<"Max Valued items that can be included in "<<capacity<<" capacity : "<<endl;
    cout<<"Knapsack Memoization : "<<knapsackMemo(items,capacity)<<endl;
    cout<<"Knapsack Tabulation : "<<knapsackTab(items,capacity)<<endl;
    cout<<"Knapsack Tabulation2 : "<<knapsackTab2(items,capacity)<<endl;

    return 0;
}