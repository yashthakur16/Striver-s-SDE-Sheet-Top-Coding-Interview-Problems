class Solution {
public:

    void solve(vector<int> &nums,vector<vector<int>> &ans,vector<int> temp,int n,int i,int target)
    {
        if(target==0)
        {
            ans.push_back(temp);
        }
        for(int index=i;index<n;index++)
        {
            if(index!=i && nums[index]==nums[index-1]) continue;

            if(target>=nums[index])
            {
                temp.push_back(nums[index]);
                solve(nums,ans,temp,n,index+1,target-nums[index]);
                temp.pop_back();
            }
           
        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<int> temp;
        vector<vector<int>> ans;

        sort(candidates.begin(),candidates.end());

        solve(candidates,ans,temp,candidates.size(),0,target);

       
        return ans;
        
    }
};
