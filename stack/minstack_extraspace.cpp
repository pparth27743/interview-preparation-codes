#include<bits/stdc++.h>
using namespace std;


class MinStack {
    public:
    stack<int> s,ss;

    MinStack(){ }

    void push(int x){
        s.push(x);
        if(ss.size() == 0 || x <= ss.top())
            ss.push(x);
    }


    int pop(){
        if(s.size() == 0)
            return -1;

        int ans = s.top();
        s.pop();
        if(ss.top() == ans)
            ss.pop();
        
        return ans;
    }

    int getMin(){
        if(ss.size() == 0)
            return -1;
        
        return ss.top();
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