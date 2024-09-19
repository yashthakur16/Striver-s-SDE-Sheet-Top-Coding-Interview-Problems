class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int cnt=0;
        int maxi=INT_MIN;

        for(auto i : nums)
        {
            if(i!=1)
            {
                cnt=0;
            }
            else
            {
                cnt++;
            }
            maxi=max(cnt,maxi);
        }

        return maxi;
        
    }
};
