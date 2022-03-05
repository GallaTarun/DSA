#include <bits/stdc++.h>
using namespace std;

// ------------------- PROBLEM STATEMENT --------------------
// Given an array ar of size n, and a target sum K,
// Check if there exists any subset of ar, such that
// sum of elements in the subset is equal to K. 
// (return either true or false).
// ----------------------------------------------------------


// Recursive solution
/*
bool subsetWithSumK(int n, vector<int> &ar, int targetSum, int cur) {
    if(targetSum==0)
        return true;
    if(cur==n)
        return targetSum==0;
    if(ar[cur] <= targetSum)
        return subsetWithSumK(n, ar, targetSum-ar[cur], cur+1) || subsetWithSumK(n, ar, targetSum, cur+1);
    return subsetWithSumK(n, ar, targetSum, cur+1);
}
*/


// DP memoization
/*
#define ITEMS 1000
#define SUM 10000

int dp[ITEMS+1][SUM+1];
memset(dp, -1, sizeof(dp));

bool subsetWithSumK(int n, vector<int> &ar, int targetSum, int cur) {
    if(targetSum==0 || cur==0)
        return true;
    if(cur==n)
        return targetSum==0;
    if(dp[cur][targetSum] != -1)
        return dp[cur][targetSum]==1;
    if(ar[cur-1] <= targetSum)
        return dp[cur][targetSum] = subsetWithSumK(n, ar, targetSum-ar[cur-1], cur+1) || subsetWithSumK(n, ar, targetSum, cur+1);
    return dp[cur][targetSum] = subsetWithSumK(n, ar, targetSum, cur+1);
}
*/


// DP Tabulation
bool subsetWithSumK(int n, vector<int> &ar, int targetSum) {
    bool dp[n+1][targetSum+1];
    for(int i=0;i<n+1;i++)
        dp[i][0] = true;
    for(int j=1;j<targetSum+1;j++) 
        dp[0][j] = false;
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<targetSum+1;j++){
            if(ar[i-1] <= targetSum)
                dp[i][j] = dp[i-1][j-ar[i-1]] || dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][targetSum];
}


int main() {
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    
    vector<int> ar(n);
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++)
        cin>>ar[i];
    
    int targetSum;
    cout<<"Enter target sum : ";
    cin>>targetSum;
 
    // Recursive and memoized solution
    // bool exists = subsetWithSumK(n, ar, targetSum, 0);
    
    // Tabulation DP - O(n * targetSum)
    bool exists = subsetWithSumK(n, ar, targetSum);
    cout<< ((exists==1) ? "Exists" : "Doesn't exist") <<endl;
    
    return 0;
}
