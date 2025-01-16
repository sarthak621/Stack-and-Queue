class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        int maxArea=0;
        int nse;  //next smaller element
        int pse;  //previous smaller element
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int element=st.top();
                st.pop();
                nse=i;
                pse=st.empty()?-1:st.top();
                maxArea=max((heights[element]*(nse-pse-1)),maxArea);

            }
            st.push(i);
        }

        //if still elements left in stack
        while(!st.empty()){
            nse=n;
            int element=st.top();
            st.pop();

            pse=st.empty()?-1:st.top();
            maxArea=max((heights[element]*(nse-pse-1)),maxArea);
        }
        return maxArea;
    }
};

//BRUTEFORCE   T.C. o(n)


// class Solution {
// public:

//     vector<int>getPrevSmallerElement(vector<int>& heights,int n){
//         stack<int>st;
//         vector<int>prev;

//         for(int i=0;i<n;i++){
//             while(!st.empty() && heights[st.top()]>=heights[i]){
//                 st.pop();
//             }
//             if(st.empty()) prev.push_back(-1);
//             else{
//                 prev.push_back(st.top());
//             }
//             st.push(i);
//         }
//         return prev;
//     }

// //next small element
//         vector<int>getNextSmallerElement(vector<int>& heights,int n){
//         stack<int>st;
//         vector<int>next;

//         for(int i=n-1;i>=0;i--){
//             while(!st.empty() && heights[st.top()]>heights[i]){
//                 st.pop();
//             }
//             if(st.empty()) next.push_back(n);
//             else{
//                 next.push_back(st.top());
//             }
//             st.push(i);
//         }
//         reverse(next.begin(),next.end());
//         return next;
//     }

//     int largestRectangleArea(vector<int>& heights) {
//         int size=heights.size();
//         vector<int>prev=getPrevSmallerElement(heights,size);
//         vector<int>next=getNextSmallerElement(heights,size);
        
//         int area=0;
//         vector<int>ans;
//         for(int i=0;i<size;i++){
//               area=heights[i]*(next[i]-prev[i]-1);
//               ans.push_back(area);
//         }
//         return *max_element(ans.begin(),ans.end());
//     }
// };