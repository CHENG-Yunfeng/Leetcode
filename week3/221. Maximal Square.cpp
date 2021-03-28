class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int area = INT_MIN;
        for (int i = 0; i < m; ++i) {
            for (int j =0; j < n; ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = (matrix[i][j] == '1')? 1:0;
                } else {
                    dp[i][j] = (matrix[i][j] == '1')? min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1: 0;
                }
                area = max(area, dp[i][j] * dp[i][j]);
            }
        }
        return area;
    }
};