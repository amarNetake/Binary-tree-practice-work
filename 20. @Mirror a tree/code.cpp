void mirror(Node* root) 
{
     // Your Code Here
     if(root==NULL)
     {
         return;
     }
     swap(root->left,root->right);
     mirror(root->left);
     mirror(root->right);
}