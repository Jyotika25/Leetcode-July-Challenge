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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
    vector<vector<int>> result;
        //if tree  has no nodes
        if(!root) return result;
        
        //otherwise create a queue
        queue<TreeNode*> Q;
        Q.push(root);
        
        while(!Q.empty()){
            int n = Q.size();
            vector<int> levelNodes(n);
            
            for(int i=0;i<n;i++)
            {
                TreeNode* node = Q.front();
                levelNodes[i] = node->val;
                Q.pop();
                
                if(node->left)  Q.push(node->left);
                if(node->right) Q.push(node->right);
            }
            result.push_back(levelNodes);
        }
        
        reverse(result.begin(),result.end());
        return result;
        
    }
};
