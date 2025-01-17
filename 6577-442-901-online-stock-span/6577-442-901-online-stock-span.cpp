class StockSpanner {
public:


    int index=-1;
    stack<pair<int,int>>st;  // value,index
    int ans;
    StockSpanner() {
         
    }
    
    int next(int price) {
        index+=1;

        //using the concept of previous greatest element
        while(!st.empty() && st.top().first<=price) {st.pop();}

        ans=index-(st.empty()?-1:st.top().second); //current index-pge[i]
        
        //push into stack pair of value : curr value and its pge index
        st.push({price,index});

        return ans;

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */