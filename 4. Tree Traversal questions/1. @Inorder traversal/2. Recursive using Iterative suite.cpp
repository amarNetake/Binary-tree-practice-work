void InOrderUtil(Node* root,vector<int>& vect)   //vector is recieved as reference
{
	if(root==NULL)
	{
		return;
	}
	InOrderUtil(root->left,vect);
	vect.push_back(root->data);
	InOrderUtil(root->right,vect);
}

vector<int> inorder(Node* root)   //Driver function i.e. main() function will call this function
{
	if(root==NULL)
	{
		return {};
	}
	vector<int> vect;
	InOrderUtil(root,vect);
	return vect;
}