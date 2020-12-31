#include <iostream>
using namespace std;

int sumOfDigits(int n){ 
    
    int sum=0;
    while(n!=0){
        sum += (n%10);
        n = n/10;
    }
    return sum;
} 

int main() {
    
    std::cout << sumOfDigits(123456) << std::endl;
    
	return 0;
	
}
