#include <bits/stdc++.h>
using namespace std;

// Shortest Common SuperSequence

// Bottom-Up approach 
int scs(int x, int y, string s1, string s2)
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
    return (x+y-dp[x][y]);
}



int main()
{
    string s1 = "efgh";
    string s2 = "jghi";

    int x = s1.size();
    int y = s2.size();
   
    cout << scs(x, y, s1, s2) << endl;

    return 0;
}
