void reverseAltPreorder(Node* root1,Node* root2,int level)
{
    if(root1==NULL||root2==NULL)
    {
        return;
    }
    if(level%2==0)
    {
        swap(root1->data,root2->data);
    }
    reverseAltPreorder(root1->left,root2->right,level+1);
    reverseAltPreorder(root1->right,root2->left,level+1);
}

void reverseAlternate(Node *root)  //main() function calls this function
{
    //Your code here
    if(root==NULL)
    {
        return;
    }
    reverseAltPreorder(root->left,root->right,0);
}