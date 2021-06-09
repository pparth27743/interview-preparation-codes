#include <bits/stdc++.h>
using namespace std;



// O(n^2) 
int minCut(string s) {
        
        int n = s.size();
        vector<int> dp(n+1, 0);
        
        // here we have to initialize
        // dp[0] = -1
        
        for(int i=0; i<=n; i++)
            dp[i] = i-1;
        
        for(int i=0; i<n; i++){
            
            // odd length palindrome
            for(int j=0; i-j>=0 && i+j<n && s[i-j] == s[i+j]; j++)
                dp[i+j+1] = min(dp[i+j+1], 1 + dp[i-j]);
            
            // even length palindrome
            for(int j=0; i-j>=0 && i+j+1<n && s[i-j] == s[i+j+1]; j++)
                dp[i+j+2] = min(dp[i+j+2], 1 + dp[i-j]);
            
        }
        
        return dp[n];
        
}


// O(n^3)
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

    string s = "parth patel";
    int n = s.size();

    vector<vector<long> > dp(n+1, vector<long> (n+1, -1));
    vector<vector<int> > p(n+1, vector<int> (n+1, -1));

    cout << solve(s, 0, n-1, dp, p) << endl;

    cout << minCut(s) << endl;

    return 0;
}
