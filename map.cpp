#include <bits/stdc++.h>
using namespace std;

int main(){
    
    map<int, int> m;
    
    m.insert(pair<int, int> (1,44));
    m.insert(pair<int, int> (2,43));
    m.insert(pair<int, int> (3,34));
    m.insert(pair<int, int> (4,44));
    m.insert(pair<int, int> (5,74));
    m.insert(pair<int, int> (6,54));
    m.insert(pair<int, int> (7,47));
    
    cout << "K  V \n";
    for(auto i = m.begin(); i != m.end(); i++)
        cout << i->first << " " << i->second << endl;
    
    
    return 0;
}
