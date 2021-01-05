#include <bits/stdc++.h>
using namespace std;

/*
                Sort by Frequency and Value
Given a list of integers nums, order nums by frequency, with most frequent values coming first. 
If there's a tie in frequency, higher valued numbers should come first.
*/


// Customized comparator 
bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.first > b.first)
        return true;
    else if(a.first == b.first)
        return (a.second > b.second);
    else
        return false;
}

vector<int> solve(vector<int>& nums) {
    unordered_map<int, int> mp;
    for(int i : nums)
        mp[i]++;

    vector<pair<int, int> > v;
    for(auto p : mp)
        v.push_back(make_pair(p.second, p.first));

    sort(v.begin(), v.end(), cmp);
    vector<int> ans;

    for(auto p : v){
        while(p.first--)
            ans.push_back(p.second);
    }    
    return ans;
}

// takes more time (but see the code size) (If we use inbuild container like gp_hash_table then it will be fast)
vector<int> solve_1(vector<int>& nums) {

    unordered_map<int, int> freq;
    for(int i : nums) freq[i]++;

    sort(nums.begin(), nums.end(), 
    [&](const int &a, const int &b) {return ((freq[a]==freq[b]) ? (a>b) : (freq[a]>freq[b]));});

    return nums;
}


int main(){

    int arr[] = {1, 1, 5, 5, 5, 2, 2, 2, 1, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    vector<int> nums(arr, arr+size);
    vector<int> ans;

    // ans = solve_1(nums);
    ans = solve(nums);

    for(int i : ans)
        cout << i << " ";

    cout << endl;

    return 0;
}