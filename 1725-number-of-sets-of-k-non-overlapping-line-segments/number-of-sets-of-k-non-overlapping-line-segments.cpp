class Solution {
public:
    static const int MOD = 1e9 + 7;
    int numberOfSets(int n, int K) {
        vector<vector<long long>> dp(K + 1, vector<long long>(n, 0));
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;
        for (int k = 1; k <= K; k++) {
            vector<long long> suffix(n + 1, 0);
            for (int i = n - 1; i >= 0; i--) {
                suffix[i] = (suffix[i + 1] + dp[k - 1][i]) % MOD;
            }
            for (int i = n - 1; i >= 0; i--) {

                long long take = 0;

                if (i + 1 < n)
                    take = suffix[i + 1];

                long long skip = 0;

                if (i + 1 < n)
                    skip = dp[k][i + 1];

                dp[k][i] = (take + skip) % MOD;
            }
        }

        return dp[K][0];
    }
};