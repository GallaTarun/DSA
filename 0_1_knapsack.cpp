// ********** PROBLEM DESCRIPTION *************
// There are n items, each item has a weight and a value(price).
// There is a Knapsack(a bag) of capacity W kg.
// We have to put the items such that the weights of items in the bag should be less than or equal to the knapsack capacity.
// What will the maximum profit obtained ?
// ********************************************


#include <bits/stdc++.h>
using namespace std;

#define ITEMS 1000 
#define CAPACITY 1000
int dp[ITEMS+1][CAPACITY+1];

// recursive solution
int knapsack(vector<int>& weights, vector<int>& values, int capacity, int items){
    // if there are 0 items or capacity is 0, profit will be 0.
    if(items==0 || capacity==0)
        return 0;
    if(weights[items-1]<=capacity)
        return max(values[items-1]+knapsack(weights, values, capacity-weights[items-1], items-1), knapsack(weights, values, capacity, items-1));
    return knapsack(weights, values, capacity, items-1);
}

// DP solution
int dpKnapsack(vector<int>& weights, vector<int>& values, int capacity, int items){
    if(items==0 || capacity==0)
        return 0;
    if(dp[items][capacity]!=-1)
        return dp[items][capacity];
    if(weights[items-1]<=capacity)
        return dp[items][capacity] = max(values[items-1]+dpKnapsack(weights, values, capacity-weights[items-1], items-1), dpKnapsack(weights, values, capacity, items-1));
    return dp[items][capacity] = dpKnapsack(weights, values, capacity, items-1);
}


int main() {
    int items;
    cout<<"Enter no.of items : ";
    cin>>items;
    
    vector<int> weights(items);
    cout<<"Enter the weights of items : ";
    for(int i=0;i<items;i++)
        cin>>weights[i];
        
    vector<int> values(items);
    cout<<"Enter the values of the items : ";
    for(int i=0;i<items;i++)
        cin>>values[i];
    
    int capacity;
    cout<<"Enter knapsack capacity : ";
    cin>>capacity;   
        
        
    memset(dp,-1,sizeof(dp));
    // int maxProfit = knapsack(weights, values, capacity, items); // Recursive solution
    // cout<<"Maximum profit in the knapsack = "<<maxProfit<<endl;
    
    int dpProfit = dpKnapsack(weights, values, capacity, items); // DP solution
    cout<<"Maximum profit in the knapsack = "<<dpProfit<<endl;
    
    return 0;
}
