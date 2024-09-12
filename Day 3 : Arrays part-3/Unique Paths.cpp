class Solution {
public:
    
    int solveT(int m,int n)
    {
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
       
        dp[m-1][n-1]=1;
        
         
       for(int currRow=m-2;currRow>=0;currRow--)
       {
          
           for(int currCol=n-2;currCol>=0;currCol--)
           {
              int   down=dp[currRow+1][currCol];
               int  right=dp[currRow][currCol+1];
               
               dp[currRow][currCol]=down+right;
           }
           
       }
        
        
         
        return dp[0][0];
    }
    
    
     int solveM(int m,int n,int currRow,int currCol,vector<vector<int>> &dp)
    {
        if(currRow==m-1 && currCol==n-1)
        {
            return 1;
        }
        if(currRow>=m)
        {
            return 0;
        }
        if(currCol>=n)
        {
            return 0;
        }
         
         if(dp[currRow][currCol]!=-1)
         {
             return dp[currRow][currCol];
         }
         
        int down=solveM(m,n,currRow+1,currCol,dp);
        int right=solveM(m,n,currRow,currCol+1,dp);
        
         dp[currRow][currCol]=down+right;
        return dp[currRow][currCol];
    }
    
    
    int solve(int m,int n,int currRow,int currCol)
    {
        if(currRow==m-1 && currCol==n-1)
        {
            return 1;
        }
        if(currRow>=m)
        {
            return 0;
        }
        if(currCol>=n)
        {
            return 0;
        }
        int down=solve(m,n,currRow+1,currCol);
        int right=solve(m,n,currRow,currCol+1);
        
        return down+right;
    }
    
    int uniquePaths(int m, int n) 
    {
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        // // return solve(m,n,0,0);
        // return solveM(m,n,0,0,dp);
        
        // return solveT(m,n);
        
    int N=m+n-2;
    int R=m-1;
    double ans=1;
    
    for(int i=1;i<=R;i++)
        {
            ans=ans*((N-R)+i)/i;
        }
    
    return (int)ans;
    }
};
