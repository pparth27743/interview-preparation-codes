#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > ans;

// Method 1
void solve_1(vector<int> &tmp, vector<bool> &visited, vector<int> &nums){
    if(tmp.size() == nums.size()){
        ans.push_back(tmp);
        return;
    }
    
    
    for(int i=0; i<nums.size(); i++){
        if(visited[i])  continue;
        
        visited[i] = true;
        tmp.push_back(nums[i]);
        solve_1(tmp, visited, nums);
        visited[i] =false;
        tmp.pop_back();
    }
    
}

vector<vector<int> > permute_1(vector<int>& nums) {
    
    ans.clear();
    vector<int> tmp;
    vector<bool> visited(nums.size());
    solve_1(tmp, visited, nums);
    
    return ans;
    
}


// Method 2
void solve_2(int index, vector<int> &nums){
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }
    
    for(int i=index; i<nums.size(); i++){
        swap(nums[i], nums[index]);
        solve_2(index+1, nums);
        swap(nums[i], nums[index]);
    }
}

vector<vector<int> > permute_2(vector<int>& nums) {
    
    ans.clear();
    solve_2(0, nums);
    return ans;
}



int main() {

    vector<int> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    vector<vector<int> > ans = permute_2(arr);

    for(auto v : ans){
        cout << "{ ";
        for(int num : v)
            cout << num << " ";
        cout << "}\n";
    }

    return 0;
}
