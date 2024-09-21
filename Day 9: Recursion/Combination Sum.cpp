class Solution {
public:

    void solve(vector<int>&candidates,vector<int> temp,vector<vector<int>> &ans,int target,int index,int n)
    {
       
            if(target==0)
            {
                ans.push_back(temp);
                return;
            }
            
            if(n==index)
            {
                return;
            }

            if(target<0)
            {
                return ;
            }


        if(target>=candidates[index])
        {
            temp.push_back(candidates[index]);
            solve(candidates,temp,ans,target-candidates[index],index,n);
            temp.pop_back();
            
        }
        
        solve(candidates,temp,ans,target,index+1,n);

        return;

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> temp;
        vector<vector<int>> ans;
        int n=candidates.size();

        solve(candidates,temp,ans,target,0,n);
        return ans;   
    }
};
