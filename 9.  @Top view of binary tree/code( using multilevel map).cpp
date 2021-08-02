void verticalTraversal(Node* root,int x,int y,map<int,map<int,int>>& ma)
{
    if(root==NULL)
    {
        return;
    }
    ma[x][y]=root->data;
    verticalTraversal(root->left,x-1,y+1,ma);
    verticalTraversal(root->right,x+1,y+1,ma);
}

void topView(struct Node *root)
{
    //Your code here
    if(root==NULL)
    {
        return;
    }
    map<int,map<int,int>> ma;
    verticalTraversal(root,0,0,ma);
    for(auto x: ma)
    {
        cout<<(x.second).begin()->second<<" ";
    }
}