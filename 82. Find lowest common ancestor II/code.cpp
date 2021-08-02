class Solution {
public:
    TreeNode* preorder(TreeNode* root,TreeNode* p,TreeNode* q,int& count)
    {
        if(root==NULL)  return NULL;
        
        TreeNode* lh=preorder(root->left,p,q,count);
        TreeNode* rh=preorder(root->right,p,q,count);
        if(root==p || root==q)
        {
            count++;
            return root;
        }
        if(lh==NULL && rh==NULL)  return NULL;
        if(lh!=NULL && rh==NULL)  return lh;  //There is a path either of p or q but not to both.
        else if(lh==NULL && rh!=NULL)  return rh;  //There is a path either of p or q but not to both.
        
        return root; // if there is a path to both p and q from given node. The control will reach here for exactly one node which is lowest common ancestor
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        int count=0;
        TreeNode* result=preorder(root,p,q,count);
        return count==2?result:NULL;
    }
};