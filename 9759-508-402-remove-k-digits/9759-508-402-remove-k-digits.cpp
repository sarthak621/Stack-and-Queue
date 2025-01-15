class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.length();i++){
               while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;
               }
               st.push(num[i]);
        }

        //if still k is not zero
        while(k>0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        vector<char>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        while(!res.empty() && res.back()=='0'){
            res.pop_back();
        }

        // reverse(res.begin(),res.end());

        if(res.empty()) return "0";
        reverse(res.begin(),res.end());
         return string(res.begin(), res.end());
    }
};