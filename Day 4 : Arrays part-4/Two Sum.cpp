class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> mpp;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            int compli=target-nums[i];
            if(mpp.find(compli)!=mpp.end())
            {
                return {mpp[compli],i};
            }
           
                mpp[nums[i]]=i;
        }

        return {};
        
    }
};
