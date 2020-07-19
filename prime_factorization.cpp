// Prime factorization using sieve

#include<bits/stdc++.h>
using namespace std;

vector<int> sieve(int num){
    
    int N = num + 1;
    vector<int> v;
    bool isPrime[N]={false};
    
   // Mark all the odd numbers as prime 
    for(int i=3; i<N; i+=2)
        isPrime[i] = true;
        
    // Optimized Sieve of Eratosthenes
    for(int i=3; i*i<N; i+=2){
        if(isPrime[i] == true){
            for(int j=i*i; j<N; j+=i)
                isPrime[j] = false;
        }
    }
    
    // Special cases
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;

    // make array of prime numbers
    for(int i=0; i<N; i++)
        if(isPrime[i] == true)
            v.push_back(i);
            
    return v;
}


int main(){

    unsigned long long int n = 12234246;

    map<int,int> m;
    vector<int> v = sieve(n);

    for(auto i=v.begin(); i!=v.end(); i++){
        while(n%(*i) == 0){
            n = n/(*i);
            if(m.find(*i) == m.end())
                m[*i] = 1;
            else
                m[*i] += 1;
        }
    }    

    cout << "Prime -> Power" << endl;
    for(auto i=m.begin(); i!=m.end(); i++)
        cout << i->first << " -> " << i->second << endl;
    

    return 0;
}
