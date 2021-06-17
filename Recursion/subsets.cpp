#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > ans;


// Backtracing 1
void solve_1(int index, int k, int n, vector<int> &vec, vector<int> &nums){
    if(vec.size() == k){
        ans.push_back(vec);
        return;
    }
    
    for(int i=index; i<n; i++){
        vec.push_back(nums[i]);
        solve_1(i+1, k, n, vec, nums);
        vec.pop_back();
    }
            
}

vector<vector<int> > using_backtracking_1(vector<int>& nums) {
    
    ans.clear();
    vector<int> vec;
    int n = nums.size();
    
    for(int i=0; i<=n; i++)
        solve_1(0, i, n, vec, nums);
    
    return ans;
    
}


// Backtracking 2
void solve_2(int i, vector<int> &nums, vector<int> &vec){
    
    if(i == 0){
        ans.push_back(vec); 
        return;
    }
    
    solve_2(i-1, nums, vec);
    vec.push_back(nums[i-1]);
    solve_2(i-1, nums, vec);
    vec.pop_back();
}

vector<vector<int> > using_backtracking_2(vector<int>& nums) {
    
    ans.clear();
    vector<int> vec;
    solve_2(nums.size(), nums, vec);
    
    return ans;
}



// Cascading     
vector<vector<int> > using_cascading(vector<int>& nums) {
    
    vector<vector<int> > ans;
    vector<int> tmp;
    ans.push_back(tmp);
    
    for(int num : nums){
        vector<vector<int> > tmpans;
        tmp.clear();
        for(auto v : ans){
            tmp = v;
            tmp.push_back(num);
            tmpans.push_back(tmp);
        }
        
        for(auto v : tmpans)
            ans.push_back(v);
    }
    
    return ans;
}


// Using Bitmask 
vector<vector<int> > using_bitmask(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int> > ans;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        for(int i=0; i<pow(2, n); i++){
            string bitmask = bitset<11>(i).to_string().substr(11-n, n);
            vector<int> tmp;
            for(int j=n-1; j>=0; j--){
                if(bitmask[j] == '1')
                    tmp.push_back(nums[j]);
            }
            ans.push_back(tmp);
        }
        
        return ans;
}


int main() {

    vector<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    vector<vector<int> > ans = using_backtracking_2(arr);

    for(auto v : ans){
        cout << "{ ";
        for(int num : v)
            cout << num << " ";
        cout << "}\n";
    }

    return 0;
}
