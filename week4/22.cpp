class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, 0, "", ans);
        return ans;

    }

    void generate(int left, int right, string str, vector<string>& ans) {
        if (left == 0 && right == 0) {
            ans.push_back(str);
        }
        if (left > 0) generate(left-1, right+1, str + "(", ans);
        if (right > 0) generate(left, right-1, str + ")", ans);
    }
};