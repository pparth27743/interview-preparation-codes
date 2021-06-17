/*
Given string in e.g. 'a1B2' return following. 

'a1b2' 
'a1B2' 
'A1b2' 
'A1B2' 

*/


#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void solve(string s, int i, string &tmp){
    if(i == s.size()){
        ans.push_back(tmp);
        return;
    }

    if(isalpha(s[i])){
        // with smaller case
        tmp.push_back(tolower(s[i]));
        solve(s, i+1, tmp);
        tmp.pop_back();

        //with uppercase
        tmp.push_back(toupper(s[i]));
        solve(s, i+1, tmp);
        tmp.pop_back();
    }
    else{
        tmp.push_back(s[i]);
        solve(s, i+1, tmp);
        tmp.pop_back();
    }

}

int main() {

    string s = "a1B2";

    string tmp = "";
    solve(s, 0, tmp);

    for(auto v : ans){
        cout << "'";
        for(auto i : v)     cout << i;
        cout << "' \n";
    }

    return 0;
}
