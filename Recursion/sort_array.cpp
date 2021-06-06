#include <bits/stdc++.h>
using namespace std;


void insert(vector<int> &arr, int val){

    if(arr.size() == 0 || arr[arr.size()-1] <= val){
        arr.push_back(val);
        return;
    }

    int tmpval = arr[arr.size()-1];
    arr.pop_back();

    insert(arr, val);
    
    arr.push_back(tmpval);
}


void sort(vector<int> &arr){

    if(arr.size() == 1)
        return;

    int val = arr[arr.size()-1];
    arr.pop_back();

    sort(arr);

    insert(arr, val);
}



int main(){

    vector<int> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(7);
    arr.push_back(0);
    arr.push_back(6);

    sort(arr);

    for(int i : arr)
        cout << i << " ";

    cout << "\n";

    return 0;
}