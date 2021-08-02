class Solution {
public:
    void preorder(TreeNode* root,TreeNode** target,int& maxLevel,int level)
    {
        if(root==NULL)  return;
        if(maxLevel<level)
        {
            *target=root;
            maxLevel=level;
        }
        preorder(root->left,target,maxLevel,level+1);
        preorder(root->right,target,maxLevel,level+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* target;
        int maxLevel=-1;
        preorder(root,&target,maxLevel,0);
        return target->val;
    }
};