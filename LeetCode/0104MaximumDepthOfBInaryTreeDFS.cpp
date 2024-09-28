class Solution {
public:

    int iterativeDFS(TreeNode* root, int ans) {
        stack<pair<TreeNode*,int> > stack;
        stack.push({root,1});

        while (!stack.empty()) {
            TreeNode* node = stack.top().first;
            int level = stack.top().second;
            ans = max(ans, level);
            stack.pop();
            if (node->left != nullptr) {
                stack.push({node->left, level+1});
            }
            if (node->right != nullptr) {
                stack.push({node->right,level+1});
            }
        }

        return ans;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        //return 1 + max(maxDepth(root->left),maxDepth(root->right));
        return iterativeDFS(root,0);
    }
};
