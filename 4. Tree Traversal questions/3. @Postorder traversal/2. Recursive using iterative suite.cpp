void postOrderUtil(Node* root,vector<int>& vect)
{
    if(root==NULL)
    {
        return;
    }
    postOrderUtil(root->left,vect);
    postOrderUtil(root->right,vect);
    vect.push_back(root->data);
}

vector <int> postOrder(Node* root)
{
  // Your code here
  if(root==NULL)
  {
      return {};
  }
  vector<int> vect;
  postOrderUtil(root,vect);
  return vect;
}
