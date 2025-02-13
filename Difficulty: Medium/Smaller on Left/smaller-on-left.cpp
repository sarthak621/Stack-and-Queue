//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        stack<int>st;
    // Allocate memory for the result array with the same size as input array
        vector<int>ans;
    
 
        
        for(int i=0;i<n;i++){
            
            while(!st.empty() && st.top()>=a[i]){
                st.pop();
            }
            
            if(st.empty()){
                ans.push_back(-1);
                
            }
            else if(st.top()<a[i]){
                ans.push_back(st.top());
                
            }
            st.push(a[i]);
            
        }
        return ans;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends