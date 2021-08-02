bool checkIfSymmetric(Node* root1,Node* root2)
{
    if(root1==NULL&&root2==NULL)
    {
        return true;
    }
    else if(root1==NULL||root2==NULL)
    {
        return false;
    }
    if(root1->data!=root2->data)
    {
        return false;
    }
    bool lh=checkIfSymmetric(root1->left,root2->right);
    if(lh==false)
    {
        return false;
    }
    bool rh=checkIfSymmetric(root1->right,root2->left);
    if(rh==false)
    {
        return false;
    }
    return true;
}

bool isSymmetric(struct Node* root)
{
	// Code here
	bool result=checkIfSymmetric(root,root);
	return result;
}