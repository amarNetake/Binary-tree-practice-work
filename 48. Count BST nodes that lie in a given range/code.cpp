void CountNodesinRange(Node* root,int l,int h,int& count)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data >=l && root->data <= h)
    {
        count++;
    }
    if(root->data >= l)
    {
        CountNodesinRange(root->left,l,h,count);
    }
    if(root->data <=h)
    {
        CountNodesinRange(root->right,l,h,count);
    }
}