#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > ans;

int solve(string txt, string pat){

    unordered_map<char, int> mp;

    for(char ch : pat)                          mp[ch]++;
    for(auto i=mp.begin(); i!=mp.end(); i++)    i->second++;

    int n=txt.size(), k=pat.size();
    int i=0, j=0;
    int count=mp.size(), ans=0;


    while(j<n){
        if(mp.find(txt[j]) != mp.end()){
            mp[txt[j]]--;
            if(mp[txt[j]] == 1)
                count--;
        }

        if(j-i+1 < k)
            j++;
        else if(j-i+1 == k){
            
            if(count == 0)
                ans++;
            
            if(mp.find(txt[i]) != mp.end()){
                mp[txt[i]]++;
                if(mp[txt[i]] == 2)
                    count++;
            }

            i++; j++;
        }
    }
    return ans;
}


int main() {

    string txt = "forxforforxorfxdofr", pat = "for";

    cout << solve(txt, pat) << endl;

    return 0;
}