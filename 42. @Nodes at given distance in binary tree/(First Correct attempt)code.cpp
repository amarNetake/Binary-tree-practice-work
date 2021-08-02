class solver
{
private:

public:

    void findPath(Node* root,int target,vector<Node*>& path,bool& found)
    {
        if(root==NULL || found==true) return;
        if(root->data==target)
        {
            found=true;
            path.push_back(root);
            return;
        }
        findPath(root->left,target,path,found);
        if(found==true)
        {
            path.push_back(root);
            return;
        }
        findPath(root->right,target,path,found);
        if(found==true)
        {
            path.push_back(root);
            return;
        }
    }
    
    void findAllNodes(Node* source,vector<int>& result,int dist,int blocker)
    {
        if(source==NULL) return;
        if(source->data==blocker) return;
        if(dist==0)  
        {
            result.push_back(source->data);
            return;
        }
        findAllNodes(source->left,result,dist-1,blocker);
        findAllNodes(source->right,result,dist-1,blocker);
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)  //Driver function
    {
        // return the sorted vector of all nodes at k dist
        vector<int> result;
        vector<Node*> path;
        bool found=false;
        findPath(root,target,path,found);
        
        for(int i=0;i<path.size();i++)
        {
            int dist=k-i;
            int blocker= i>0?path[i-1]->data:-1;  
            findAllNodes(path[i],result,dist,blocker);
        }
        
        return result;
    }
};