#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

// The principle of greedy algorithms is that the local optimum may lead to the global optimum.

// Time Complexity=0(n.logn), Space Complexity=0(1)
int minCoins(vector<int> &coins, int amount){
    int n = coins.size();
    sort(coins.begin(), coins.end());
    int coinCount = 0;

    for (int i = n - 1; i >= 0; i--){
        if (amount >= coins[i]){
            int cnt = (amount / coins[i]);
            coinCount += cnt;
            amount -= (cnt * coins[i]);
        }

        // Break if there is no amount left
        if (amount == 0)
            break;
    }
    return coinCount;
}

bool comparator(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}

// Time Complexity=0(n.logn), Space Complexity=0(n)
int maxMeetings(int *start,int *end,int n){
    vector<pair<int,int>> vec;

    for(int i=0;i<n;i++){
        pair<int,int> p=make_pair(start[i],end[i]);
        vec.push_back(p);
    }
    sort(vec.begin(),vec.end(),comparator);

    int count=1, ansEnd=vec[0].second;
    for(int i=1;i<n;i++){
        if(vec[i].first > ansEnd){
            count++;
            ansEnd=vec[i].second;
        }
    }

    return count;
}

// Time Complexity=0(1), Space Complexity=0(1)
int minimumDays(int s,int n,int m){
    int sunday=s/7;

    int buyingDays=s-sunday;
    int totalFood=s*m;
    int ans=0;

    ans = (totalFood/n) + ((totalFood % n == 0)?0:1);
    if(ans>buyingDays){
        return -1;
    }
    return ans;
}

int main(){

    // Minimum Coins
    vector<int> coins={1,5,2,10,20};
    int amount=50;
    cout<<"Minimum coins needed for Rs."<<amount<<" -> "<<minCoins(coins,amount)<<endl;

    // Max meetings
    int start[]={1, 3, 0, 5, 8, 5};
    int end[]={2, 4, 6, 7, 9, 9};
    int meetings=sizeof(start)/sizeof(start[0]);
    cout<<"Max Meetings possible -> "<<maxMeetings(start,end,meetings)<<endl;

    // Check if it is possible to survive on Island
    int n=20, m=30, s=10;
    // n = Maximum food units that can be bought per day.
    // m = Food units needed per day.
    // s = Total number of survival days.
    cout<<"Minimum days survival possible on island -> "<<minimumDays(s,n,m)<<endl;

    return 0;
}