#include<bits/stdc++.h>
using namespace std;

vector<int> sieve(int N){
    
    bool isPrime[N+1] = {false};
    vector<int> v;
    
   // Mark all the odd numbers as prime 
    for(int i=3; i<N+1; i+=2)
        isPrime[i] = true;
        
    // Sieve of Eratosthenes
    for(int i=3; i*i<N+1; i+=2){
        if(isPrime[i] == 1){
            for(int j=i*i; j<N; j+=i)
                isPrime[j] = false;
        }
    }
        
    // Special cases
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    
    
    // make isPrimeay of prime numbers
    for(int i=0; i<N; i++)
        if(isPrime[i] == true)
            v.push_back(i);
            
    return v;
    
}


int main(){
    
    int N = 30;
    
    vector<int> v = sieve(N);
    
    cout << "List of prime numbres upto " << N << ": ";
    
    for(auto i=v.begin(); i!=v.end(); i++)
        cout << *i << " ";   

    return 0;
}
