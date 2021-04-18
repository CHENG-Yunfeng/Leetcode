#include<iostream>
#include<vector>

using namespace std;

// 最长回文字串
class Solution {
public:
    string longestPalindrome(string s) {
        int maxlength = 1;
        string ans = s;
        for (int i = 0;i < s.size() - 1; ++i) {
            string oddstring = expandCenter(s, i, i);
            string evenstring = expandCenter(s, i, i+1);
            string maxstring = (oddstring.size() > evenstring.size())? oddstring: evenstring;
            if (maxstring.size() >= maxlength) {
                maxlength = maxstring.size();
                ans = maxstring;
            }
        }
        return ans;
    }

    string expandCenter(string& s, int l, int r) {
        while (l >=0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - 1 -l);
    }
    
};

int main() {
    Solution solution;
    string s = "cbbd";
    string ans = solution.longestPalindrome(s);
    cout << ans << endl;
    return 0;
}