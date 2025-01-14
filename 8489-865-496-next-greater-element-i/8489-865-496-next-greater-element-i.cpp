class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int,int>mp;
        vector<int>ans;
        int n=nums2.size();

        //method of back traversal
        for(int i=n-1;i>=0;i--){
            //kis case me pop kare
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }

            // agar stack pura khali ho
            if(st.empty()) mp[nums2[i]]=-1;
            else {mp[nums2[i]]=st.top();}
            st.push(nums2[i]); //ye to karwana hi hai
        }

        for(int j=0;j<nums1.size();j++){
             ans.push_back(mp[nums1[j]]);
        }
        return ans;
    }
};

