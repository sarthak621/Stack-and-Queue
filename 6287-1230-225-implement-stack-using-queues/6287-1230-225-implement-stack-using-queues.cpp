class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        int s=q.size();
        //queue me simply push kar do pehle
        q.push(x);

        //ab jo elements pehle se pushed hai unko jo abhi element push hua h unke bad karo
        for(int i=1;i<=s;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int topElement=q.front();
        q.pop();
        return topElement;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size()!=0) return false;
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */