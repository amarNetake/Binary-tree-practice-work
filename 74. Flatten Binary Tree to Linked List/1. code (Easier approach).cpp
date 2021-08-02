// Store all nodes in the vector in preorder fashion then manipulate the pointers according to your desire

void flattenBT(TreeNode* root,vector<TreeNode*>& vect)
{
    if(root==NULL)
    {
        return;
    }
    vect.push_back(root);
    flattenBT(root->left,vect);
    flattenBT(root->right,vect);
}

void flatten(TreeNode* root) {
    if(root==NULL)
    {
        return;
    }
    vector<TreeNode*> vect;
    flattenBT(root,vect);
    TreeNode* prev=NULL;
    for(auto x: vect)
    {
        x->left=NULL;
        if(prev!=NULL)
        {
            prev->right=x;
        }
        prev=x;
    }
    
}