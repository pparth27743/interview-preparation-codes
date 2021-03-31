// Source: https://cp-algorithms.com/algebra/extended-euclid-algorithm.html

#include<iostream>
using namespace std;

int gcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    else{
        int x1, y1;
        int d = gcd(b, a%b, x1, y1);
        x = y1;
        y = x1 - y1 * (a/b);
        return d;
        
    }
}



int main(){
    
    int a = 17, b = 17, x, y, d;
    d = gcd(a, b, x, y);
    
    cout << x << " " << y << " " << d << endl;
        
    return 0;
}
