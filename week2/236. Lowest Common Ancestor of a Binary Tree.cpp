/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int self_flag, l_flag, r_flag;
        vector<TreeNode*> ans;
        preorder(root, p, q, ans);
        return ans[0];
    }

    int preorder(TreeNode* root, TreeNode*& p, TreeNode*& q, vector<TreeNode*>& ans) {
        if (!root) return 0;
        int self_flag = 0, l_flag = 0, r_flag = 0;
        if ((root == p) || (root == q)) {
            self_flag = 1;
        }
        l_flag = preorder(root->left, p, q, ans);
        r_flag = preorder(root->right, p, q, ans);
        if ((l_flag && r_flag) || (self_flag && (l_flag || r_flag))) {
            ans.push_back(root);
        }
        return (self_flag || l_flag || r_flag);
    }
};