void traverse(Node* root,int& dead,int l,int r)
{
    if(dead==0||root==NULL)
    {
        return;
    }
    if(l==r || r==1) 
    {
        dead=0;
    }
    traverse(root->left,dead, l, root->data - 1); //Nodes in LHS of root must have values greater than l and less than (root->data - 1).
    traverse(root->right,dead, root->data + 1, r);//Nodes in RHS of root must have values greater than or equal to root->data + 1 and smaller than r.
    
}
bool isDeadEnd(Node *root)
{
    //Your code here
    int dead=1;
    traverse(root,dead,INT_MIN,INT_MAX);
    if(dead==0)
    {
        return true;  //We found a deadend in given binary tree
    }
    return false;     //Given binary tree has no dead end
}