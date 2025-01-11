class MinStack {
public:
 
   //approach 2: having S.C. 0(n) T.C O(1)
    MinStack() {
        
    }
    stack<long long int>st;
    long long int mini=INT_MAX;
    void push(long long int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val>mini){
                st.push(val);
            }
            else{
                st.push(2*val-mini);   //we do this bcoz after this if we have to going to pop
                mini=val;
            }
        }
    }
    
    void pop() {
        if(!st.empty()){
            long long int x=st.top();
            st.pop();

            //update the mini
            if(x<mini){
                mini=mini*2-x;
            }
        }
    }
    
    int top() {
        if(st.empty()) return -1;
        
       long long int x=st.top();
        if(x>mini){
            return x;
        }
        else{
            return mini;
        }
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */