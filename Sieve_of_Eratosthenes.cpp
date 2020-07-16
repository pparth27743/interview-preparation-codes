#include<iostream>
using namespace std;

void sieve_of_prime(int arr[], int N){
    
   // Mark all the odd numbers as prime 
    for(int i=3; i<N; i+=2)
        arr[i] = 1;
        
    // Sieve of Eratosthenes
    for(int i=3; i<N; i+=2){
        if(arr[i] == 1){
            for(int j=i*i; j<N; j+=i)
                arr[j] = 0;
        }
    }
        
    // Special cases
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    
}



int main(){
    
    int N = 100;
    int arr[N] = {0};
    
    sieve_of_prime(arr, N);
    
    cout << "List of prime numbres upto " << N << ": ";
    
    for(int i=0; i<N; i++)
        if(arr[i] == 1)
            cout << i << " ";

    return 0;
}
