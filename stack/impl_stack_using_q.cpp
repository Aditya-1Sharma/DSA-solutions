// Implement a last-in-first-out (LIFO) stack using only two queues. 
// The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

// Implement the MyStack class:

// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.

#include <bits/stdc++.h>
using namespace std;

class MyStack {
    queue<int>q1;
    queue<int>q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()!=1){
            q2.push(q1.front());
                q1.pop();
        }
        int x=q1.front();
        q1.pop();
        swap(q1,q2);
        return x;
        
    }
    
    int top() {
        while(q1.size()!=1){
            q2.push(q1.front());
                q1.pop();
        }
        int x=q1.front();
        q1.pop();
        swap(q1,q2);
        q1.push(x);
        return x;
        
    }
  bool empty() {
        return(q1.empty() && q2.empty());
            
    }
};

int main() {
    MyStack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << s.top() << endl;
    
    s.pop();
    cout << s.top() << endl;
    
    s.pop();
    cout << s.empty() << endl;
    
    s.pop();
    cout << s.empty() << endl;
    
    return 0;
}
