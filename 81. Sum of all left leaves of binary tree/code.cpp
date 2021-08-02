class Solution {
public:
    
    int sumLeftLeavesUtil(TreeNode* root,int pos)
    {
        if(root==NULL)  return 0;
        int lsum=sumLeftLeavesUtil(root->left,-1);  //Let -1 stands for left child of the parent
        int rsum=sumLeftLeavesUtil(root->right,1); //Let 1 stands for the right child of the parent
        if(pos==-1 && root->left==NULL&& root->right==NULL)  return (root->val + lsum + rsum);
        else  return (lsum+rsum);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)  return 0;
        int sum=sumLeftLeavesUtil(root,0);
        return sum;
    }
};