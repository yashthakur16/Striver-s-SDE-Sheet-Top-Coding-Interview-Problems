class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int n=nums.size();
        int el1=INT_MIN;
        int el2=INT_MIN;
        int cnt1=0;
        int cnt2=0;
        
        for(auto i : nums)
        {
            if(cnt1==0 && i!=el2)
            {
                cnt1++;
                el1=i;
            }
            else if(cnt2==0 && i!=el1)
            {
                cnt2++;
                el2=i;
            }
            else if(el1==i)
            {
                cnt1++;
            }
            else if(el2==i)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1=0;
        cnt2=0;
        
        for(auto i: nums)
        {
            if(i==el1)
            {
                cnt1++;
            }
            else if(i==el2)
            {
                cnt2++;
            }
        }
        
        if(cnt1>n/3 && cnt2>n/3)
        {
            return {el1,el2};
        }
        else if(cnt1>n/3)
        {
            return {el1};
        }
        else if(cnt2>n/3)
        {
            return {el2};
        }
        
        return {};
    }
};
