#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
// using pii = pair<int, int>; 


void dijkstra(vector<vector<pii> > adjList){

    int n = adjList.size();

    vector<bool> explored(n, false);
    vector<int> d(n, INT_MAX);
    vector<int> p(n, -1);

    priority_queue<pii, vector<pii>, greater<pii> > pq;

    int s = 0;
    d[s] = 0;

    pq.push(make_pair(d[s], s));

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        
        if(explored[u]) 
            continue;

        explored[u] = true;

        for(auto edge : adjList[u]){
            int v = edge.first;
            int w = edge.second;

            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                p[v] = u;
                pq.push(make_pair(d[v], v));
            }
        }
    }

    for(int i : d)
        cout << i << " "; 

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    vector<vector<pii> > adjList(9);

    adjList[0].push_back(make_pair(1, 4));
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

    dijkstra(adjList);
    

    return 0;
}




