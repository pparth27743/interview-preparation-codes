#include <bits/stdc++.h>
using namespace std;


// lps(a) = lcs(a, reverse(a))

// Longest Palindromic Subsequence
int lcs(int x, int y, string s1, string s2){
    
    vector<vector<int> > dp(2, vector<int>(y+1,0));
    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            if(s1[i-1] == s2[j-1])
                dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
            else    
                dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
        }
    }
    return dp[x%2][y];
}


int main()
{
    string s = "agbfsadfasdfsadfcba";
    string rs = s;   
    reverse(rs.begin(), rs.end());
    int x = s.size();
    
    int len_lcs = lcs(x, x, s, rs); 

    cout << len_lcs << endl;

    return 0;
}
