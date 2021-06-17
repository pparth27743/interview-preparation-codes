#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void solve(string s, int i, string &tmp){
    if(i == s.size()){
        ans.push_back(tmp);
        return;
    }

    if(i == 0){
        tmp.push_back(s[i]);
        solve(s, i+1, tmp);
        tmp.pop_back();
    }
    else{
        // with space 
        tmp.push_back(' ');
        tmp.push_back(s[i]);
        solve(s, i+1, tmp);
        tmp.pop_back();
        tmp.pop_back();

        // without space
        tmp.push_back(s[i]);
        solve(s, i+1, tmp);
        tmp.pop_back();
    }
}

int main() {

    string s = "ABCD";

    string tmp = "";
    solve(s, 0, tmp);

    for(auto v : ans){
        cout << "'";
        for(auto i : v)     cout << i;
        cout << "' \n";
    }

    return 0;
}
