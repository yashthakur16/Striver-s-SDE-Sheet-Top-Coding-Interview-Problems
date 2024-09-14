//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) 
    {
        long long sum=0;
        int maxi=0;
        
        unordered_map<long long,int> mpp;
        
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i];
            
            
            if(sum==0)
            {
                maxi=max(maxi,i+1);
                mpp[sum]=i;
            }
            else if(mpp.find(sum)!=mpp.end())
            {
                maxi=max(maxi,i-mpp[sum]);
            }
            else
            {
                mpp[sum]=i;
            }
            
            
        }
       
       return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
