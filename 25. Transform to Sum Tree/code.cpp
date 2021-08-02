int sumofNodes(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->data + sumofNodes(root->left) + sumofNodes(root->right); 
}
void toSumTree(Node *root)
{
    // Your code here
    if(root==NULL)
    {
        return;
    }
    root->data=sumofNodes(root->left) + sumofNodes(root->right);
    toSumTree(root->left);
    toSumTree(root->right);
}