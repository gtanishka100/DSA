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

void trackParent(unordered_map<TreeNode*, TreeNode*> &parentNode, TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
    TreeNode* curr=q.front();
    q.pop();
    if(curr->left){
        parentNode[curr->left]=curr;
        q.push(curr->left);
    }
        if(curr->right){
        parentNode[curr->right]=curr;
        q.push(curr->right);
    }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentNode;
        trackParent(parentNode, root);
        int step=0;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> qq;
        qq.push(target);
        visited[target]=true;
        while(!qq.empty()){
            int size=qq.size();
            if(step++ ==k) break;
            for(int i=0;i<size;i++){
            TreeNode* curr_node=qq.front();
            qq.pop();
            if(curr_node->left && !visited[curr_node->left]){
                qq.push(curr_node->left);
                visited[curr_node->left]=true;
            }
             if(curr_node->right && !visited[curr_node->right]){
                qq.push(curr_node->right);
                visited[curr_node->right]=true;
            }
             if(parentNode[curr_node] && !visited[parentNode[curr_node]]){
                qq.push(parentNode[curr_node]);
                visited[parentNode[curr_node]]=true;
            }
        }
        }

        vector<int> result;
        while(!qq.empty()){
            TreeNode* ans=qq.front();
            qq.pop();
            result.push_back(ans->val);
        }
        return result;
    }
};