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
    void Preorder(TreeNode* root,vector<int>& ans){
        if(root==NULL){
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->val);
        Preorder(root->left,ans);
        Preorder(root->right,ans);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> vecp,vecq;
        Preorder(p,vecp);
        Preorder(q,vecq);
        for(int i=0;i<vecp.size();i++){
            if(vecp[i]!=vecq[i]) return false;
        }
        return true;
    }
};
