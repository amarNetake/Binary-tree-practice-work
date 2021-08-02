// Do preorder traversal and keep track of first node that was visited in each level.
void leftViewUtil(Node* root,vector<int>& result,int& maxLevel,int level)
{
    if(root==NULL)  return;
    if(level > maxLevel) 
    {
        maxLevel=level;
        result.push_back(root->data);
    }
    leftViewUtil(root->left,result,maxLevel,level+1);
    leftViewUtil(root->right,result,maxLevel,level+1);
}

vector<int> leftView(Node *root)
{
   // Your code here
   if(root==NULL)  return {};
   vector<int> result;
   int maxLevel=-1;
   leftViewUtil(root,result,maxLevel,0);
   return result;
}