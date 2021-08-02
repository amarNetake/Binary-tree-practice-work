class Solution {
public:
    void findAllLeftmostNodes(TreeNode* root,vector<int>& result)
    {
        if(root==NULL)   return;
        if(root->left==NULL && root->right==NULL)  return;
        result.push_back(root->val);
        
        if(root->left!=NULL)    findAllLeftmostNodes(root->left,result);
        else if(root->right!=NULL)   findAllLeftmostNodes(root->right,result);
    }
    void findAllLeafNodes(TreeNode* root,vector<int>& result)
    {
        if(root==NULL)  return;
        if(root->left==NULL&&root->right==NULL)   result.push_back(root->val);
        findAllLeafNodes(root->left,result);
        findAllLeafNodes(root->right,result);
    }
    
    void findAllRightmostNodes(TreeNode* root,vector<int>& result)
    {
        if(root==NULL)  return;
        if(root->right==NULL&&root->left==NULL)  return;
        
        if(root->right!=NULL)        findAllRightmostNodes(root->right,result);
        else if(root->left!=NULL)    findAllRightmostNodes(root->left,result);
        
        result.push_back(root->val);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root==NULL)  return {};
        vector<int> result;
        result.push_back(root->val);
        if(root->left==NULL && root->right==NULL)  return result;
        findAllLeftmostNodes(root->left,result);
        findAllLeafNodes(root,result);
        findAllRightmostNodes(root->right,result);
        return result;
    }
};