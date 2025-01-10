class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        //2 stack lena padega
        // s1 -> s2
        // x->s1
        //s2->s1

        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);

        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }

    }
    
    int pop() {
        
        int poppedElement=s1.top();
        s1.pop();
        return poppedElement;
    }
    
    int peek() {
        // Returns the element at the front of the queue
        return s1.top();
    }
    
    bool empty() {
        if(s1.size()) return false;
        return true;
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