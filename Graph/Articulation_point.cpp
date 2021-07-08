#include <bits/stdc++.h>
using namespace std;

int timer = 0;

void dfs(vector<vector<int> > &adjlist, int u, int par, vector<bool> &vis, vector<int> &timein, vector<int> &low, vector<bool> &articulation){
    vis[u] = true;
    timein[u] = low[u] = timer++;
    
    int child = 0;

    for(int v : adjlist[u]){
        if(v == par)    continue;
        if(!vis[v]){
            child++;
            dfs(adjlist, v, u, vis, timein, low, articulation);
            low[u] = min(low[u], low[v]);
            if(par != -1 && low[v] >= timein[u])
                articulation[u] = true;
        }
        else
            low[u] = min(low[u], timein[v]);
    }

    if(par == -1 && child > 1)
        articulation[u] = true;

}


int main(){
  
    int n = 8;
    vector<vector<int> > adjList(n);
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[0].push_back(3);

    adjList[1].push_back(0);
    adjList[1].push_back(2);
    adjList[1].push_back(5);

    adjList[2].push_back(1);
    adjList[2].push_back(0);

    adjList[3].push_back(0);
    adjList[3].push_back(4);

    adjList[4].push_back(3);
    
    adjList[5].push_back(1);
    adjList[5].push_back(6);
    adjList[5].push_back(7);

    adjList[6].push_back(5);
    adjList[6].push_back(7);

    adjList[7].push_back(5);
    adjList[7].push_back(6);


    timer = 0;
    vector<bool> vis(n, false), articulation(n, false);
    vector<int> timein(n, -1), low(n, -1);

    for(int i=0; i<n; i++){
        if(vis[i] == false) 
            dfs(adjList, i, -1, vis, timein, low, articulation);
    }

    cout << "Articulation Points: ";
    for(int i=0; i<n; i++){
        if(articulation[i])
            cout << i << " ";
    }
    cout << endl;

    return 0;
}




