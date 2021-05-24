#include <bits/stdc++.h>
using namespace std;


void rangeUpdateSegTree(int segTree[], int val, int qlow, int qhigh, int low, int high, int pos){


    if(low > high || qlow > high || qhigh < low)
        return;

    else if(low == high){
        segTree[pos] += val;
        return;
    }

    int mid = (low+high)/2;

    rangeUpdateSegTree(segTree, val, qlow, qhigh, low, mid, 2*pos + 1);
    rangeUpdateSegTree(segTree, val, qlow, qhigh, mid+1, high, 2*pos + 2);

    segTree[pos] = min(segTree[2*pos + 1], segTree[2*pos + 2]);    
}



int rangeMinQuery(int segTree[], int qlow, int qhigh, int low, int high, int pos){

    if(qhigh < low || qlow > high)
        return INT_MAX;

    else if(qlow <= low && qhigh>=high)
        return segTree[pos];

    int mid = (low+high)/2;

    return min(rangeMinQuery(segTree, qlow, qhigh, low, mid, 2*pos + 1),
                rangeMinQuery(segTree, qlow, qhigh, mid+1, high, 2*pos + 2));
}


void createSegmentTree(int segTree[], int input[], int low, int high, int pos){

    if(low == high){
        segTree[pos] = input[low];
        return;
    }

    int mid = (low+high)/2;

    createSegmentTree(segTree, input, low, mid, 2*pos+1);
    createSegmentTree(segTree, input, mid+1, high, 2*pos+2);
    segTree[pos] = min(segTree[2*pos + 1], segTree[2*pos + 2]);

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int arr[] = {-1, 3, 3, 0, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]); 

    int size = pow(2, ceil(log2(n))+1) - 1;
    int segTree[size];

    int low = 0, high = n-1, pos = 0;

    createSegmentTree(segTree, arr, low, high, pos);
    
    cout << rangeMinQuery(segTree, 0, 5, low, high, pos) << endl;
    
    rangeUpdateSegTree(segTree, 10, 0, 5, low, high, pos);

    cout << rangeMinQuery(segTree, 0, 5, low, high, pos) << endl;

    for(auto i : segTree)
        cout << i << " ";


    cout << endl;

    return 0;
}