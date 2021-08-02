class Status
{
    public:
        bool found;
        int depth;
        vector<Node*> path;
        Status()
        {
            found=false;
            depth=0;
        }
};

void infoOfNode(Node* root,int item,Status& s)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data==item)
    {
        s.found=true;
        s.path.push_back(root);
        return;
    }
    infoOfNode(root->left,item,s);
    if(s.found==true)
    {
        s.depth++;
        s.path.push_back(root);
        return;
    }
    infoOfNode(root->right,item,s);
    if(s.found==true)
    {
        s.depth++;
        s.path.push_back(root);
        return;
    }
}
bool isCousins(Node *root, int a, int b)
{
   //add code here.
   if(root==NULL||root->data==a||root->data==b)
   {
       return false;
   }
   Status infoA;
   infoOfNode(root,a,infoA);
   Status infoB;
   infoOfNode(root,b,infoB);
   if(infoA.depth==infoB.depth && infoA.path[1]!=infoB.path[1])
   {
       return true;
   }
   return false;
}