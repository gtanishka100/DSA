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
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=calLeftHeight(root->left);
        int rh=calRightHeight(root->right);
        if(lh==rh) return (1<< (lh+1))-1;
        return 1+(countNodes(root->left)+ countNodes(root->right));
    }

    int calLeftHeight(TreeNode* node){
        int count=0;
        while(node!=NULL){
            count++;
            node=node->left;
        }
        return count;
    }

      int calRightHeight(TreeNode* node){
        int count1=0;
        while(node!=NULL){
            count1++;
            node=node->right;
        }
        return count1;
    }
};