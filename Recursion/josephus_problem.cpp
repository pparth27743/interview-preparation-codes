/*


Josephus special case: k = 2. 

Method - 1 : Math
repersent n = 2^a + l, where a is max such that 2^a <= n.
ans : (2*l + 1)

Method - 2 : Bit Manipulation
represnt n in term of binary number. 
Now take leading 1 from that represent and put at back, now this new number is answer. 
ex. n = 9 , 1001 -> 0011 -> 3 (ans)


*/



#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) | SC : O(n)  by Aditya Verma
int solve_1(int index, int n, int k, vector<int> &arr){
    if(n == 1)
        return arr[0];

    int x = (index + k)%n;
    arr.erase(arr.begin() + x);
    
    n = n-1;
    x = x%n;
    return solve_1(x, n, k, arr);
}

// TC: O(n) | SC : O(1) by Sumit Malik
int solve_2(int n, int k){
    if(n == 1)
        return 0;

    int x = solve_2(n-1, k);
    int y = (x + k)%n;

    return y;    
}



int main() {

    int n = 7;
    int k = 2;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i=1; i<=n; i++)
        arr[i-1] = i;

    cout << solve_1(0, n,k-1, arr) << endl;
    cout << solve_2(n, k)+1 << endl;

    return 0;
}
