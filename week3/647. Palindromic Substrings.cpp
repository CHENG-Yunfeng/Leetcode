class Solution {
public:
    int countSubstrings(string s) {
        int m = s.size();
        int count = 0;
        for (int i = 0; i < m; ++i) {
            expandCentre(s, i, i, count);
            if (i + 1 <= m - 1) {
                expandCentre(s, i, i +1, count);
            }
        }
        return count;
    }

    void expandCentre(string& s, int left, int right, int& count) {
        while (left >=0 && right < s.size()) {
            if (s[left] == s[right]) {
                count++;
                left--;
                right++;
            } else {
                break;
            }
        }
    }
};