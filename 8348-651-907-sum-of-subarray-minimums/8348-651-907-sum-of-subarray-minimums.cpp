class Solution {
public:


    vector<int>getNextSmallIndex(vector<int>& arr,int n){
        stack<int>st;
        vector<int>next;
        for(int i=n-1;i>=0;i--){
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
    
    vector<int>getPrevSmallIndex(vector<int>& arr,int n){
        stack<int>st;
        vector<int>prev;
        for(int i=0;i<n;i++){
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

    int sumSubarrayMins(vector<int>& arr) {
        int mod=int(1e9+7);
        int n=arr.size();
        vector<int>previousSmallerElementIndex=getPrevSmallIndex(arr,n);
        vector<int>nextSmallerElementIndex=getNextSmallIndex(arr,n);

        int total=0;

        for(int i=0;i<n;i++){
            long long left=i-previousSmallerElementIndex[i];
            long long right=nextSmallerElementIndex[i]-i;

            total = (total +(left*right*arr[i])%mod)%mod;
        }
        return total;

    }
};