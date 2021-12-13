#include<bits/stdc++.h>
using namespace std;


bool hasPath(int** edges,int n, int start, int end, bool* visited){
    if(start==end)
        return true;
    visited[start] = true;
    for(int i=0;i<n;i++){
        if(edges[start][i] && !visited[i]){
            return hasPath(edges,n,i,end,visited);
        }
    }
    return false;
}

void bfs(int** edges,int n,int start_vertex,bool* visited){
    queue<int> q;
    q.push(start_vertex);
    visited[start_vertex] = true;
    while(!q.empty()){
        int cur_vertex = q.front();
        q.pop();
        cout<<cur_vertex<<" ";
        for(int i=0;i<n;i++){
            if(edges[cur_vertex][i]==1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void printBFS(int** edges,int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(edges,n,i,visited);
        }
    }
}

// dfs traversal
void dfs(int** edges, int n, int start_vertex,bool* visited){
    cout<<start_vertex<<endl;
    visited[start_vertex] = true;
    for(int i=0;i<n;i++){
        if(i==start_vertex)
            continue; 
        if(edges[start_vertex][i] && !visited[i]){
            dfs(edges,n,i,visited);   
        }
    }
}

void printDFS(int** edges, int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(edges,n,i,visited);
    }
}

// dfs1 function to return a connected component
void dfs1(int** edges, int n, int start,vector<int>& component,bool* visited){
    component.push_back(start);
    visited[start] = true;
    for(int i=0;i<n;i++){
        if(i==start)
            continue; 
        if(edges[start][i] && !visited[i]){
            dfs1(edges,n,i,component,visited);   
        }
    }
}

// function to return all connected components
vector<vector<int>> getConnectedComponents(int** edges,int n){
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    vector<vector<int>> res;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int> component;
            dfs1(edges,n,i,component,visited);
            res.push_back(component);
        }
    }
    return res;
}

int dfs2(int** mat,int n,int row,int col,bool** visited){
    if(row>=n || row<0 || col<0 || col>=n) 
        return 0;
    visited[row][col] = true; 
    if(mat[row][col]==0)
        return 0;
    return 1+dfs2(mat,n,row+1,col,visited)+dfs2(mat,n,row-1,col,visited)+dfs2(mat,n,row,col+1,visited)+dfs2(mat,n,row,col-1,visited);
}

int largestIsland(int** mat,int n){
    bool** visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[n];
        for(int j=0;j<n;j++){
            visited[i][j] = false;
        }
    }
    int max_size = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1 && !visited[i][j]){
                int size = 1;
                size = dfs2(mat,n,i,j,visited);
                if(max_size<size)
                    max_size = size;
            }
        }
    }
    return max_size;
}


// vector<int> getPath(int** edges,int n,int start,int end,bool* visited){
//     if(start==end){
//         visited[end] = true;
//         return {end};
//     }
//     for(int i=0;i<n;i++){
//         if(start!=i && edges[start][i] && !visited[i]){
//             visited[i] = true;
//             vector<int> sub_path = getPath(edges,n,i,end,visited);
//             if(!sub_path.empty()){
//                 sub_path.insert(sub_path.begin(),i);
//                 return sub_path;
//             }
//         }
//     }
//     return {};
// }


int main(){
    int n,e;
    cout<<"Enter num of vertices : ";
    cin>>n;
    cout<<"Enter num of edges : ";
    cin>>e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    int f,s;
    for(int i=0;i<e;i++){
        cout<<"Enter edge "<<i+1<<" : ";
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
        
    // print the graph - dfs traversal
    printDFS(edges,n);
    
    // bfs traversal
    printBFS(edges,n);
    
    // for(int i=0;i<n;i++)
    //     visited[i] = false;
    cout<<"\nHas path : ";
    cout<<hasPath(edges,n,2,4,visited)<<" ";
    cout<<hasPath(edges,n,6,7,visited)<<endl;
    for(int i=0;i<n;i++)
        visited[i] = false;
    // cout<<"Path from 4 to 7";
    // vector<int> res = getPath(edges,n,4,7,visited);
    // for(int val:res){
    //     cout<<val<<" ";
    // }cout<<endl;
    
    vector<vector<int>> res = getConnectedComponents(edges,n);
    cout<<"Connected components ->"<<endl;
    for(auto comp:res){
        for(int val:comp){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    
    int **mat = new int*[4];
    for(int i=0;i<4;i++)
        mat[i] = new int[4];
    cout<<"Enter matrix input ->"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>mat[i][j];
        }
    }
    cout<<"largest Island = ";
    cout<<largestIsland(mat,4)<<endl;
    // delete all the memory
    delete edges;
    delete visited;
    return 0;
}
