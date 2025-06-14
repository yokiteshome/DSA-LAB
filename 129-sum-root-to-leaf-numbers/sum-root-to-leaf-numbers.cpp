/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* cur, int num) -> int {
            if (!cur) return 0;

            num = num * 10 + cur->val;
            if (!cur->left && !cur->right) return num;

            return dfs(cur->left, num) + dfs(cur->right, num);
        };

        return dfs(root, 0);
        
    }
};