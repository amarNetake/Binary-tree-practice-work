class Sum{
  public:
    int oddSum=0;
    int evenSum=0;
};
void utility(Node* root,Sum& s,int level)
{
    if(root==NULL)  return;
    if(level&1==1)  s.oddSum=s.oddSum+root->data;
    else s.evenSum=s.evenSum + root->data;
    utility(root->left,s,level+1);
    utility(root->right,s,level+1);
}

int getLevelDiff(Node *root)
{
   //Your code here
   Sum s;
   utility(root,s,1);
   return s.oddSum-s.evenSum;
}