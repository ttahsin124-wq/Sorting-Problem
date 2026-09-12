class Solution {
public:
    struct Node {
        long long score;
        vector<int> idxs;

        Node(long long s = -1) : score(s) {}
    };

    int n;
    vector<int> nextIndex;
    vector<vector<Node>> dp;

    int findNext(vector<vector<int>>& arr, int endPoint) {
        int l = 0, r = n - 1;
        int ans = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid][0] > endPoint) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    Node solve(vector<vector<int>>& arr, int i, int k) {

        if (k == 0 || i >= n) {
            Node base(0);
            return base;
        }

        if (dp[i][k].score != -1)
            return dp[i][k];

        Node skip = solve(arr, i + 1, k);

        Node temp = solve(arr, nextIndex[i], k - 1);

        Node take;
        take.score = temp.score + arr[i][2];
        take.idxs = temp.idxs;
        take.idxs.push_back(arr[i][3]);

        sort(take.idxs.begin(), take.idxs.end());

        Node res;

        if (take.score > skip.score) {
            res = take;
        }
        else if (take.score < skip.score) {
            res = skip;
        }
        else {
            res = (take.idxs < skip.idxs) ? take : skip;
        }

        return dp[i][k] = res;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i); 
        }

        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] < b[1];
                return a[0] < b[0];
            });

        nextIndex.resize(n);

        for (int i = 0; i < n; i++) {
            nextIndex[i] = findNext(intervals, intervals[i][1]);
        }

        dp.assign(n + 1, vector<Node>(5, Node(-1)));

        return solve(intervals, 0, 4).idxs;
    }
};