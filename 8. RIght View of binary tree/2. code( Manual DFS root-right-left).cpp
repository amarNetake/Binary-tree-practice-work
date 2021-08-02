class Solution {
public:
    
    void rightViewUtil(TreeNode* root,vector<int>& result,int& maxLevel,int level)
    {
        if(root==NULL)  return;
        if(level > maxLevel)  
        {
            maxLevel=level;
            result.push_back(root->val);
        }
        rightViewUtil(root->right,result,maxLevel,level+1);
        rightViewUtil(root->left,result,maxLevel,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)  return {};
        vector<int> result;
        int maxLevel=-1;
        rightViewUtil(root,result,maxLevel,0);
        return result;
    }
};