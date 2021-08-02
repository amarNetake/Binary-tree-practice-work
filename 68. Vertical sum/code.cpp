void findVerticalSum(Node* root,map<int,int>& ma,int x)
{
    if(root==NULL)
    {
        return;
    }
    ma[x]=ma[x]+root->data;
    findVerticalSum(root->left,ma,x-1);
    findVerticalSum(root->right,ma,x+1);
}
vector <int> verticalSum(Node *root) {
    // add code here.
    if(root==NULL)
    {
        return {};
    }
    map<int,int> ma;
    int x=0;
    findVerticalSum(root,ma,x);
    vector<int> vect;
    for(auto x:ma)
    {
        vect.push_back(x.second);
    }
    return vect;
}