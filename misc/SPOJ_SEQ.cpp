
//Matrix Multiplication and Power of Matrix

// This is the solution of the SPOJ Problem SEQ - Recursive Sequence
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_SIZE 10
#define MOD 1000000000

int size;

// This is a structure for Matrix
struct Matrix{
    
    unsigned long long int M[MAX_SIZE][MAX_SIZE];
    
    // Constructure 
    Matrix() {
        memset(M,0,sizeof(M));
    }
    
    // Method to make zero Matrix
    void zeroMat() {
        memset(M,0,sizeof(M));
    }
    
    // Method to make identity Matrix
    void identity(){
        for(int i = 0; i<size; i++) M[i][i] = 1; 
    } 
    
};

//  Matrix multiplication (Here &s1 means it is call by reference)
void mul(Matrix &s1, Matrix &s2, Matrix &res){
    
    res.zeroMat();
    
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            for(int k=0; k<size; k++){
                res.M[i][j] = (res.M[i][j] + s1.M[i][k]*s2.M[k][j])%MOD;
            }
        }
    }
}

// Binary exponentiation of Matrix
// Result is returned as user define datatype 'Matrix' (just like we retur int/float/char )
Matrix power(Matrix &M, int n){
    
    Matrix res, mul_res;
    
    if(n==0){
        res.identity();
        return res;
    } 
    else if(n==1){
        return M;
    }
    else{
        if(n&1){
            res = power(M,n/2);
            mul(res,res,mul_res);
            mul(mul_res,M,res);
            return res;
        }
        else{
            res = power(M,n/2);
            mul(res,res,mul_res);
            return mul_res;
        }
    }
}

int main(){
    
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++){
        
        cin >> size;
        int b[size], c[size];
        
        for(int i=0; i<size; i++)
            cin >> b[i];
        
        for(int i=0; i<size; i++)
            cin >> c[i];
        
        int n;
        cin >> n;
        
        Matrix Tras, tmp;
        
        for(int i=0; i<size-1; i++)
                Tras.M[i][i+1] = 1;
        for(int i=0; i<size; i++)
                Tras.M[size-1][i] = c[(size-1)-i];        
            
        if(n <= size){
            cout << b[n-1] << endl;
        }
        else{
            tmp = power(Tras,n-size);
            
            unsigned long long int ans = 0;
            
            for(int i=0; i<size; i++){
                ans = (ans + tmp.M[size-1][i]*b[i])%MOD;
            }
            cout << ans << endl;
        }
        
    // // For printing the Matrix     
  
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                cout << tmp.M[i][j] << " ";
            }
            cout << "\n";
        }   
    } 
    return 0;
}
