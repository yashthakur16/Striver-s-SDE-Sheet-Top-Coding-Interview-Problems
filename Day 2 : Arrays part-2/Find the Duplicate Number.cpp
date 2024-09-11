class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int slow=nums[0];
        int fast=nums[0];
        
        while(true)
        {
            
            slow=nums[slow];
            fast=nums[fast];
            fast=nums[fast];
            if(slow==fast)
            {
                break;
            }
        }
        slow=nums[0];
        
        while(true)
        {
            if(slow==fast)
            {
                return slow;
            }
            slow=nums[slow];
            fast=nums[fast];
        }
        
        return -1;
        
    }
};
