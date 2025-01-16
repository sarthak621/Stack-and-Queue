class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){

            //when k is 1
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
            
            //we know that if the upcoming element is bigger then prev element then we pop our goal is to make 
            //bigger element at the front if the element is small then we dont have problem
            while(!dq.empty() && nums[dq.back()]<nums[i] ){
                     dq.pop_back();
            }

            dq.push_back(i);
            
            if(i>=k-1) ans.push_back(nums[dq.front()]);

    }
    return ans;
  }
};