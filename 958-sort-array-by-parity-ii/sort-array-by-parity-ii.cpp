class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int>even,odd;
        for(int x:nums)
        {
            if(x%2==0)
            {
                even.push_back(x);
            }
            else
            {
                odd.push_back(x);
            }
        }
        vector<int>ans;
        int i=0,j=0;
        while(i<even.size()&& j<odd.size())
        {
            ans.push_back(even[i++]);
            ans.push_back(odd[j++]);
        }
        return ans;
    }
};