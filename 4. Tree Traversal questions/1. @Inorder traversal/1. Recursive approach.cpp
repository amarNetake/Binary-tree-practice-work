void InOrder(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	InOrder(root->left);
	cout<<root->data<<" ";
	InOrder(root->right);
}