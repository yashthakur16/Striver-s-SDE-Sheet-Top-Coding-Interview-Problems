class Solution {
public:

    void solve(vector<vector<string>> &ans,vector<string> temp,int n,int index,string &s)
    {
        if(index==n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<n;i++)
        {
            if(isPalindrome(index,i,s))
            {
                temp.push_back(s.substr(index,i-index+1));
                solve(ans,temp,n,i+1,s);
                temp.pop_back();
            }
        }

        return ;
    }

    bool isPalindrome(int start,int end,string s)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
            {
                return false;
            }
            start++;
            end--;
          
        }

        return true;
    }

    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> temp;
        int n=s.size();
        solve(ans,temp,n,0,s);

        return ans;
        
    }
};
