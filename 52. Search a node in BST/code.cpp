bool search(Node* root, int x)
{
    //Your code here
    if(root==NULL)
    {
        return false;
    }
    while(root!=NULL)
    {
        if(root->data==x)
        {
            return true;
        }
        else if(root->data < x)
        {
            root=root->right;
        }
        else if(root->data > x)
        {
            root=root->left;
        }
    }
    return false;
}