#include <bits/stdc++.h>
using namespace std;


// O(n^2)
int minJumps(int arr[], int n) 
{ 
    int jumps[n];
    jumps[0] = 0;
    for(int i=1; i<n; i++){
        jumps[i] = INT_MAX;
        for(int j=0; j<i; j++){
            if(i<=j+arr[j]){
                jumps[i] = min(jumps[i], jumps[j]+1);
            }
        }
    }

    return jumps[n-1];
} 

// O(n)
int minJumps1(int arr[], int n){

    if(n==1)
        return 0;

    if(arr[0] == 0)
        return -1;

    int maxreachble = arr[0];
    int steps = arr[0];
    int jumps = 1;

    for(int i=1; i<n; i++){

        if(i == n-1)
            return jumps;

        
        maxreachble = max(maxreachble, i+arr[i]);
        steps--;

        if(steps == 0){
            jumps++;
            if(i>=maxreachble)
                return -1;
            steps = maxreachble - i;
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[] = { 1, 0, 6, 3, 2, 
                  3, 6, 8, 9, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Minimum number of jumps to"; 
    cout << " reach the end is " << minJumps1(arr, n) << "\n"; 
    return 0; 

}

