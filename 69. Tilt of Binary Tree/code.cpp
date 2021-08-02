int findSum(Node* root,int& tilt)
{
    if(root==NULL)
    {
        return 0;
    }
    int ls=findSum(root->left,tilt);
    int rs=findSum(root->right,tilt);
    tilt= tilt + abs(ls-rs);
    int sum= root->val + ls + rs;
    return sum;
}

int tiltTree(Node* root)
{
	// Code here
	int tilt=0;
	int sum=findSum(root,tilt);
	return tilt;
}