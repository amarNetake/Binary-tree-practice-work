void countUtil(Node* root,int* count)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        (*count)++;
        return;
    }
    countUtil(root->left,count);
    countUtil(root->right,count);
}
int countLeaves(Node* root)  //main() function calls this fn
{
  // Your code here
  int count=0;
  countUtil(root,&count);
  return count;
}