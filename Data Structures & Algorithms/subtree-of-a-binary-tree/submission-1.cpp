class Solution {
public:
    bool solve(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) return true;
        if (root == NULL || subRoot == NULL) return false;

        if (root->val == subRoot->val) {
            return solve(root->left, subRoot->left) &&
                   solve(root->right, subRoot->right);
        }

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) return false;

        if (solve(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};