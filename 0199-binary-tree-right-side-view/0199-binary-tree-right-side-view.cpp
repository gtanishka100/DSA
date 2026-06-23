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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        fn(root, 0, ans);
        return ans;
    }

    void fn(TreeNode* root, int level, vector<int> &ans){
        if(root==nullptr) return;
        if(level==ans.size()) ans.push_back(root->val);
        fn(root->right, level+1, ans);
        fn(root->left, level+1, ans);
    }
};