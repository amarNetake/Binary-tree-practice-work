class route{
    public:
        stack<Node*> lane;
        bool found=false;
};

void findPath(Node* root,int target,route& path)
{
    if(root==NULL)  return;
    if(root->data==target)
    {
        path.found=true;
        path.lane.push(root);
        return;
    }
    findPath(root->left,target,path);
    if(path.found==true)
    {
        path.lane.push(root);
        return;
    }
    findPath(root->right,target,path);
    if(path.found==true)  
    {
        path.lane.push(root);
    }
}
int findDist(Node* root, int a, int b) {
    // Your code here
    if(root==NULL)  return -1;
    route path1,path2;
    findPath(root,a,path1);
    findPath(root,b,path2);
    if(path1.found==false || path2.found==false)  return -1;
    while(path1.lane.empty()==false && path2.lane.empty()==false)
    {
        if(path1.lane.top()!=path2.lane.top())
        {
            return path1.lane.size() + path2.lane.size();
        }
        path1.lane.pop();
        path2.lane.pop();
    }
    return path1.lane.size()+path2.lane.size();
}