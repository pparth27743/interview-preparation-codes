#include <bits/stdc++.h>
using namespace std;


int main(){

    string A = "12823423";
    int divisor = 234;
    string ans = "";

    int i = 0;
    int tmp = 0;
    
    while( i < A.size()){
        
        tmp = tmp*10 + A[i]-'0';

        while(tmp < divisor && i < A.size()){
            if(ans != ""){
                ans += "0";
            }
            tmp = tmp * 10 + A[++i]-'0';
        }

        if(i == A.size())
            break;

        ans += tmp/divisor + '0';
        tmp = tmp - ((tmp/divisor)*divisor);

        i++;
    }
    
    cout << ans << endl;

    
    return 0;
}
