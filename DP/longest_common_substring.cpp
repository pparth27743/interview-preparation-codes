#include <bits/stdc++.h>
using namespace std;


// Top-Down Approach
int longest_common_substring_Rec(int x, int y, string s1, string s2, int count){
    
    if(x==0 || y==0)
        return count;

    if(s1[x-1] == s2[y-1])
        count = longest_common_substring_Rec(x-1, y-1, s1, s2, 1+count);
    else
        count =  max(count, max(longest_common_substring_Rec(x, y-1, s1, s2, 0), longest_common_substring_Rec(x-1, y, s1, s2, 0)));

    return count;
}


// Bottom-Up approach 
int longest_common_substring(int x, int y, string s1, string s2)
{
    vector<vector<int> > dp(x + 1, vector<int>(y + 1, 0));

    int ans = INT_MIN;

    for (int i = 1; i <= x; i++){
        for (int j = 1; j <= y; j++){
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;

            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

int main()
{

    string s1 = "ABCDGH";
    string s2 = "ABCDGH";

    int x = s1.size();
    int y = s2.size();
   
    cout << longest_common_substring(x, y, s1, s2) << endl;
    cout << longest_common_substring_Rec(x, y, s1, s2, 0) << endl;

    return 0;
}
