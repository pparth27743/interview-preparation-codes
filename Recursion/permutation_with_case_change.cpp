/*
Given string in small letters ex. 'abc' return following. 

'abc' 
'abC' 
'aBc' 
'aBC' 
'Abc' 
'AbC' 
'ABc' 
'ABC'
*/


#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void solve(string s, int i, string &tmp){
    if(i == s.size()){
        ans.push_back(tmp);
        return;
    }

    //without case change 
    tmp.push_back(s[i]);
    solve(s, i+1, tmp);
    tmp.pop_back();

    //with case change 
    tmp.push_back(toupper(s[i]));
    solve(s, i+1, tmp);
    tmp.pop_back();
    
}

int main() {

    string s = "abc";

    string tmp = "";
    solve(s, 0, tmp);

    for(auto v : ans){
        cout << "'";
        for(auto i : v)     cout << i;
        cout << "' \n";
    }

    return 0;
}
