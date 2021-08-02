void findSumOfLeaves(Node* root,int& sum)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL && root->right==NULL)
    {
        sum = sum + root->data; 
    }
    findSumOfLeaves(root->left,sum);
    findSumOfLeaves(root->right,sum);
}

int sumLeaf(Node* root)
{
    // Code here
    if(root==NULL)
    {
        return 0;
    }
    int sum=0;
    findSumOfLeaves(root,sum);
    return sum;
}