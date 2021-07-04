#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
// using pii = pair<int, int>; 


void dfs(int u, vector<bool> &visted, vector<int> &ans, vector<vector<pii> > &adjList){

    visted[u] = true;
    ans.push_back(u);

    for(auto edge  : adjList[u]){
        int v = edge.first;
        if(!visted[v]){
            dfs(v, visted, ans, adjList);
        }
    }
}


void bfs(vector<vector<pii> > &adjList){

    vector<int> ans;
    int n = adjList.size();

    vector<bool> visited(n,false);
    vector<int> d(n), p(n);
    queue<int> q;

    int s = 0;
    visited[s] = true;
    p[s] = -1;
    d[s] = 0;
    q.push(s);


    while(!q.empty()){
        int u = q.front();  q.pop();
        ans.push_back(u);
        
        for(auto edge :  adjList[u]){
            int v = edge.first;
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                d[v] = d[u] + 1;
                p[v] = u;
            }
        }
    }
   
    for(int i : ans)
        cout << i << " ";
    cout << "\n";
    

}


int main(){
  

    vector<vector<pii> > adjList(9);

    adjList[0].push_back(make_pair(1, 4));              // (dest, weight)
    adjList[0].push_back(make_pair(7, 8));
    adjList[1].push_back(make_pair(0, 4));
    adjList[1].push_back(make_pair(2, 8));
    adjList[1].push_back(make_pair(7, 11));
    adjList[2].push_back(make_pair(1, 8));
    adjList[2].push_back(make_pair(3, 7));
    adjList[2].push_back(make_pair(8, 2));
    adjList[2].push_back(make_pair(5, 4));
    adjList[3].push_back(make_pair(2, 7));
    adjList[3].push_back(make_pair(5, 14));
    adjList[3].push_back(make_pair(4, 9));
    adjList[4].push_back(make_pair(3, 9));
    adjList[4].push_back(make_pair(5, 10));
    adjList[5].push_back(make_pair(4, 10));
    adjList[5].push_back(make_pair(3, 14));
    adjList[5].push_back(make_pair(2, 4));
    adjList[5].push_back(make_pair(6, 2));
    adjList[6].push_back(make_pair(5, 2));
    adjList[6].push_back(make_pair(8, 8));
    adjList[6].push_back(make_pair(7, 1));
    adjList[7].push_back(make_pair(6, 1));
    adjList[7].push_back(make_pair(8, 7));
    adjList[7].push_back(make_pair(1, 11));
    adjList[7].push_back(make_pair(0, 8));
    adjList[8].push_back(make_pair(7, 8));
    adjList[8].push_back(make_pair(2, 2));
    adjList[8].push_back(make_pair(6, 6));

    bfs(adjList);

    int n = adjList.size();
    vector<int> ans;
    vector<bool> visited(n, false);

    dfs(0, visited, ans, adjList);

    for(int i : ans)
        cout << i << " ";
    cout << "\n";
    

    return 0;
}




