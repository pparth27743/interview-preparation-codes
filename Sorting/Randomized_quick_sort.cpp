#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>

using namespace std;

int partition(int arr[], int l, int r){

    int pivort = arr[l];
    int i = l+1, j=r;

    while(i<=j){
        while(i<=j && arr[i]<=pivort) i++;
        while(i<=j && arr[j]>pivort) j--;

        if(i<j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    i--;
    arr[l] = arr[i];
    arr[i] = pivort;

    return i;
}




void quickSort(int arr[], int l, int r){

    if(l<r){

        int p = (rand()%(r-l+1)) + l;
        swap(arr[l], arr[p]);
        int k = partition(arr, l, r);

        quickSort(arr, l, k-1);
        quickSort(arr, k+1, r);
    }
}





int main(){

    srand(time(0));

    int arr[] = {3,4,6,2,6,56,3,6,23,7,9,7,54,23,56,68,9,6,4,434,56,658,56,6,456,4,73,4,6,324};
    int size = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, size-1);

    for(int i : arr)
        cout << i << " ";

    cout << "\n";

    return 0;
}