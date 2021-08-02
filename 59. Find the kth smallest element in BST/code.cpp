 void findkthSmallest(Node* root,int k,int& itr,int& item)
{
    if(root==NULL)
    {
        return;
    }
    findkthSmallest(root->left,k,itr,item);
    itr++;
    if(itr==k)
    {
        item=root->val;
        return;
    }
    findkthSmallest(root->right,k,itr,item);
}
int kthSmallest(Node* root, int k) {
    int itr=0;
    int item;
    findkthSmallest(root,k,itr,item);
    return item;
}