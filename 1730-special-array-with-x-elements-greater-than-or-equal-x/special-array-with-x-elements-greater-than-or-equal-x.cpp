class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        for (int x = 0; x <= n; x++) {
            int count = 0;
            for (int v : nums) {
                if (v >= x) count++;
            }
            if (count == x) return x;
        }
        return -1;
    }
};