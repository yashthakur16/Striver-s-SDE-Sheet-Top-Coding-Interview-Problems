//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
    bool isSafe(vector<vector<int>> &mat,int row,int col,int n)
    {
        if(row==n||col==n||row<0||col<0||mat[row][col]==0)
        {
            return false;
        }
        
        return true;
    }
  
    void solve(vector<vector<int>> &mat, vector<string> &ans, string temp,int row,int col,int n)
    {
        if(row==n-1 && col==n-1)
        {
            ans.push_back(temp);
            return ;
        }
        
        mat[row][col]=0;
        
        //down
        if(isSafe(mat,row+1,col,n))
        {
            temp.push_back('D');
            solve(mat,ans,temp,row+1,col,n);
            temp.pop_back();
        }
        
        //right
        if(isSafe(mat,row,col+1,n))
        {
            temp.push_back('R');
            solve(mat,ans,temp,row,col+1,n);
            temp.pop_back();
        }
        
        //up
        if(isSafe(mat,row-1,col,n))
        {
            temp.push_back('U');
            solve(mat,ans,temp,row-1,col,n);
            temp.pop_back();
        }
        
        //left
        if(isSafe(mat,row,col-1,n))
        {
            temp.push_back('L');
            solve(mat,ans,temp,row,col-1,n);
            temp.pop_back();
        }
        
        mat[row][col]=1;
        
        return ;
    }
  
    vector<string> findPath(vector<vector<int>> &mat) 
    {
        int n=mat.size();
        if(mat[n-1][n-1]==0 || mat[0][0]==0)
        {
            return {"-1"};
        }
        
        vector<string> ans;
        string temp;
        solve(mat,ans,temp,0,0,n);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
