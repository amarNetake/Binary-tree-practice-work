class balPair{
  public:
    int ht;
    bool bal;
};

balPair isBalancedUtil(Node* root)
{
    if(root==NULL)
    {
        balPair pa;
        pa.ht=-1;
        pa.bal=true;
        return pa;
    }
    balPair lb=isBalancedUtil(root->left);
    balPair rb=isBalancedUtil(root->right);
    
    if(lb.bal==false)
    {
        return lb; //We no longer care about height if we got bal as false for any intermediate node as our end goal is check is Balanced
    }
    if(rb.bal==false)
    {
        return rb;  //We no longer care about height if we got bal as false for any intermediate node as our end goal is check is Balanced
    }
    
    int diff;
    balPair p;
    lb.ht>=rb.ht?diff=lb.ht-rb.ht:diff=rb.ht-lb.ht;
    if(diff<2)
    {
        p.bal=true;
        p.ht=max(lb.ht,rb.ht)+1;
    }
    else
    {
        p.bal=false;
        p.ht=max(lb.ht,rb.ht)+1;
    }
    return p;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    if(root==NULL)
    {
        return true;
    }
    balPair pa= isBalancedUtil(root);
    return pa.bal;
}