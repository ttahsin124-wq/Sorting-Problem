class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        for (int& x : arr) {
            x = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1;
        }
        return arr;
    }
};