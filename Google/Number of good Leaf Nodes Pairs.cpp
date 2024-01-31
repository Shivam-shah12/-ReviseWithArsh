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
    int countPairs(TreeNode* root, int distance) {
        map<TreeNode* ,vector<TreeNode*>>mp;
        queue<TreeNode*>pq;
        pq.push(root);
        vector<TreeNode*>Leaf;
        while(!pq.empty())
        {
            TreeNode* curr=pq.front();
            pq.pop();
            if(curr->left==curr->right)
            Leaf.push_back(curr);
            if(curr->left)
            {
                mp[curr].push_back(curr->left);
                mp[curr->left].push_back(curr);
                pq.push(curr->left);
            }
            if(curr->right)
            {
                mp[curr].push_back(curr->right);
                mp[curr->right].push_back(curr);
                pq.push(curr->right);
            }
        }
        int ans=0;
        for(auto node:Leaf)
        {
            unordered_map<TreeNode*,int>vis;
            queue<pair<TreeNode*,int>>q;
            q.push({node,0});
            
            while(!q.empty())
            {
                pair<TreeNode*,int>p1=q.front();
                q.pop();
                vis[p1.first]=1;
                for(auto each:mp[p1.first])
                {
                    if(vis[each])continue;
                    vis[each]=1;
                    if(p1.second+1<=distance){
                        if(each->left==each->right)
                        ans++;
                        else
                        {
                            q.push({each,p1.second+1});
                        }
                    }
                }
            }
        }
        return ans/2;
    }
};
