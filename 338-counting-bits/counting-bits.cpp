class Solution {
public:
    vector<int> countBits(int n) {
      vector<int>ans(n+1,0);
      {
        for(int i=1;i<=n;i++)
        {
            ans[i]=ans[i>>1]+(i & 1); // here i>>1 cut last bit from binary
        }
        return ans;
      }  
    }
};