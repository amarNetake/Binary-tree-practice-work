// Using O(n) time and O(1) space

void findKthSmallest(Node* root,int &s,int k,int &item)
{
    if(root==NULL)
    {
        return;
    }
    findKthSmallest(root->left,s,k,item);
    s++;
    if(s==k)
    {
        item=root->data;
        return;
    }
    findKthSmallest(root->right,s,k,item);
}

int KthSmallestElement(Node *root, int k)
{
    //add code here.
    int s=0;
    int item=-1000000;
    findKthSmallest(root,s,k,item);
    if(item== -1000000)
    {
        return -1;
    }
    return item;
}