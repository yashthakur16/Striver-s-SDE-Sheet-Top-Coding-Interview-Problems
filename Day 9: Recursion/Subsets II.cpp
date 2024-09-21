class Solution {
public:

    void solve(vector<int> &nums, vector<int> temp, vector<vector<int>> &ans,int index,int n)
    {
        ans.push_back(temp);
        for(int i=index;i<n;i++)
        {
            if(i!=index &&nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums,temp,ans,i+1,n);
            temp.pop_back();
        }

        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int> temp;
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        solve(nums,temp,ans,0,nums.size());

        return ans;
        
    }
};
