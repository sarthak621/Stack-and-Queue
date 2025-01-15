class Solution {
public:
    
    vector<int>getPrefixMax(vector<int>& height){
        vector<int>prefixMax(height.size());
        prefixMax[0]=height[0];
        prefixMax.push_back(prefixMax[0]);
        for(int i=1;i<height.size();i++){
            prefixMax[i]=max(prefixMax[i-1],height[i]);
            prefixMax.push_back(prefixMax[i]);
        }
        return prefixMax;
    }

    vector<int>getSuffixMax(vector<int>& height){
        vector<int>suffixMax(height.size());
        suffixMax[height.size()-1]=height[height.size()-1];
        suffixMax.push_back(suffixMax[height.size()-1]);
        for(int i=height.size()-2;i>=0;i--){
            suffixMax[i]=max(suffixMax[i+1],height[i]);
            suffixMax.push_back(suffixMax[i]);
        }
        return suffixMax;
    }

    
    int trap(vector<int>& height) {
        //t.c O(3n) s.c O(2n)
        int total=0;
        vector<int>leftMax=getPrefixMax(height);
        vector<int>rightMax=getSuffixMax(height);
       

       for(int i=0;i<height.size();i++){
          total+=min(leftMax[i],rightMax[i])-height[i];
       }

       return total;
    }


};