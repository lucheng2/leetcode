#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

class MyQueue {
public:
    stack<int> inStack;
    stack<int> outStack;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inStack.emplace(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(outStack.empty()) {
            while(!inStack.empty()) {
                outStack.emplace(inStack.top());
                inStack.pop();
            }
        } 
        int top = outStack.top();
        outStack.pop();
        return top;

    }
    
    /** Get the front element. */
    int peek() {
        if(outStack.empty()) {
            while(!inStack.empty()) {
                outStack.emplace(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();

    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
	
	return 0;
}
