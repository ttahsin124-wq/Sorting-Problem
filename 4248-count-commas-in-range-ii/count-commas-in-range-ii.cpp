class Solution {
public:
    long long countCommas(long long n) {
    long long ans=0;
    long long int thresh=1000;
    while(thresh<=n)
    {
        ans+=(long long)n-thresh+1;
        thresh*=1000;
    }
    return ans;
    }
};