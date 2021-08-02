void traverse(Node* root,int count,int& max)
{
    if(root==NULL)
    {
        return;
    }
    count++;
    if(count>1 && count>max)
    {
        max=count;
    }
    
    if(root->left!=NULL && root->left->data - root->data ==1)
    {
        traverse(root->left,count,max);
    }
    else
    {
        traverse(root->left,0,max);
    }
    if(root->right!=NULL && root->right->data - root->data ==1)
    {
        traverse(root->right,count,max);
    }
    else
    {
        traverse(root->right,0,max);
    }
}

int longestConsecutive(Node* root)
{
     //Code here
     int max=-1;
     traverse(root,0,max);
     return max;
}