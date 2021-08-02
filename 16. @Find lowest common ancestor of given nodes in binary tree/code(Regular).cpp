class route{
    public:
    stack<TreeNode*> lane;
    bool found=false;
};

class Solution {
public:
    void findPath(TreeNode* root,TreeNode* target,route& path)
    {
        if(root==NULL) return;
        if(root==target)
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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) //driver function
    {
        route path1;
        route path2;
        findPath(root,p,path1);
        findPath(root,q,path2);
        TreeNode* result;
        while(path1.lane.empty()==false && path2.lane.empty()==false)
        {
            if(path1.lane.top()!=path2.lane.top()) break;
            result=path1.lane.top();  
            path1.lane.pop();
            path2.lane.pop();
        }
        return result;
    }
};