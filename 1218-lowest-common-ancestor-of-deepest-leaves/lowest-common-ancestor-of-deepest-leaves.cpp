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
 unordered_map<TreeNode*, int> cache;
    TreeNode* lcaDeepestLeaves(TreeNode* root) {


        if (root == nullptr) {
            return nullptr;
        }

        if (getHeight(root->left) == getHeight(root->right)) {
            return root;
        } else if (getHeight(root->left) > getHeight(root->right)) {
            return lcaDeepestLeaves(root->left);
        } else {
            return lcaDeepestLeaves(root->right);
        }
    }

    int getHeight(TreeNode* root) {
        if (cache.count(root)) return cache[root];
        if (root == nullptr) return 0;
        int res = max(getHeight(root->left), getHeight(root->right)) + 1;
        cache[root] = res;
        return res;
    }

};