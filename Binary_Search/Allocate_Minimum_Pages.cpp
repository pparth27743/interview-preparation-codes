#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &A, int limit, int B){
    
    int stud = 1;
    int sum = 0;
    
    for(int  pgs : A){

        // This if condition is required if we start Binary search from low = 0.

        // In the best case minimum pages read by a student can't be less then max pages book. 
        // So this condition helps to make sure of that. 
        
        // This will take care of the case, where we can allocated pages to some students only  
        // and still we can reduce the answer. But we want to allocate every student at least one 
        // book. 
        if(pgs > limit)
            return false;

        sum += pgs;
        if(sum > limit){
            stud++;
            sum = pgs;
        }
        
        if(stud > B)
            return false;
    }
    
    return true;
}


int books(vector<int> &A, int B) {
    
    int sumPg = 0;
    int ans = -1;
    int mxPgs = INT_MIN;
    
    // This is the only case where allocation of book is not possible
    if(B > A.size())
        return -1;
    
    for(int num : A){
        mxPgs = max(mxPgs, num);
        sumPg += num;
    }
    
    // In the best case minimum pages read by a student can't be less then max pages book. 
    // So we can initialize low = max(arr)
    // But if we initialize low = 0 then the condtion I have mentioned in isValid function is required.
    int low=mxPgs, high=sumPg, mid;
    
    while(low<=high){
        mid = low + (high - low)/2;
        
        if(isValid(A, mid, B)){
            ans = mid;
            high = mid-1;    
        }else{
            low = mid+1;
        }
    }
    return ans;
}


int main() {

    int arr[] = {97, 26, 12, 67, 10, 33, 79, 49, 79, 21, 67, 72, 93, 36, 85, 45, 28, 91, 94, 57, 1, 53, 8, 44, 68, 90, 24 };


    int B = 26;

    vector<int> A(begin(arr), end(arr));

    cout << books(A, B) << endl;


    return 0;
}

