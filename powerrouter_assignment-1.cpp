#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    //Initializing Queues
    queue<int> q1;
    queue<int> q2;

    //PUSH OPERATION
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());    q1.pop();
        }
        swap(q1, q2);
    }
    
    //POP OPERATION
    int pop() {
        int result = top();
        q1.pop();
        return result;
    }
    
    //TOP OPERATION
    int top() {
        return q1.front();
    }
    

    //CHECK WHETHER STACK IS EMPTY
    bool empty() {
        return q1.empty();
    }
};







int main()
{
    MyStack S;
    S.push(5);
    S.push(10);
    S.push(15);

    cout<<S.top()<<endl;
    S.pop();
    cout<<S.top()<<endl;
    cout<<S.empty()<<endl;


    return 0;
}