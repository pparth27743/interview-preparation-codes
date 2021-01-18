#include <bits/stdc++.h>
using namespace std;


class DisJointSet {

    int *rank, *parent, n;

    public:

    DisJointSet(int n){
        rank = new int[n];
        parent = new int[n];
        this->n = n;

        for(int i=0; i<n; i++)
            make_set(i);
    }

    void make_set(int v){
        parent[v] = v;
        rank[v] = 0;
    }

    // Path Compression is Implementated
    int find_set(int v){

        if(parent[v] == v)
            return v;

        return parent[v] = find_set(parent[v]);
    }

    // Uinon by Rank
    void union_set(int a, int b){

        a = find_set(a);
        b = find_set(b);

        if(a != b){
            if(rank[a] < rank[b])
                parent[a] = b;
            else if(rank[b] < rank[a])
                parent[b] = a;
            else{
                parent[b] = a;
                rank[a]++;
            }
        }

    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    int n = 5;

    DisJointSet dsu(n);

    dsu.union_set(0,1);
    dsu.union_set(2,3);
    dsu.union_set(4,1);
    dsu.union_set(3,4);

    for(int i=0; i<n; i++)
        cout << dsu.find_set(i) << " ";


    cout << endl;







               

}