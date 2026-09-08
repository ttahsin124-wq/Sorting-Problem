class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
    int n=score.size();
    vector<pair<int, int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({score[i],i});
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    vector<string>ans(n);
    for(int i=0;i<n;i++)
    {
        int original=v[i].second;
        if(i==0)
        {
            ans[original]="Gold Medal";
        }
        else if(i==1)
        {
            ans[original]="Silver Medal";
        }
        else if(i==2)
        {
            ans[original]="Bronze Medal";
        }
        else
        {
            ans[original]=to_string(i+1);
        }
    }
    return ans;
    }
};