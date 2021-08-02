bool isFullTree (struct Node* root)
{
//add code here.
    if(root==NULL)
    {
        return true;
    }
    if((root->left==NULL&&root->right!=NULL)||(root->left!=NULL&&root->right==NULL))
    {
        return false;
    }
    bool lh=isFullTree(root->left);
    if(lh==false)
    {
        return false;
    }
    
    bool rh=isFullTree(root->right);
    if(rh==false)
    {
        return false;
    }
    return true;
}