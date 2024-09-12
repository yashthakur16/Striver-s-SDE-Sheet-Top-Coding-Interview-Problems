class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int count=0;
        int element=0;
        
        for(auto i : nums)
        {
            if(count==0)
            {
                element=i;
                count++;
            }
            else if(element==i)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        
        return element;
    }
};
