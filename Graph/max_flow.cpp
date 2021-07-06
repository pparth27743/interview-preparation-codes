#include<bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int> > &adjmat, vector<int> &parent, int source, int sink){

    int n = adjmat.size();
    parent.resize(n, -1);
    vector<bool> visited(n, false);
    
    parent[source] = -1;
    visited[source] = true;
    queue<int> q;
    q.push(source);
    
    int minflow = INT_MAX;
    
    while(!q.empty()){
        int i = q.front();  q.pop();
        
        for(int j=0; j<n; j++){
            if(visited[j] == false && adjmat[i][j] != 0){
                
                visited[j] = true;
                parent[j] = i;
                q.push(j);
                minflow = min(minflow, adjmat[i][j]);
                
                if(j == sink)
                    return minflow;
                
            }
        }
    }
    return 0;           // means that we are not able find augmented path from source to sink
}


int max_flow(vector<vector<int> > &adjmat){
    
    int n = adjmat.size();
    vector<int> parent(n);
    vector<vector<int> > augmentedPaths;            // stores all the augmented paths
    
    int ans = 0;
    int source = 0;
    int sink = n-1;
    
    while(1){
        int newflow = bfs(adjmat, parent, source, sink);
        
        if(newflow == 0)
            break;
        
        vector<int> augPath;
        
        ans += newflow;
        int curr = sink;
        augPath.push_back(curr);

        while(curr != source){
            int prev = parent[curr];
            adjmat[prev][curr] -= newflow;
            adjmat[curr][prev] += newflow;
            curr = prev;
            augPath.push_back(curr);
        }
        
        reverse(augPath.begin(), augPath.end());
        augmentedPaths.push_back(augPath);
    }
    
    return ans;
}
