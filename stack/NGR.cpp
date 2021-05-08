#include <bits/stdc++.h>
using namespace std;


// Nearest Greater to right or Next Largest Element

vector<int> NGR(int arr[], int n){
    
    stack<int> s;
    vector<int> ans; 

    for(int i=n-1; i>=0; i--){
        if(s.size() == 0){
            ans.push_back(-1);
        }
        else if(s.top() > arr[i]){
            ans.push_back(s.top());
        }
        else if(s.top() <= arr[i]){
            while(s.size()>0 && s.top() <= arr[i]){
                s.pop();
            }
            if(s.size() == 0){
                ans.push_back(-1);
            }else{
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}



   
int main(){
   
    int val[] = {1,3,2,4};

    int n = sizeof(val)/sizeof(val[0]);
    vector<int> ans = NGR(val, n);

    for(int i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}


