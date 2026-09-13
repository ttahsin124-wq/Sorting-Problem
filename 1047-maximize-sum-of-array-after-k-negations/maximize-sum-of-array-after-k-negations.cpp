class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
    int n=nums.size();
    int sum=0;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n && k>0;i++)
    {
        if(nums[i]<0)
        {
            nums[i]=-nums[i];
            k--;
        }
    }
    int mn=*min_element(nums.begin(),nums.end());
    for(int x:nums)
    {
        sum+=x;
    }
    if(k%2==1)
    {
        sum-=2*mn;
    }
    return sum;  
    }
};