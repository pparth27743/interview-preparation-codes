#include <bits/stdc++.h>
using namespace std;


// Nearest Greater to left

vector<int> NGL(int arr[], int n){

    vector<int> ans;
    stack<int> s;

    for(int i=0; i<n; i++){
        if(s.size() == 0)
            ans.push_back(-1);
        else if(s.top() > arr[i])
            ans.push_back(s.top());
        else if (s.top() <= arr[i]){
            while(s.size()>0 && s.top()<=arr[i])
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
   
    int val[] = {1,3,2,4};

    int n = sizeof(val)/sizeof(val[0]);
    vector<int> ans = NGL(val, n);

    for(int i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}


