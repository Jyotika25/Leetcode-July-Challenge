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
    
    TreeNode* helper(vector<int>& inorder , vector<int> &postorder , int instart , int inend , int poststart , int postend){
        //base case
        if (instart > inend) {
            return nullptr;
        }
        
        int rootVal = postorder[postend]; // last of post order is root
        TreeNode *root = new TreeNode(rootVal); // create treenode with root  =  rootval
        
        int rootIndex = instart;
        
        for (; rootIndex <= inend; rootIndex++) {//till end of inorder
            if (inorder[rootIndex] == rootVal) { // root found in inorder
                break;
            }
        }
        
        //get left values  ans right values
        int leftTreeSize = rootIndex - instart;
        int rightTreeSize = inend - rootIndex;
        
        //recursive calls to left and right subtree
        root->left = helper(inorder, postorder, instart, rootIndex - 1, poststart, poststart + leftTreeSize - 1);
        root->right = helper(inorder, postorder, rootIndex + 1, inend, postend - rightTreeSize, postend - 1);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        return helper(inorder , postorder , 0 , size-1 , 0  , size-1);
        
    }
};
