class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int l=0;
        int r=0;
        int maxi=0;

        int n=s.size();
        unordered_map<char,int> mpp;

        while(r<n)
        {
            if(mpp.find(s[r])!=mpp.end())
            {
                l=max(l,mpp[s[r]]+1);
            }
           
            maxi=max(maxi,r-l+1);
            mpp[s[r]]=r;
            r++;

        }

        return maxi;

        
    }
};
