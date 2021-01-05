#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0)
        return a;
    else 
        return gcd(b, a%b);
}

void rotateArr(int arr[], int d, int n){
   
   for(int i=0; i<gcd(n,d); i++){
       int j, k, tmp;   
       tmp = arr[i];
       j=i;
       while(1){
            k = (j+d)%n;
            if(k == i)
                break;
            arr[j]=arr[k];
            j=k;
        }
        arr[j] = tmp;
   }
}

int main(){

    int n = 8, d = 19;
    int arr[n];

    for(int i=0; i<n; i++){
        arr[i] = i+1;
        cout << arr[i] << " ";
    }
    
    rotateArr(arr, d, n);
    
    cout << endl;
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
