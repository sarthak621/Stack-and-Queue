class Solution {
public:
    bool isValid(string s) {
        //first declare the stack data structure
        stack<int>st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' ||s[i]=='{'){
                st.push(s[i]);
            }
            else{
                //check it is empty...if it is empty direct return false
                if(st.empty()) return false; 
                
                char topEl=st.top();
                st.pop();

                if(s[i]==')' && topEl=='(' || s[i]==']' && topEl=='[' || s[i]=='}' && topEl=='{') continue;
                else{
                    return false;
                }
            }
        }

        if(st.empty()) return true;
        else{
            return false;
        }

    }
};