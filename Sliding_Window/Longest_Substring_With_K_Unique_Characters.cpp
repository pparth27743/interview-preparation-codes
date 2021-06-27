#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > ans;

int solve(string s, int k){

    int ans = 0;
    int n = s.size();
    int i = 0, j = 0;
    unordered_map<char, int> mp;

    while(j < n){
        mp[s[j]]++;
        
        if(mp.size() < k)
            j++;
        else if(mp.size() == k){
            ans = max(ans, j-i+1);
            j++;
        }
        else{
            while(mp.size() > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }

            // Even if I don't write this condition code would works perfectly. 
            // Because here even if mp.size() = k, the answer we are looking for is longest substing that 
            // can't occur here as we are doing i++.
            
            if(mp.size() == k)
                ans = max(ans, j-i+1);
            
            j++;
        }
    }

    return ans;
}

int main() {

    string s = "aabacbebebe";
    int k = 3;

    cout << solve(s, k) << endl;

    return 0;
}