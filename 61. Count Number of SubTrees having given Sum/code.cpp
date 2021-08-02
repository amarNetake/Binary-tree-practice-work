int findAllSubtrees(Node* root,int X,int& count)
{
    if(root==NULL)
    {
        return 0;
    }
    int sum= root->data + findAllSubtrees(root->left,X,count) + findAllSubtrees(root->right,X,count);
    if(sum==X)
    {
        count++;
    }
    return sum;
}

int countSubtreesWithSumX(Node* root, int X) // main() function calls this
{
	// Code here
	int count=0;
	int result=findAllSubtrees(root,X,count);
	return count;
}