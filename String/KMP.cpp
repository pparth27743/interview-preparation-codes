#include <bits/stdc++.h>
using namespace std;

/*
Compute the lps(longest prefix suffix)  ->
At any index i what is the maximum lenght of the prefix that is also a suffix of the of stirng S[0:i]

    string  : a b c a a b c a b
    lps     : 0 0 0 1 1 2 3 4 2

*/
vector<int> computeLPS(string S){
    
    int n = S.size();
    vector<int> lps(n);
    lps[0] = 0;

    int j = 0;
    for(int i=1; i<n; i++){
        if(S[i] == S[j]){
            lps[i] = j+1;
            j++;
        }
        else{
            while(j>0 && S[i] != S[j])
                j = lps[j-1];

            if(S[i] == S[j]){
                lps[i] = j+1;
                j++;
            }
            else{
                // j is already become 0 here
                lps[i] = 0;
            }
        }
    }

    return lps;
}

// lps fuction form CP algorithm.
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}



// KMP algo ( return all the indcies of the original string where pattern start to mathc.)
vector<int> KMP(string text, string pattern){

    vector<int> lps = computeLPS(pattern);
    vector<int> ans;

    int j = 0;
    for(int i=0; i<text.size(); i++){

        if(text[i] == pattern[j]){
            j++;
        }
        else{
            while(j>0 && text[i] != pattern[j]){
                j = lps[j-1];
            }

            if(text[i] == pattern[j]){
                j++;
            }
        }

        if(j == pattern.size()){
            ans.push_back(i-(j-1));
            j = 0;
        }
    }

    return ans;

}


int main(){

    string text = "Parth Patel Parth arth art h arthhh";
    string pattern = "arth";

    
    vector<int> ans = KMP(text, pattern);

    for(int i : ans){
        cout << i << endl;
    }
     

    // vector<int> ans = computeLPS(text);
    // vector<int> ans1 = prefix_function(s);
    
    // for(int i : ans)
    //     cout << i << " ";
    // cout << endl;

    // for(int i : ans1)
    //     cout << i << " ";
    // cout << endl;

    // bool flag = true;

    // for(int i=0; i<s.size(); i++){
    //     if(ans[i] != ans1[i]){
    //         flag = false;
    //         break;
    //     }
    // }
   
    // if(flag)
    //     cout << "they are same \n";
    // else    
    //     cout << "not same bro\n";

    return 0;
}