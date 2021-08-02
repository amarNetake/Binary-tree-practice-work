//With O(1) space

void findKthLargest(Node* root,int& s,int k,int& item)
{
    if(root==NULL)
    {
        return;
    }
    findKthLargest(root->right,s,k,item);
    s++;
    if(s==k)
    {
        item=root->data;
        return;
    }
    findKthLargest(root->left,s,k,item);
}
int kthLargest(Node *root, int k)
{
    //Your code here
    if(root==NULL)
    {
        return -1;
    }
    vector<int> vect;
    int item;
    int s=0;
    findKthLargest(root,s,k,item);
    return item;
}