class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx = max_element(nums.begin(), nums.end()) - nums.begin();

        vector<int> temp = nums;
        sort(temp.begin(), temp.end(), greater<int>());

        if (temp[0] >= 2 * temp[1])
            return idx;

        return -1;
    }
};