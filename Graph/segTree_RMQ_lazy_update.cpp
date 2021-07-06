#include <bits/stdc++.h>
using namespace std;


void createSegmentTree(int segTree[], int arr[], int low, int high, int pos){

    if(low == high){
        segTree[pos] = arr[low];
        return;
    }

    int mid = (low+high)/2;
    createSegmentTree(segTree, arr, low, mid, 2*pos+1);
    createSegmentTree(segTree, arr, mid+1, high, 2*pos+2);
    segTree[pos] = min(segTree[2*pos+1], segTree[2*pos+2]);
}

void updateRange(int segTree[], int lazyTree[], int qlow, int qhigh, int low, int high, int val, int pos){

    if(low > high)
        return;

    if(lazyTree[pos] != 0){
        segTree[pos] += lazyTree[pos];
        if(low != high){
            lazyTree[2*pos+1] += lazyTree[pos];
            lazyTree[2*pos+2] += lazyTree[pos];
        }
        lazyTree[pos] = 0;
    }

    // no overlap
    if(qlow>high || qhigh<low)
        return;

    // total overlap
    if(qlow<=low && qhigh>=high){
        segTree[pos] += val;
        if(low != high){
            lazyTree[2*pos+1] += val;
            lazyTree[2*pos+2] += val;
        }
        return;
    }

    int mid = (low+high)/2;
    updateRange(segTree, lazyTree, qlow, qhigh, low, mid, val, 2*pos+1);
    updateRange(segTree, lazyTree, qlow, qhigh, mid+1, high, val, 2*pos+2);
    segTree[pos] = min(segTree[2*pos+1], segTree[2*pos+2]);
}

int RMQ(int segTree[], int lazyTree[], int qlow, int qhigh, int low, int high, int pos){

    if(low > high)
        return INT_MAX;

    if(lazyTree[pos] != 0){
        segTree[pos] += lazyTree[pos];
        if(low != high){
            lazyTree[2*pos+1] += lazyTree[pos];
            lazyTree[2*pos+2] += lazyTree[pos];
        }
        lazyTree[pos] = 0;
    } 

    // no overlap
    if(qlow>high || qhigh<low)
        return INT_MAX;

    // total overlap
    if(qlow<=low && qhigh>=high)
        return segTree[pos];

    // partial overlap
    int mid = (low+high)/2;
    return min(RMQ(segTree, lazyTree, qlow, qhigh, low, mid, 2*pos+1),
               RMQ(segTree, lazyTree, qlow, qhigh, mid+1, high, 2*pos+2));
}

int main(){
    
    int arr[] = {-1, 3, 3, 0, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]); 

    int size = pow(2, ceil(log2(n))+1) - 1;
    int segTree[size], lazyTree[size];
    memset(lazyTree, 0, sizeof(lazyTree));

    int low = 0, high = n-1, pos = 0;
    createSegmentTree(segTree, arr, low, high, pos);

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            updateRange(segTree, lazyTree, i, j, low, high, 10, pos);
            cout << RMQ(segTree, lazyTree, 0, 5, low, high, pos) << endl;
        }
    }

    cout << "\n";

    cout << RMQ(segTree, lazyTree, 0, 0, low, high, pos) << endl;
    cout << RMQ(segTree, lazyTree, 1, 1, low, high, pos) << endl;
    cout << RMQ(segTree, lazyTree, 2, 2, low, high, pos) << endl;
    cout << RMQ(segTree, lazyTree, 3, 3, low, high, pos) << endl;
    cout << RMQ(segTree, lazyTree, 4, 4, low, high, pos) << endl;
    cout << RMQ(segTree, lazyTree, 5, 5, low, high, pos) << endl;

    cout << "\n";


    for(auto i : segTree)
        cout << i << " ";

    cout << endl;
    return 0;
}