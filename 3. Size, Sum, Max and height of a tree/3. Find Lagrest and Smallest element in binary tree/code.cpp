// Returns maximum value in a given Binary Tree
int findMax(struct node* root)
{
    if(root==NULL) return INT_MIN;
    int lh=findMax(root->left);
    int rh=findMax(root->right);
    return max({root->data,lh,rh});
}

// Returns minimum value in a given Binary Tree
int findMin(struct node* root)
{
    if(root==NULL)  return INT_MAX;
    int lh=findMin(root->left);
    int rh=findMin(root->right);
    return min({root->data,lh,rh});
}