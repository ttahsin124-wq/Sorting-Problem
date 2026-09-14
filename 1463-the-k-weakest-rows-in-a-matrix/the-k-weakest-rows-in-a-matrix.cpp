class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int n=mat.size();
    vector<pair<int,int>>rows;
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j]== 1) 
            {
                cnt++;
            }
            else break;
        }
        rows.push_back({cnt,i});
    }  
    sort(rows.begin(),rows.end());
    vector<int>result;
    for(int i=0;i<k;i++)
    {
        result.push_back(rows[i].second);
    }
    return result;
    }
};