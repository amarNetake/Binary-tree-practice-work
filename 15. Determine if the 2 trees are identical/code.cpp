class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)  return true;
        if(p==NULL || q==NULL)   return false;
        if(p->val != q->val)   return false;
        bool lh=isSameTree(p->left,q->left);
        if(lh==false)  return false;
        bool rh=isSameTree(p->right,q->right);
        if(rh==false)  return false;
        return true;
    }
};