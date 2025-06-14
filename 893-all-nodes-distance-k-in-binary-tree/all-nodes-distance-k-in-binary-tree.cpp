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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        assignParent(root, parentMap);

        unordered_map<TreeNode*, bool> isVisited;
        queue<TreeNode*> levelQueue;
        levelQueue.push(target);
        isVisited[target] = true;

        int level = 0;

        while (!levelQueue.empty()) {
            if (level == k) break;
            int levelCount = levelQueue.size();
            level++;

            for (int i = 0; i < levelCount; i++) {
                TreeNode* node = levelQueue.front();
                levelQueue.pop();

                if (node->left && !isVisited[node->left]) {
                    levelQueue.push(node->left);
                    isVisited[node->left] = true;
                }
                if (node->right && !isVisited[node->right]) {
                    levelQueue.push(node->right);
                    isVisited[node->right] = true;
                }
                if (parentMap[node] && !isVisited[parentMap[node]]) {
                    levelQueue.push(parentMap[node]);
                    isVisited[parentMap[node]] = true;
                }
            }
        }

        vector<int> result;
        while (!levelQueue.empty()) {
            TreeNode* node = levelQueue.front();
            levelQueue.pop();
            result.push_back(node->val);
        }

        return result;
    }

private:
    void assignParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }
        
    }
};