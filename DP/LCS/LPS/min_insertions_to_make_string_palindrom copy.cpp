#include <bits/stdc++.h>
using namespace std;

/*
Solution : min no. of insertions to make string palindrom = min no. deletions to make string palindrom

ex. aebcbda => palindromic subsequence ( abcba ) we deleted e and d characters, 
    now we have question to make existing string a palindrom so, above we saw after deleting
    some characters we can make string palindrom so, the same way if we add those character at 
    appropriate location then we can make existing string palindromic. 


We also can print that newly genarated palindromic string using scs code.

*/




string print_scs(int x, int y, string s1, string s2, vector<vector<int> > dp){

    string ans = "";

    int i = dp.size();
    int j = dp[0].size();

    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans = s1[i-1] + ans;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            ans = s1[i-1] + ans;
            i--;
        }
        else{
            ans = s2[j-1] + ans;
            j--;
        }
    }

    while(i>0){
        ans = s1[i-1] + ans;
        i--;
    }

    while(j>0){
        ans = s2[j-1] + ans;
        j--;
    }
    
    return ans;
}

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

    cout << print_scs(x, y, s1, s2, dp) << endl;

    return (x+y-dp[x][y]);
}


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
    string s = "aebcbda";
    string rs = s;   
    reverse(rs.begin(), rs.end());
    int x = s.size();
    
    // print palindrome string
    scs(x,x, s, rs);

    int len_lcs = lcs(x, x, s, rs); 
    cout << x - len_lcs << endl;

    return 0;
}
