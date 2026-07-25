class Solution {
public:
    void solve(TreeNode* root, int &result, int maxi) {
        if (root == NULL) return;

        if (root->val >= maxi) {
            result++;
            maxi = root->val;
        }

        solve(root->left, result, maxi);
        solve(root->right, result, maxi);
    }

    int goodNodes(TreeNode* root) {
        int result = 0;
        solve(root, result, root->val);
        return result;
    }
};
