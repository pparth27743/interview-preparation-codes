#include <bits/stdc++.h>
using namespace std;


int solve(string s) {
    
    int n = s.size();
    int i=0, j=0;
    int ans = 0;
    unordered_map<char, int> mp;
    
    while(j<n){
        mp[s[j]]++;
        
        if(mp.size() == j-i+1){
            ans = max(ans, j-i+1);
            j++;
        }
        else{
            while(mp.size() < j-i+1){
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    
    return ans;
    
}

int main() {

    string s = "aabacbebebe";
    int k = 3;

    cout << solve(s) << endl;

    return 0;
}