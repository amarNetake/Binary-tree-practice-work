int evalTree(node* root) {
    // Your code here
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return stoi(root->data);  //stoi() converts string to integer.
    }
    int lval=evalTree(root->left);
    int rval=evalTree(root->right);
    if(root->data=="+")
    {
        return lval + rval;
    }
    else if(root->data=="-")
    {
        return lval - rval;
    }
    else if(root->data == "*")
    {
        return lval * rval;
    }
    else if(root->data=="/")
    {
        return lval/rval;
    }
}