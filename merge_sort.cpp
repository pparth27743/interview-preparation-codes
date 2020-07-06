#include <iostream> 
using namespace std;


void merge(int arr[], int l, int m, int r){ 

    int i=0;
    int j=0;
    int k=l;
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    
    for(int i=0; i<n1; i++)
        L[i] = arr[l+i];
    
    for(int i=0; i<n2; i++)
        R[i] = arr[m+1+i];
        
    
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergesort(int arr[], int l, int r){
    if(l < r){
        int m = (l+r)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {12,2,4,7,3,3,67,34,643,2,4,23,3,34,234654,75,345};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    mergesort(arr,0,size-1);
    
    for(int i=0; i<size; i++)
        cout << arr[i] << " ";
    
    return 0;
} 
