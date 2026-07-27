/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Serialize using Level Order Traversal
    string serialize(TreeNode* root) {

        if(root == NULL)
            return "";

        string ans = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if(node == NULL) {
                ans += "N,";
            }
            else {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }

        return ans;
    }

    // Deserialize using Level Order Traversal
    TreeNode* deserialize(string data) {

        if(data == "")
            return NULL;

        stringstream ss(data);
        string str;

        // First value is the root
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            // Left child
            getline(ss, str, ',');
            if(str != "N") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            // Right child
            getline(ss, str, ',');
            if(str != "N") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};

/**
 * Your Codec object will be instantiated and called as such:
 * Codec ser, deser;
 * TreeNode* ans = deser.deserialize(ser.serialize(root));
 */