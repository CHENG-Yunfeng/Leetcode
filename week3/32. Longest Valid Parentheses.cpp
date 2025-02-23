class Solution {
public:
    int longestValidParentheses(string s) {
        int m = s.size();
        vector<int> dp(m, 0);
        int ans = 0;
        for (int i = 1; i < m; ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = (i-2 >= 0? dp[i-2]: 0) + 2;
                } else if (i - dp[i-1] - 1 >= 0 && s[i-dp[i-1] - 1] == '(') {
                    dp[i] = dp[i-1] + 2 + (i - dp[i-1] - 2 >= 0? dp[i - dp[i-1] -2]: 0);
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};