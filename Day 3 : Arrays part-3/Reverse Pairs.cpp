
class Solution {
public:
    
    void merge(vector<int> & nums, int start,int end,int &cnt)
{
    int mid=start+((end-start)/2);
    int length1=mid-start+1;
    int length2=end-mid;

    vector<int> arr1(length1,0);
    vector<int> arr2(length2,0);

    int index=start;

    for(int i=0;i<length1;i++)
    {
        arr1[i]=nums[index++];
    }
    for(int i=0;i<length2;i++)
    {
        arr2[i]=nums[index++];
    }

    index=start;

    int i=0;
    int j=0;
    

    while(i<length1 && j<length2)
    {
        if(arr1[i]<arr2[j])
        {
            nums[index++]=arr1[i++];
        }
        else
        {
            nums[index++]=arr2[j++];
        }
        
    }

    int right=0;

   for(int i=0;i<length1;i++)
   {
    while(right<length2 && arr1[i]>(long long)2*arr2[right]) 
    {
        right++;
    }

    cnt=cnt+right;
   }
        
    

    while(i<length1)
    {
        nums[index++]=arr1[i++];
    }

    while(j<length2)
    {
        nums[index++]=arr2[j++];
    }

    return ;
}
    
    void mergeSort(vector<int> &nums, int start,int end,int &cnt)
    {
        if(start>=end)
        {
            return ;
        }
        int mid=start+((end-start)/2);

        mergeSort(nums,start,mid,cnt);
        mergeSort(nums,mid+1,end,cnt);

       return merge(nums,start,end,cnt);

        
        
    }
    
    int reversePairs(vector<int>& nums) 
    {
        int cnt=0;
        int n=nums.size();
        mergeSort(nums,0,n-1,cnt);
        return cnt;
        
    }
};
