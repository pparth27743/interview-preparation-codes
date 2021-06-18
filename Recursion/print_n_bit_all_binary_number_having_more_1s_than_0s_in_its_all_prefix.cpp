#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void solve(int ones, int zeros, int n, string &tmp){
    if(ones+zeros == n){
        ans.push_back(tmp);
        return;
    }

    if(zeros < ones){
        // take zero 
        tmp.push_back('0');
        solve(ones, zeros+1, n, tmp);
        tmp.pop_back();

        // take one
        tmp.push_back('1');
        solve(ones+1, zeros, n, tmp);
        tmp.pop_back();
        tmp.pop_back();
    }
    else{
        tmp.push_back('1');
        solve(ones+1, zeros, n, tmp);
        tmp.pop_back();
    }

}


int main() {

    int n = 3;
    cin >> n;
    string tmp = "";
    solve(0,0, n, tmp);

    for(auto s : ans){
        cout << "'";
        cout << s ;
        cout << "'\n";
    }

    return 0;
}
