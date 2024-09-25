//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int ub(vector<int> &nums,int target)
    {
        int start=0;
        int end=nums.size()-1;
        int mid=(start+end)/2;
        int ans=end+1;
        
        while(start<=end)
        {
           if(nums[mid]>target)
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
            mid=(start+end)/2;
        }
        
        return ans;
    }



    int cnt(vector<vector<int>> &matrix,int x)
    {
        int count=0;
        for(int i=0;i<matrix.size();i++)
        {
            count=count+ub(matrix[i],x);
        }
        
        return count;
        
    }
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int req=(R*C)/2;
        int low=INT_MAX;
        int high=INT_MIN;
        
        for(int i=0;i<R;i++)
        {
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][C-1]);
        }
        
        int mid=(low+high)/2;
        
        while(low<=high)
        {
            int smallEquals=cnt(matrix,mid);
            
            if(smallEquals<=req)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
            mid=(low+high)/2;
        }
        return low;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends
