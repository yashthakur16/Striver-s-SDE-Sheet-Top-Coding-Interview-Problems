class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        int N=numRows;
      vector<vector<int>> ans;
    vector<int> prev;

    for(int i=0;i<2&&i<N;i++)
    {
        vector<int>row(i+1);
        row[0]=1;
        row[i]=1;
        ans.push_back(row);
        prev=row;
    }



    for(int i=2;i<N;i++)
    {
        vector<int>row;
        row.push_back(1);
        for(int j=0;j<prev.size()-1;j++)
        {
            row.push_back(prev[j]+prev[j+1]);
        }
        row.push_back(1);
        prev.clear();

        prev=row;


        ans.push_back(row);
    }

    return ans;
    }
};
