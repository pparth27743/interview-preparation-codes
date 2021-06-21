#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > ans;

vector<int> solve(int arr[], int n, int k){

    vector<int> ans; 
    queue<int> q;

    int j=0, i=0;

    while(j<n){

        if(arr[j] < 0)
            q.push(arr[j]);

        if(j-i+1 < k){
            j++;
        }
        else if(j-i+1 == k){
            if(q.size() == 0)
                ans.push_back(0);
            else{
                ans.push_back(q.front());
                if(arr[i] == q.front())
                    q.pop();
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main() {

    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> ans = solve(arr, n, 3);

    for(int num : ans)
        cout << num << " ";

    cout << endl;

    return 0;
}