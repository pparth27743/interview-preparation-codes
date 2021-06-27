#include <bits/stdc++.h>
using namespace std;


string solve(string s, string t) {
    
    int n = s.size();
    int i=0, j=0;
    unordered_map<char, int> mp;
    int left = -1, right = -1;
    int ans = INT_MAX;
    
    for(char ch : t)
        mp[ch]++;
    
    int count = mp.size();
    
    while(j<n){
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if(mp[s[j]] == 0)
                count--;
        }
        
        if(count == 0){
            while(count == 0){
                if(ans > j-i+1){
                    ans = j-i+1;
                    left = i;
                    right = j;
                }
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1)
                        count++;
                }
                i++;
            }
        }
        j++;
    }
    
    if(ans == INT_MAX)
        return "";
    
    return s.substr(left, right-left+1);
}


int main() {

    string s = "btottoctt";
    string t = "ttc";

    cout << solve(s,t) << endl;

    return 0;
}