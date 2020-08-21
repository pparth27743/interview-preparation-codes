#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {10,20,30,10,50,100};
    int b[] = {10,20,30,10,50,100};
    int a1[6] = {0};
    
    int q; cin >> q;
    while(q--){
//************   Naive Method    *********//
        int l,r,val;
        cin >> l >> r >> val;
        
        for(int i=l; i<=r; i++)
            a[i] += val;
            
//************  Optimized Method  *********//
        a1[l] += val;
        if((r+1)<6)
            a1[r+1] += (-val);
    }
    
//************   Naive Method Output   *********//
    cout << "Naive Method: \n"
    for(int i: a)
        cout << i << " ";
    cout << "\n";

//************  Optimized Method Output *********//
    cout << "Optimized Method: \n"
    for(int i=1; i<6; i++)
        a1[i] += a1[i-1];
    for(int i=0; i<6; i++)
        a1[i] += b[i];
    for(int i: a1)
        cout << i << " ";
        
	return 0;
}
