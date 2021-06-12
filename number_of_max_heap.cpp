#include <bits/stdc++.h>
using namespace std;

long numMaxHeap(long A, vector<long> &dp, vector<vector<long> > &nck){
    
    if(A <= 1)
        return 1;
        
    if(dp[A] != -1)
        return dp[A];  
        
    long m = 1e9+7;
    
    long h = log2(A);
    long nodeH = pow(2, h); // 2^h
    long last = A - (pow(2, h) - 1); // A - (2^h -1)
    
    long L;
    
    if(last >= nodeH/2)
        L = pow(2, h) - 1;
    else
        L = (pow(2, h-1) - 1) + last;
    
    long R = A-1-L;

    long leftans = numMaxHeap(L,dp, nck ) % m;
    long rightans = numMaxHeap(R, dp, nck) % m;

    long ans = (nck[A-1][L] * ((leftans * rightans) % m)) % m;
    
    return dp[A] = ans;
    
}



int main() {
    
    long A;
    cin >> A;

    long m = 1e9+7;

    vector<vector<long> > nck(A+1, vector<long> (A+1,  0));

    for(long i=0; i<=A; i++)
        nck[i][0] = 1;

    for(long i=1; i<=A; i++){
        for(long j=1; j<=A; j++){
            nck[i][j] = ((nck[i-1][j] % m) + (nck[i-1][j-1] % m)) % m;
        }
    }
    
    vector<long> dp(A+1, -1);
    
    cout <<  numMaxHeap(A, dp, nck) << '\n'; 
    
    return 0;
}
