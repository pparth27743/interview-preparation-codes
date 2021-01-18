
#include<bits/stdc++.h>
using namespace std;

class DisJointSetUnion{
  
  int n, *parent, *rank;
  
  public:
  
  DisJointSetUnion(int n){
      
      parent = new int[n];
      rank = new int[n];
      this->n = n;
      
      for(int i=0; i<n; i++)
        make_set(i);
  }
  
  void make_set(int v){
      parent[v] = v;
      rank[v] = 0;
  }
  
  int find_set(int v){
      
      if(v == parent[v])
        return v;
        
    return parent[v] = find_set(parent[v]);
  }
    

    void union_set(int a,  int b){
        
        a = find_set(a);
        b = find_set(b);
        
        if(a == b)
            return;
            
        if(rank[a] < rank[b])
            parent[a] = b;
            
        else if(rank[a] > rank[b])
            parent[b] = a;
        
        else{
            parent[b] = a;
            rank[a]++;
        }
    }

    // void print(){
    //     for(int i=1; i<n; i++)
    //         cout << parent[i] << " ";
    //     cout << "\n";
    // }

};


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    using pii = pair<int, int>;

    vector<pii> close, build;


    int n; cin >> n;
    
    int u, v;

    DisJointSetUnion dsu(n+1);
    
    for(int i=0; i<n-1; i++){
        cin >> u >> v;
        if(dsu.find_set(u) == dsu.find_set(v))
            close.push_back(make_pair(u, v));
        else
            dsu.union_set(u, v);
    }

    for(int i=2; i<=n; i++){
        if(dsu.find_set(1) != dsu.find_set(i)){
            build.push_back(make_pair(1,i));
            dsu.union_set(1, i);
        }
    }
    

    cout << close.size() << "\n";
    for(int i=0; i<close.size(); i++){
        cout << close[i].first << " " << close[i].second << " ";
        cout << build[i].first << " " << build[i].second << "\n";
    }
       
    return 0;
}
