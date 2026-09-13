class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
    vector<int>even,odd;
    for(int x:nums)
    {
        if(x%2==0)   // for reminder sort by parity means even first then odd!
        {
            even.push_back(x);
        }
        else
        {
            odd.push_back(x);
        }
    }  
    even.insert(even.end(),odd.begin(),odd.end());
    return even;
    }
};