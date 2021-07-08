#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int B, int n){

    sort(arr.begin(), arr.end());
    int cnt=0;

    for(int i=0; i<n; i++){
        if(arr[i] <= B){
            B  -= arr[i];
            cnt++;
        }
        else    
            break;
    }

    return cnt;
}



int main() {


    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif

    int t;  cin >> t;
    int cnt = 1;


    while(t--){
        int n, B;  cin >> n >> B;
        vector<int> arr(n);
        
        for(int i=0; i<n; i++) 
            cin >> arr[i];

        int ans = solve(arr, B, n);
        

        cout << "Case #" << cnt << ": " << ans << endl;
        cnt++;

    }
    return 0;
}


