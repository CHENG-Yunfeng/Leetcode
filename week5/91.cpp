#include<iostream>
#include<vector>

using namespace std;

// 解码方法
class Solution {
public:
    int numDecodings(string s) {
        int m = s.size();
        if (s[0] == '0') return 0;
        vector<int> dp(m + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 1; i < m; ++i) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2') {
                    dp[i+1] = dp[i-1];                 
                } else {
                    return 0;
                }
            } else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <='6')) {
                dp[i+1] = dp[i] + dp[i-1];
            } else {
                dp[i+1] = dp[i];
            }
        }
        return dp[m];
    }
};

int main() {
    Solution solution;
    string s = "226";
    int ans = solution.numDecodings(s);
    cout << ans << endl;
}