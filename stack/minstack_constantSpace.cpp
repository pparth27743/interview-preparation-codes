#include<bits/stdc++.h>
using namespace std;


class MinStack {
    public:
    int minval;
    stack<int> s;

    MinStack(){ }

    void push(int x){
        if(s.size() == 0){
            s.push(x);
            minval = x;
        }
        else{
            if(x >= minval){
                s.push(x);
            }
            else{
                // push y = 2*x - minval
                s.push(2*x - minval);
                minval = x;
            }
        }
    }


    void pop(){
        if(s.size() == 0)
            return;
        else{
            if(s.top() >= minval){
                s.pop();
            }
            else{
                // we have to restore previous minval
                // minval = 2 * minval - s.top() 
                minval = 2*minval - s.top();
                s.pop();
            }
        }
    }

    int top(){
        if(s.size() == 0)
            return -1;
        
        if(s.top() >= minval)
            return s.top();
    
        return minval;
    }


    int getMin(){
        if(s.size() == 0)
            return -1;
        return minval;
    }

   
};


int main(){

    MinStack minstack;

    minstack.push(18);
    minstack.push(20);

    cout << minstack.getMin() << endl;

    minstack.push(15);

    cout << minstack.getMin() << endl;
    minstack.pop();
    minstack.push(13);

    cout << minstack.getMin() << endl;
    minstack.pop();

    minstack.push(23);

    minstack.pop(); 
    minstack.pop();
    cout << minstack.getMin() << endl;

    minstack.pop();
    cout << minstack.getMin() << endl;




    return 0;
}