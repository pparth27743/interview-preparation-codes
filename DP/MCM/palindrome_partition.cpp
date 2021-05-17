#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string s, int i, int j, vector<vector<int> > &p){

    if(p[i][j] != -1)
        return p[i][j];

    while(i<j){
        if(s[i] != s[j])
            return p[i][j] = 0;
        i++;
        j--;
    }
    return p[i][j] = 1;
}


int solve(string s, int i, int j, vector<vector<long> > &dp, vector<vector<int> > &p){

    if(i>=j || isPalindrome(s, i, j, p) == 1)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for(int k=i; k<=j-1; k++){
        int tmp = 1 + solve(s, i, k, dp, p) + solve(s, k+1, j, dp, p);
        ans = min(ans, tmp);
    }
  
    return dp[i][j] = ans;
}


int main()
{

    string s = "parth";
    int n = s.size();

    vector<vector<long> > dp(n+1, vector<long> (n+1, -1));
    vector<vector<int> > p(n+1, vector<int> (n+1, -1));

    cout << solve(s, 0, n-1, dp, p) << endl;

    return 0;
}
