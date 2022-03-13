#include <bits/stdc++.h>
using namespace std;

// ------------------- PROBLEM STATEMENT --------------------
// Given an array ar of size n, 
// Find the count of subsets of the array whose sum is equal to k.
// ----------------------------------------------------------

int countSubsetsWithSumK(vector<int>&ar, int n, int k) {
    int dp[n+1][k+1];
    for(int i=0;i<n+1;i++)
        dp[i][0] = 1;
    for(int j=1;j<k+1;j++)
        dp[0][j] = 0;
    
    for(int i=1;i<n+1;i++){
        for(int j=0;j<k+1;j++){
            if(ar[i-1] <= j)
                dp[i][j] = dp[i-1][j-ar[i-1]] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[n][k];
}


int main() {
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    
    vector<int> ar(n);
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++)
        cin>>ar[i];
    
    int k;
    cout<<"Enter sum : ";
    cin>>k;
    
    int result = countSubsetsWithSumK(ar,n,k);
    cout<<result<<endl;
    
    return 0;
}
