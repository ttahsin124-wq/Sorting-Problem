class Solution {
public:
    double trimMean(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    int n=arr.size();
    long long sum=0;
    for(int i=round(n*0.05);i<n-(n*0.05);i++)
    {
        sum+=arr[i];
    }   
    return sum/(n-n*0.1);
    }
};