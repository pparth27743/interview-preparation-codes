#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void solve(int open, int close, string &tmp){

    if(open == 0 && close == 0){
        ans.push_back(tmp);
        return;
    }  

    if(open < 0 || close < 0)
        return;

    if(close > open){
 
        tmp.push_back(')');
        solve(open, close-1, tmp);
        tmp.pop_back();

        tmp.push_back('(');
        solve(open-1, close, tmp);
        tmp.pop_back();

    }
    else{
        tmp.push_back('(');
        solve(open-1, close, tmp);
        tmp.pop_back();
    }

}

int main() {

    int n = 3;
    cin >> n;
    string tmp = "";
    solve(n,n, tmp);

    for(auto s : ans){
        cout << "'";
        cout << s ;
        cout << "'\n";
    }

    return 0;
}
