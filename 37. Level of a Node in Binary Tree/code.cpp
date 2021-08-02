void findLevel(Node* root,int target,int &level,int itr)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==target)
    {
        level=itr+1;
        return;
    }
    findLevel(root->left,target,level,itr+1);
    if(level>=0)
    {
        return;
    }
    findLevel(root->right,target,level,itr+1);
}

int getLevel(struct Node *root, int target)
{
	//code here
	if(root==NULL)
	{
	    return 0;
	}
	int level=INT_MIN;
	findLevel(root,target,level,0);
	if(level<0)
	{
	    return 0;
	}
	return level;
}
