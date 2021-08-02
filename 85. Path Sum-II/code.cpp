class Solution {
public:
    
    void preorderUtility(TreeNode* root,int& targetSum,vector<vector<int>>& result,vector<int> temp,int sum)
    {
        if(root==NULL)  return;
        temp.push_back(root->val);
        sum=sum+root->val;
        if(root->left==NULL && root->right==NULL)
        {
            if(sum==targetSum) result.push_back(temp);
            return;
        }
        preorderUtility(root->left,targetSum,result,temp,sum);
        preorderUtility(root->right,targetSum,result,temp,sum);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)  return {};
        vector<vector<int>> result;
        vector<int> temp;
        preorderUtility(root,targetSum,result,temp,0);
        return result;
    }
};