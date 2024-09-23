class Solution {
public:

    bool isSafe(vector<string> board,int row,int col,int n)
    {
        for(int i=col;i>=0;i--)
        {
            if(board[row][i]=='Q')
                return false;
        }

        int i=row;
        int j=col;

        while(i>=0 && j>=0)
        {
            if(board[i][j]=='Q')
                return false;

            i--;
            j--;
        }

        i=row;
        j=col;

        while(i<n && j>=0)
        {
            if(board[i][j]=='Q')
                return false;

            i++;
            j--;
        }

        return true;
    }


    void solve(vector<vector<string>> &ans,vector<string> board,int row,int col,int n)
    {
        if(row==n || col==n)
        {
            ans.push_back(board);
            return ;
        }

        for(int i=0;i<n;i++)
        {
            if(isSafe(board,i,col,n))
            {
                board[i][col]='Q';
                solve(ans,board,i,col+1,n);
                board[i][col]='.';
            }
        }

        return ;
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n);
        string s(n,'.');

        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }

        vector<vector<string>> ans;

        solve(ans,board,0,0,n);
        
        return ans;
        
    }
};
