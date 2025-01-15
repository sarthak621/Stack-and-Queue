class Solution {
public:

    // for maximum subarray 
     vector<long long int>getNextGreatIndex(vector<int>& arr,long long int n){
        stack<long long int>st;
        vector<long long int>next;
        for(long long int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){  
                st.pop();
            }

            if(st.empty()){
                next.push_back(n);
            }
            else{
                next.push_back(st.top());
            }

            st.push(i);
        }
        reverse(next.begin(),next.end());
        return next;
    }
    
    vector<long long int>getPrevGreatIndex(vector< int>& arr,long long int n){
        stack<long long int>st;
        vector<long long int>prev;
        for(long long int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){  // don't take >= as we have to consider for smaller equal element also eg [1,1,1]
                st.pop();
            }

            if(st.empty()){
                prev.push_back(-1);
            }
            else{
                prev.push_back(st.top());
            }

            st.push(i);
        }
        return prev;
    }

    long long int sumSubarrayMax(vector<int>& arr) {
        long long int mod=int(1e9+7);
        long long int n=arr.size();
        vector<long long int>previousGreaterElementIndex=getPrevGreatIndex(arr,n);
        vector<long long int>nextGreaterElementIndex=getNextGreatIndex(arr,n);

        long long int total=0;

        for(long long int i=0;i<n;i++){
            long long left=i-previousGreaterElementIndex[i];
            long long right=nextGreaterElementIndex[i]-i;

            total = (total +(left*right*arr[i]));
        }
        return total;

    }


    //For minimum subarray
    vector<long long int>getNextSmallIndex(vector<int>& arr,long long int n){
        stack<long long int>st;
        vector<long long int>next;
        for(long long int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){  
                st.pop();
            }

            if(st.empty()){
                next.push_back(n);
            }
            else{
                next.push_back(st.top());
            }

            st.push(i);
        }
        reverse(next.begin(),next.end());
        return next;
    }
    
    vector<long long int>getPrevSmallIndex(vector<int>& arr,long long int n){
        stack<long long int>st;
        vector<long long int>prev;
        for(long long int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){  // don't take >= as we have to consider for smaller equal element also eg [1,1,1]
                st.pop();
            }

            if(st.empty()){
                prev.push_back(-1);
            }
            else{
                prev.push_back(st.top());
            }

            st.push(i);
        }
        return prev;
    }

    long long int sumSubarrayMins(vector<int>& arr) {
        long long int mod= int(1e9+7);
        long long int n=arr.size();
        vector<long long int>previousSmallerElementIndex=getPrevSmallIndex(arr,n);
        vector<long long int>nextSmallerElementIndex=getNextSmallIndex(arr,n);

        long long int total=0;

        for(long long int i=0;i<n;i++){
            long long left=i-previousSmallerElementIndex[i];
            long long right=nextSmallerElementIndex[i]-i;

            total = (total +(left*right*arr[i]));
        }
        return total;

    }
    long long subArrayRanges(vector<int>& nums) {
        long long int min=sumSubarrayMins(nums);
         long long int max=sumSubarrayMax(nums);

         return max-min;
    }
};