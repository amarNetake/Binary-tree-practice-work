class status{
    public: 
        int MaxDiff;
        int smallest;
};

status findMaxDiff(Node* root)
{
    if(root==NULL) 
    {
        status s;
        s.smallest=1e7;
        s.MaxDiff=-1e7;
        return s;
    }
    status lh=findMaxDiff(root->left);
    status rh=findMaxDiff(root->right);
    status s;
    s.smallest=min({lh.smallest,rh.smallest,root->data});
    s.MaxDiff= max({root->data-lh.smallest,root->data-rh.smallest,lh.MaxDiff,rh.MaxDiff});
    return s;
}

int maxDiff(Node* root)
{ 
    status result=findMaxDiff(root);
    return result.MaxDiff;
}