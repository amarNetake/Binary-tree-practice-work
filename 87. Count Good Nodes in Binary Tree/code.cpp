class Solution {
public:
    
    void goodNodesUtil(TreeNode* root,int& count,int maximum)
    {
        if(root==NULL) return;
        if(root->val>=maximum) count++;
        goodNodesUtil(root->left,count,max(maximum,root->val));
        goodNodesUtil(root->right,count,max(maximum,root->val));
    }
    
    int goodNodes(TreeNode* root) {
        int count=0;
        goodNodesUtil(root,count,root->val);
        return count;
    }
};