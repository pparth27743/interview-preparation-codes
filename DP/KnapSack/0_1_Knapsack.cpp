#include<bits/stdc++.h>
using namespace std;


// Returns the maximum value that  
// can be put in a knapsack of capacity W 

int knapSackRec(int W, int wt[], int val[], int n, int **arr) 
{ 
    if(W == 0 || n == 0)
        return 0;
    else{
        if(arr[n][W] != -1)
            return arr[n][W];
        else{
            if(wt[n-1]<=W){
                arr[n][W] = max(knapSackRec(W, wt, val, n-1, arr), val[n-1] + knapSackRec(W-wt[n-1], wt, val, n-1, arr));
                return arr[n][W];
            }
            else{
                arr[n][W] = knapSackRec(W, wt, val, n-1, arr);
                return arr[n][W];
            }
        }
    }   
}


int knapSack(int W, int wt[], int val[], int n) 
{ 
    int *arr[n+1];
    for(int i=0; i<=n; i++){
        arr[i] = new int [W+1];
        memset(arr[i], -1 , sizeof(int)*(W+1));
    }
    return knapSackRec(W, wt, val, n, arr);
}


// int knapSack(int W, int wt[], int val[], int n) 
// { 
//     int arr[n+1][W+1];
//     for(int i=0; i<=n; i++)
//         arr[i][0] = 0;
//     for(int j=0; j<=W; j++)
//         arr[0][j] = 0;
        
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=W; j++){
//             if(wt[i-1] <= j)
//                 arr[i][j] = max(arr[i-1][j], val[i-1] + arr[i-1][j-wt[i-1]]);
//             else
//                 arr[i][j] = arr[i-1][j];
//         }
//     }
//     return arr[n][W];
// }



int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        //calling method knapSack()
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
} 