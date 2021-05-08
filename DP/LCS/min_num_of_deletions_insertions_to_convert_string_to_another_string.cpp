#include <bits/stdc++.h>
using namespace std;


// Bottom-Up approach 
int lcs(int x, int y, string s1, string s2)
{
    vector<vector<int> > dp(x+1, vector<int>(y+1, 0));

    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else    
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[x][y];
}


int main()
{
    string s1 = "heap";
    string s2 = "pea";

    int x = s1.size();
    int y = s2.size();
    
    int len_lcs = lcs(x, y, s1, s2);

    cout << (x+y-(2*len_lcs)) << endl;

    return 0;
}
