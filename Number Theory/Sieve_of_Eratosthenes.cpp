// Source: https://www.youtube.com/watch?v=yB57bcffJo4

#include<bits/stdc++.h>
using namespace std;

// Original Sieve
vector<int> sieve1(int num){
    
    int N = num + 1;
    vector<int> v;
    bool isPrime[N];
    
    for(int i=0; i<N; i++)
        isPrime[i] = true;
    
    // Special cases
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    
    // Original Sieve
    for(int i=2; i*i<N; i++){
        if(isPrime[i] == true){
            for(int j=i*i; j<N; j+=i)
                isPrime[j] = false;
        }
    }
    
    // make array of prime numbers
    for(int i=0; i<N; i++)
        if(isPrime[i] == true)
            v.push_back(i);
            
    return v;
}

 // Optimized Sieve of Eratosthenes
vector<int> sieve2(int num){
    
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
    
    int num = 100;
    
    vector<int> v = sieve1(num);
    
    cout << "List of prime numbres upto " << num << ": ";
    
    for(auto i=v.begin(); i!=v.end(); i++)
        cout << *i << " ";   

    return 0;
}
