class Solution{
    public int cutRod(int price[], int n) {
        Integer[][] memo = new Integer[price.length+1][n+1];
        return rec(0, n, price, memo);
    }

    // Think of it like, you are collecting rod of various lenght and total length N is allowed to take. 
  
     private int rec(int i, int N, int[] price, Integer[][] memo) {
        if(i==price.length)
            return 0;
        if(N == 0)
            return 0;
            
        if(memo[i][N] != null)
            return memo[i][N];
        
        int length = i+1;
        
        if(length<=N) {
            return memo[i][N] = Math.max(rec(i, N-length, price, memo) + price[i], rec(i+1, N, price, memo));
        }
        
        return memo[i][N] = rec(i+1, N, price, memo);
    }
}
