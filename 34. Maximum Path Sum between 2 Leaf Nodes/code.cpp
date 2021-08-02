int findMaxPathSum(Node* root,int& result)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->left==NULL&&root->right==NULL)
    {
        return root->data;
    }
    
    int lh=findMaxPathSum(root->left,result);
    int rh=findMaxPathSum(root->right,result);
    
    if(root->left!=NULL&&root->right!=NULL)
    {
        result=max(lh+rh+root->data,result);
        
        return max(lh,rh) + root->data;
    }
    
    if(root->left==NULL&&root->right!=NULL)
    {
        return rh+root->data;
    }
    else if(root->left!=NULL&&root->right==NULL)
    {
        return lh+ root->data;
    }
}

int maxPathSum(Node* root)
{ 
    // code here   
    if(root==NULL)
    {
        return 0;
    }
    int result=INT_MIN;
    int r= findMaxPathSum(root,result);
    return result;
}