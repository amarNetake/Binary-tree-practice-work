void findNodesInGivenRange(Node* root,int low,int high,vector<int>& vect)
{
    if(root==NULL)
    {
        return;
    }
    findNodesInGivenRange(root->left,low,high,vect);
    if(root->data >= low && root->data <=high)
    {
        vect.push_back(root->data);
    }
    findNodesInGivenRange(root->right,low,high,vect);
}
vector<int> printNearNodes(Node *root, int low, int high)
{
  // your code goes here 
  vector<int> vect;
  findNodesInGivenRange(root,low,high,vect);
  return vect;
}