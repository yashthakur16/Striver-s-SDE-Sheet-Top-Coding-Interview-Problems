class Solution {
public:


    void solve(vector<int> &nums, vector<vector<int>> &ans,int index, int n)
    {
        if(index==n)
        {
            ans.push_back(nums);
            return ;
        }

        for(int i=index;i<n;i++)
        {
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1,n);
            swap(nums[index],nums[i]);
        }

        return ;

    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        int n=nums.size();

        solve(nums,ans,0,n);

        return ans;
        
    }
};
