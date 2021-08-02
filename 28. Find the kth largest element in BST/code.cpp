void findKthLargest(Node* root,vector<int>& vect)
{
    if(root==NULL)
    {
        return;
    }
    findKthLargest(root->right,vect);
    vect.push_back(root->data);
    findKthLargest(root->left,vect);
}
int kthLargest(Node *root, int k)
{
    //Your code here
    if(root==NULL)
    {
        return -1;
    }
    vector<int> vect;
    findKthLargest(root,vect);
    return vect[k-1];
}