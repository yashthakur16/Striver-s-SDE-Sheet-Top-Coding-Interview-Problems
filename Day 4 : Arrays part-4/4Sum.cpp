class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i=0;i<n-3;i++)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;

            for(int j=i+1;j<n-2;j++)
            {
                if(j!=i+1 && nums[j-1]==nums[j]) continue;

                int k=j+1;
                int l=n-1;
                while(k<l)
                {
                    if(k!=j+1&&nums[k]==nums[k-1])
                    {
                        k++;
                        continue;
                    } 

                    if(l!=n-1 && nums[l]==nums[l+1])
                    {
                        l--;
                        continue;
                    } 

                    long long sum=nums[i]+nums[j];
                    sum=sum+nums[k];
                    sum=sum+nums[l];

                    if(sum==target)
                    {
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                       k++;
                       l--;
                    }
                    else if(sum>target)
                    {
                        l--;
                    }
                    else
                    {
                        k++;
                    }

   

                }
            }
        } 

        return ans;   
    }
};
