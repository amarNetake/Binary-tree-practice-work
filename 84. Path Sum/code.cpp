class Solution {
public:
    void preorderUtility(TreeNode* root,int targetSum,bool& result,int sum)
    {
        if(root==NULL)  return;
        sum=sum+root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum) result=true;
            return;
        }
        preorderUtility(root->left,targetSum,result,sum);
        if(result==true) return;
        preorderUtility(root->right,targetSum,result,sum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        bool result=false;
        preorderUtility(root,targetSum,result,0);
        return result;
    }
};