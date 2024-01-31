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
   TreeNode* preOrderTraversal(TreeNode* root,int low, int high)
    {
        if(!root)
            return root;
        
        root->left = preOrderTraversal(root->left,low,high);
        root->right = preOrderTraversal(root->right,low,high);
        
        if(root->val<low)
        {
            root->left=NULL;
            root=root->right;
        }
        else if(root->val>high)
        {
            root->right = NULL;
            root=root->left;
        }
        return root;
        
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return preOrderTraversal(root,low,high);
    }
};
