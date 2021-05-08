#include <bits/stdc++.h>
using namespace std;


// Nearest Smaller to left

vector<int> NSL(int arr[], int n){

    vector<int> ans;
    stack<int> s;

    for(int i=0; i<n; i++){
        if(s.size() == 0)
            ans.push_back(-1);
        else if(s.top() < arr[i])
            ans.push_back(s.top());
        else if(s.top() >= arr[i]){
            while(s.size() > 0 && s.top() >= arr[i])
                s.pop();
            if(s.size() == 0)
                ans.push_back(-1);
            else    
                ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return ans;
}

   
int main(){
   
    int val[] = {4,5,2,10,8};

    int n = sizeof(val)/sizeof(val[0]);
    vector<int> ans = NSL(val, n);

    for(int i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}


