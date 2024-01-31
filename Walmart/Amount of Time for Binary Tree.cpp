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
    map<int,vector<int>>mp;
    void CreateTree(TreeNode* root)
    {
        if(root==NULL)
        return ;
        int node=root->val;
    
        if(root->left)
        {
            mp[node].push_back(root->left->val);
            mp[root->left->val].push_back(node);
            CreateTree(root->left);
        }
        if(root->right)
        {
            mp[node].push_back(root->right->val);
            mp[root->right->val].push_back(node);
            CreateTree(root->right);
        }
    }
    int BFS(int start)
    {
      int n=mp.size();
      set<int>st;
      queue<int>q;
      q.push(start);
      st.insert(start);
      int t=0;
      while(!q.empty())
      {
          int levelSize=q.size();
          while(levelSize > 0)
          {
              int current=q.front();
              q.pop();
              for(auto val:mp[current])
                {
                    if(st.find(val)==st.end())
                    {
                        st.insert(val);
                        q.push(val);
                    }
                }
          levelSize--;
          }
          t++;
      }
      for(auto val:st)
      cout<<val<<" ";
      cout<<endl;
      return t-1;
    }
    int amountOfTime(TreeNode* root, int start) {
        // created a undirected Graph
        // then use BFS search and find times required
        CreateTree(root);
        int Time=BFS(start);       
        return Time;
    }
};
