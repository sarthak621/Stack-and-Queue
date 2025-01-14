class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //hypothetically double the array 
        vector<int>ans;
        stack<int>st;
        int size=nums.size();

        for(int i=2*size-1;i>=0;i--){
            //pop case
            while(!st.empty() && st.top()<=nums[i%size]){
                st.pop();
            }

            //pushing in the ans. case when (i<size)
            if(i<size){
                if(st.empty()){
                    ans.push_back(-1);
                }
                else{
                     ans.push_back(st.top());
                }
            }

            //push case always occur
            // reverse(ans.begin(), ans.end());
            st.push(nums[i%size]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};