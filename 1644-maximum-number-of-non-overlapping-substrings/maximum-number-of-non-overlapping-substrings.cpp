class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n);
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }
        vector<pair<int, int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (last[c] == -1)
                continue;
            int start = first[c];
            int end = last[c];
            bool valid = true;
            for (int i = start; i <= end; i++) {

                int x = s[i] - 'a';
                if (first[x] < start) {
                    valid = false;
                    break;
                }
                end = max(end, last[x]);
            }

            if (valid) {
                intervals.push_back({start, end});
            }
        }
        sort(intervals.begin(), intervals.end(),
             [](pair<int, int> a, pair<int, int> b) {
                 if (a.second != b.second)
                     return a.second < b.second;

                 return a.first > b.first;
             });

        vector<string> answer;
        int previousEnd = -1;
        for (auto interval : intervals) {
            int start = interval.first;
            int end = interval.second;
            if (start > previousEnd) {

                answer.push_back(s.substr(start, end - start + 1));

                previousEnd = end;
            }
        }
        return answer;
    }
};