class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> st;

        for(auto i : nums)
        {
            st.insert(i);
        }
        
        int maxi=0;

        for(auto i : st)
        {
            if(st.find(i-1)==st.end())
            {
                int j=i;
                int cnt=1;
                while(st.find(j+1)!=st.end())
                {
                   
                    j++;
                    cnt++;
                               
                }
                maxi=max(cnt,maxi);
            }
        }

        return maxi;
        
    }
};
