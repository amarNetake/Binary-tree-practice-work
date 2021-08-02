bool compare(Node* root1,Node* root2)
{
    if(root1==NULL&&root2==NULL)
    {
        return true;
    }
    if(root1==NULL||root2==NULL)
    {
        return false;
    }
    if(root1->data!=root2->data)
    {
        return false;
    }
    bool lh=compare(root1->left,root2->left);
    if(lh==false)
    {
        return false;
    }
    bool rh=compare(root1->right,root2->right);
    return rh;
}

bool isSubTree(Node* root1, Node* root2) {
    // Your code here
    // return 1 if S is subtree of T else 0
    if(root2==NULL)
    {
        return true;
    }
    if(root1==NULL)
    {
        return false;
    }
    bool isIdentical=compare(root1,root2);
    if(isIdentical==true)
    {
        return true;
    }
    return (isSubTree(root1->left,root2)||isSubTree(root1->right,root2));
}