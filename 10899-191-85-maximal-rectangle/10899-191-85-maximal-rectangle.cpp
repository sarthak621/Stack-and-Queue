class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        int maxArea=0;
        int nse;  //next smaller element
        int pse;  //previous smaller element
        for(int i=0;i<n;i++){
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> psum(rows, vector<int>(cols, 0));  //prefix sum
        
        int sum=0;
        for(int j=0;j<cols;j++){
           sum=0;
           for(int i=0;i<rows;i++){
             if(matrix[i][j]=='0') sum=0;
             else sum+=1;
             psum[i][j]=sum;
           }
        }

        //assume each row a histogram rectangles
        int maxArea=0;
        for(int i=0;i<rows;i++){
                maxArea=max(maxArea,largestRectangleArea(psum[i]));  //first row return ho jayega
        }
        return maxArea;
    }
};

