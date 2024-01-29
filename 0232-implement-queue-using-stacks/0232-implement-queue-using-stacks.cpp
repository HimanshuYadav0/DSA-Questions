#include <stack>

class MyQueue {
private:
    std::stack<int> inStack;  // Used for enqueueing
    std::stack<int> outStack; // Used for dequeueing

public:
    MyQueue() {
        
    }
    
    // Push element to the back of the queue
    void push(int x) {
        inStack.push(x);
    }
    
    // Remove the element from the front of the queue and return it
    int pop() {
        if (outStack.empty()) {
            // Transfer elements from inStack to outStack
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        
        // Pop from outStack
        int frontElement = outStack.top();
        outStack.pop();
        return frontElement;
    }
    
    // Return the element at the front of the queue
    int peek() {
        if (outStack.empty()) {
            // Transfer elements from inStack to outStack
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        
        // Peek from outStack
        return outStack.top();
    }
    
    // Check if the queue is empty
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */