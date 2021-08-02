// Using depth first traversal
void findAllNodes(Node* root,int s,int k,vector<int>& vect)
{
    if(root==NULL)
    {
        return;
    }
    if(s==k)
    {
        vect.push_back(root->data);
        return;
    }
    findAllNodes(root->left,s+1,k,vect);
    findAllNodes(root->right,s+1,k,vect);
}

vector<int> Kdistance(struct Node *root, int k)
{
  // Your code here
  vector<int> vect;
  findAllNodes(root,0,k,vect);
  return vect;
}