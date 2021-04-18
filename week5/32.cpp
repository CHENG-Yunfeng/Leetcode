#include<vector>
#include<stack>
#include<iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int m = s.size();
        int ans = 0;
        int count = 0;
        vector<vector<int>> dp(m, vector<int>(m,0));
        for (int i = 0; i < m; ++i) {
            stack<char> stk;
            int count = 0;
            for (int j = i; j < m; ++j) {
                if (s[j] == '(') {
                    stk.push(s[j]);
                    dp[i][j] = (i == j)? 0: dp[i][j-1];
                } else if (s[j] == ')') {
                    if (stk.size() == 0) {
                        dp[i][j] = 0;
                        break;
                    } else {
                        stk.pop();
                        count += 2;
                        if (stk.size() == 0) {
                            dp[i][j] = dp[i][j-1] + count;
                            count = 0;
                        } else {
                            dp[i][j] = dp[i][j-1];
                        }
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string s = ")(((((()())()()))()(()))(";
    cout << solution.longestValidParentheses(s) << endl;
}