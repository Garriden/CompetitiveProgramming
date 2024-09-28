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
    vector<double> averageOfLevels(TreeNode* root) {
        /////////////
        // Insert null pointer to check levels. 
        /////////////
        /*
        vector<double> averages(0,0);

        queue<TreeNode*> que;
        que.push(root);
        que.push(nullptr);
        //averages.push_back(root->val);

        double sum = 0;
        double count = 0;

        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            if(node == nullptr) {
                double avg = sum/count;
                averages.push_back(avg);
                sum = 0;
                count = 0;
                if(que.size() > 0) {
                    que.push(nullptr);
                }
            } else {
                sum += node->val;
                ++count;

                if(node->left){
                    que.push(node->left);
                }

                if(node->right){
                    que.push(node->right);
                }
            }
        }
        return averages;
        */


        vector<double> result;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            double avg = 0;
            for (int i=0; i<n; i++) {
                TreeNode* node = q.front();
                avg += node->val;
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(avg/n);
        }
        return result;


    }
};
