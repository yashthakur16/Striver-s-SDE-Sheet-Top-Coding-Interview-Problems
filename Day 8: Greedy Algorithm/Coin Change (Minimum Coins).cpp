//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    int solve(vector<int> &coins,int sum,vector<int> &dp)
    {
        if(sum==0)
        {
            return 0;
        }
        if(sum<0)
        {
            return INT_MAX;
        }
        
        if(dp[sum]!=-1)
        {
            return dp[sum];
        }
        
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int ans=solve(coins,sum-coins[i],dp);
            if(ans!=INT_MAX)
            mini=min(mini,ans+1);
            dp[sum]=mini;
        }
        
        return dp[sum];
    }
  public:
    int minCoins(vector<int> &coins, int sum) {
        vector<int> dp(sum+1,-1);
        int ans=solve(coins,sum,dp);
        if(ans==INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends
