class Status{
    public:
        bool found;
        vector<int> path;
        Status(){
            found=false;
            path={};
        }
};

void findAncestors(Node* root,int target,Status& s)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==target)
    {
        s.found=true;
        s.path={};
        return;
    }
    findAncestors(root->left,target,s);
    if(s.found==true)
    {
        s.path.push_back(root->data);
        return;
    }
    findAncestors(root->right,target,s);
    if(s.found==true)
    {
        s.path.push_back(root->data);
        return;
    }
}
vector<int> Ancestors(struct Node *root, int target)
{
     // Code here
     if(root==NULL)
     {
         return {};
     }
     Status s;
     findAncestors(root,target,s);
     return s.path;
}