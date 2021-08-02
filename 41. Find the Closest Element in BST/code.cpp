void findminDiff(Node* root,int k,int& diff)
{
    if(root==NULL)
    {
        return;
    }
    diff=min(abs(root->data - k), diff);
    findminDiff(root->left,k,diff);
    findminDiff(root->right,k,diff);
}
int minDiff(Node *root, int k)  //main() calls this function
{
    //Your code here
    if(root==NULL)
    {
        return k;
    }
    int diff=INT_MAX;
    findminDiff(root,k,diff);
    return diff;
}