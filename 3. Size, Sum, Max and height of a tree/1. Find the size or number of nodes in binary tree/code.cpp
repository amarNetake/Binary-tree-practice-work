int getSize(Node* rool)
{
   // Your code here
   if(root==NULL)  return 0;
   return 1 + getSize(root->left) + getSize(root->right);
}