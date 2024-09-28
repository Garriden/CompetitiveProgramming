
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& mapi, int& index, int l, int r) {
        if(l > r) return nullptr;

        TreeNode* root = new TreeNode(preorder[index]);
        ++index;

        int mid = mapi[root->val];
        
        root->left  = build(preorder, mapi, index, l, mid - 1);
        root->right = build(preorder, mapi, index, mid + 1, r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mapi;
        for (int ii = 0; ii < inorder.size(); ++ii) {
            mapi[inorder[ii]] = ii;
        }
        int index = 0;
        return build(preorder, mapi, index, 0, inorder.size()-1);
    }
