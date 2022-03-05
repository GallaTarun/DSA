#include<bits/stdc++.h>
using namespace std;

// ------------------- PROBLEM STATEMENT --------------------
// Given an array ar of size n, 
// Return true if ar can be divided into two partitions,
// such that the sum of elements are equal in both the partitions
// or else, return false.
// ----------------------------------------------------------

bool subsetWithSumK(vector<int> &ar, int n, int sum){
    // a function for checking if there exists a subset of the input array,
    // such that the sum of elements will be equal to 'sum'.
    bool dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
        dp[i][0] = true;
    for(int j=1;j<sum+1;j++)
        dp[0][j] = false;
    
    // dp[i][j] => true, if there is a subset of the subarray ar[0...i] forming a sum of j. False otherwise.
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(ar[i-1]<=j)
                dp[i][j] = (dp[i-1][j-ar[i-1]] || dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}


bool equalSumPartition(vector<int> &ar, int n){
    int arraySum = 0;
    for(int x:ar)
        arraySum += x;
    // if the array sum is odd, there is no possibility to divide
    // the array into 2 partitions of equal sum. so, return false.
    if(arraySum%2==1)
        return false;
    // if the sum is even, then if there is a subset with sum 'arraySum/2',
    // then the second partition can be also formed by the remaining elements,
    // which also has the sum equal to the first partition.
    return subsetWithSumK(ar,n,arraySum/2);
}

int main(){
    int n;
    cout<<"Enter array size : ";
    cin>>n;
    
    vector<int> ar(n);
    cout<<"Enter array elements : ";
    for(int i=0;i<n;i++)
        cin>>ar[i];
    
    bool result = equalSumPartition(ar,n);
    cout<<result<<endl;
    
    return 0;
}
