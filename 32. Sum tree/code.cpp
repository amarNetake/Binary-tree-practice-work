int sum(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->data + sum(root->left) +  sum(root->right);
}

bool isSumTree(Node* root)
{
     // Your code here
     if(root==NULL)
     {
         return true;
     }
     if(root->left==NULL&&root->right==NULL)
     {
         return true;
     }
     if(root->data==sum(root->left) + sum(root->right))
     {
         bool lh=isSumTree(root->left);
         if(lh==false)
         {
             return false;
         }
         bool rh=isSumTree(root->right);
         if(rh==false)
         {
             return false;
         }
         return true;
     }
     return false;
}