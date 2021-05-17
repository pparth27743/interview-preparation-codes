#include <bits/stdc++.h>
using namespace std;


// Bottom-Up approach 
int lcsTab(int x, int y, string s1, string s2)
{
    vector<vector<int> > dp(x + 1, vector<int>(y + 1, 0));

    for (int i = 1; i <= x; i++){
        for (int j = 1; j <= y; j++){
            
            if (s1[i - 1] == s2[j - 1] && i != j)           // Here extra condition is added (i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[x][y];
}

int main()
{

    string s1 = "aabebcdd";
    string s2 = s1;
    int x = s1.size();
    int y = s2.size();
   
    cout << lcsTab(x, y, s1, s2) << endl;
 

    return 0;
}
