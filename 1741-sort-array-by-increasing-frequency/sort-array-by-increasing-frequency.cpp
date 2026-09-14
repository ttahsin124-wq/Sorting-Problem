class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int x : nums)
            mp[x]++;
        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            if (a.second != b.second)
                return a.second < b.second;
            return a.first > b.first;
        });
        vector<int> result;
        for (auto& [val, cnt] : v) {
            for (int i = 0; i < cnt; i++)
                result.push_back(val);
        }
        return result;
    }
};