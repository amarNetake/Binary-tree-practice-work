// Inorder successor of give node in BST is the smallest node in Right subtree of given node
// and if RHS of given node is null then its immediate next node in recursion.

class Solution {
public:
    TreeNode* findSuccessor(TreeNode* root)
    {
        root=root->right;
        if(root==NULL)  return NULL;
        while(root->left!=NULL)  root=root->left;
        return root;
    }
    
    void inorderSucUtil(TreeNode* root,TreeNode* p,bool& found,TreeNode*& target)
    {
        if(root==NULL)  return;
        if(root==p)
        {
            found=true;   
            target=findSuccessor(root);
            return;
        }
        inorderSucUtil(root->left,p,found,target);
        if(found==true)  
        {
            if(target==NULL)  target=root;
            return;
        }
        inorderSucUtil(root->right,p,found,target);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)  //Driver function
    {
        bool found=false;
        TreeNode* target=NULL;
        inorderSucUtil(root,p,found,target);
        return target;
    }
};