#define intmax INT_MAX
 #define intmin INT_MIN
class NodeValue{
    public:
    int maxi,mini,maxi_sum;
    NodeValue(int first,int second,int max_sum)
    {
        this->maxi=second;
        this->mini=first;
        this->maxi_sum=max_sum;
    }
};
class Solution {
public:
    
    NodeValue Traversal(TreeNode* root,int& result)
    {
        if(root==nullptr)
        {
             return {intmax,intmin,0};
        }
        
        auto left=Traversal(root->left,result);
        auto right=Traversal(root->right,result);
        if(left.maxi>=root->val || right.mini<=root->val)
        {
            return {intmin,intmax,0};
        }
        // it means tree is valid
        int sum=root->val+left.maxi_sum+right.maxi_sum;
        result=max(sum,result);
        return {min(left.mini,root->val),max(right.maxi,root->val),sum};
    }
    int maxSumBST(TreeNode* root) {
        int leftmax=0;int rightmin=0;int max_sum=0;
        int result=0;
        NodeValue ans= Traversal(root,result);
        return result;
        
    }
};