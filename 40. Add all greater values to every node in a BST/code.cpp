void utility(Node* root,int& sum)
{
    if(root==NULL)  return;
    
    utility(root->right,sum);
    sum=sum + root->data;
    root->data= sum;
    utility(root->left,sum);
}

Node* modify(Node *root)
{
    // Your code here
    int sum=0;
    utility(root,sum);
    return root;
}