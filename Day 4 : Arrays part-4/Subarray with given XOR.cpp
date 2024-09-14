int Solution::solve(vector<int> &A, int B) 
{
    unordered_map<int,int> mpp;
    int cnt=0;
    mpp[0]=1;
    int XR=0;
    
    for(auto i : A )
    {
        XR=XR^i;
        int x=XR^B;
       
        cnt=cnt+mpp[x];

         mpp[XR]++;

    }
    
    return cnt;
}
