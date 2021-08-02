class status{
    public:
        int dia;
        int ht;
};

class Solution {
public:
    
    status diameterUtil(TreeNode* root)
    {
        if(root==NULL)
        {
            status s;
            s.dia=0;
            s.ht=-1;
            return s;
        }
        status lh=diameterUtil(root->left);
        status rh=diameterUtil(root->right);
        status s;
        s.dia=max({lh.dia,rh.dia,lh.ht+rh.ht+2});
        s.ht=max(lh.ht+1,rh.ht+1);
        return s;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)  return 0;
        status s=diameterUtil(root);
        return s.dia;
    }
};