// Source: https://www.youtube.com/watch?v=fByR5N-TseY

#include<bits/stdc++.h>
using namespace std;


 // Optimized Sieve of Eratosthenes
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

vector<unsigned long long> segmented_sieve(unsigned long long L, unsigned long long R){
    
    vector<unsigned long long> v;
    vector<int> primes;
    bool isPrime[R-L+1];
    
    for(int i=0; i<(R-L+1); i++)
        isPrime[i] = true;
    
    primes = sieve(sqrt(R));

    
    for(int i=0; i<primes.size(); i++){
        unsigned long long base = (L/primes[i])*primes[i];
        if(base < L)
            base += primes[i];
        
        for(auto j=base; j<=R; j+=primes[i])
            isPrime[j-L] = false;
            
        if(base == primes[i])
            isPrime[base - L] = true;
            
    }
    
    for(int i=0; i<(R-L+1); i++)
        if(isPrime[i] == true)
            v.push_back(i+L);
            
    if(v[0] == 1)
        v.erase(v.begin());
            
            
    return v;
}


int main(){
    
    unsigned long long int L,R;
    L = 1;
    R = 20;
    
    vector<unsigned long long> v = segmented_sieve(L, R);
    
    cout << "List of prime numbres between " << L << " to " << R << ": ";
    
    for(auto i=v.begin(); i!=v.end(); i++)
        cout << *i << " ";   

    return 0;
}
