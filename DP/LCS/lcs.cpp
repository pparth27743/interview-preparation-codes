#include <bits/stdc++.h>
using namespace std;

// Top-Down Approach
int helper(int x, int y, string s1, string s2, vector<vector<int> > &dp){ 
    if(x==0 || y==0)
        return 0;
    if(dp[x][y] != -1)
        return dp[x][y];
    if(s1[x-1] == s2[y-1])
        return dp[x][y] = (1 + (helper(x-1, y-1, s1, s2, dp))); 
    return dp[x][y] = max(helper(x-1, y, s1, s2, dp), helper(x, y-1, s1, s2, dp));    
}

int lcsRec(int x, int y, string s1, string s2){
    vector<vector<int> > dp(x+1, vector<int>(y+1, -1));
    return helper(x, y, s1, s2, dp);
}


void display(vector<char> v){
    reverse(v.begin(), v.end());
    for(char ch : v)
        cout << ch;
    cout << endl;
}

void printSubSeq(int i, int j, string s1, string s2, vector<vector<int> >&dp, vector<char> &v){

    if(i == 0 || j == 0){
        display(v);
        return;
    }

    if(s1[i-1] == s2[j-1]){
        v.push_back(s1[i-1]);
        printSubSeq(i-1, j-1, s1, s2, dp, v);
    }
    else{
        if(dp[i-1][j] > dp[i][j-1]){
            printSubSeq(i-1, j, s1, s2, dp, v);
        }
        else if(dp[i][j-1] > dp[i-1][j]){
            printSubSeq(i, j-1, s1, s2, dp, v);
        }
        else{
            vector<char> p = v;
            printSubSeq(i, j-1, s1, s2, dp, p);
            printSubSeq(i-1, j, s1, s2, dp, v);
        }
    }

}

// Space Optimized 
int lcs_space_op(int x, int y, string s1, string s2){

    vector<vector<int> > dp(2, vector<int>(y+1, 0));

    for (int i=1; i<=x; i++){
        for (int j=1; j<=y; j++){
            if (s1[i-1] == s2[j-1])
                dp[i%2][j] = 1 + dp[(i-1)%2][j-1];
            else
                dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
        }
    }
    return dp[x%2][y];
}

// Bottom-Up approach 
int lcsTab(int x, int y, string s1, string s2)
{
    vector<vector<int> > dp(x + 1, vector<int>(y + 1, 0));

    for (int i = 1; i <= x; i++){
        for (int j = 1; j <= y; j++){
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    vector<char> v;
    printSubSeq(x,y,s1,s2,dp,v);

    return dp[x][y];
}

int main()
{

    string s1 = "abcadfadffasdfasdfasdfasasdfasdfsdfbcaa";
    string s2 = "acbsdfadfsdfasdfasdfasdfasdfassdfacba";

    int x = s1.size();
    int y = s2.size();
   
    // cout << lcsTab(x, y, s1, s2) << endl;
    cout << lcs_space_op(x, y, s1, s2) << endl;
    // cout << lcsRec(x, y, s1, s2) << endl;

    return 0;
}
