class Solution {
public:
    int hIndex(vector<int>& citations) {
    int n=citations.size();
    int ans=0;
    for(int h=1;h<=n;h++)
    {
        int cnt=0;
        for(int citation:citations)
        {
            if(citation>=h)
            {
                cnt++;
            }
        }
        if(cnt>=h)
        {
            ans=h;
        }
    }  
    return ans;
    }
};