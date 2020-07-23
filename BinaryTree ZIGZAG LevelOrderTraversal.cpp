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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)   return{};
        vector<vector<int>> result;
        deque<TreeNode*> q;
        q.push_back(root);
        
        bool reverse = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> levelNodes;
            
            deque<TreeNode*> dq;
            
            for(int i=0;i<size;i++){
                TreeNode *node = q.front();
                levelNodes.push_back(node->val);
                q.pop_front();
                
                //reverse or zigzag logic
                if(reverse){
                    if(node->left) dq.push_front(node->left);
                     if(node->right) dq.push_front(node->right);
                }
                else{
                     if(node->right) dq.push_front(node->right);
                     if(node->left) dq.push_front(node->left);
                }
            }//end of level
            
            q.insert(q.end() , dq.begin() , dq.end());
            result.push_back(levelNodes);
            reverse = !reverse;
        }
        
        return result;
    }
};
