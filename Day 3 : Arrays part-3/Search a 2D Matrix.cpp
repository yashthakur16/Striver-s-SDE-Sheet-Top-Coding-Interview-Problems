class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n=matrix.size()*matrix[0].size();
        int start=0;
        int end=n;
        int mid=start+((end-start)/2);
        int col=matrix[0].size();
        int column=mid%col;
        int row=mid/col;
        
        while(start<end)
        {
            if(matrix[row][column]==target)
            {
                return true;
            }
            else if(matrix[row][column]>target)
            {
                end=mid;
            }
            else
            {
                start=mid+1;
            }
            
            mid=(start+end)/2;
            column=mid%col;
            row=mid/col;
        }
        
        return false;
    }
};
