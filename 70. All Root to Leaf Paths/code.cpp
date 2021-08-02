
void findAllPaths(Node* root,vector<int>vect,vector<vector<int>>&allPaths)//Note that 'vect' is pass by value and 'allPaths' is pass by reference
{
    if(root==NULL)
    {
        return;
    }
    else if(root->left==NULL&&root->right==NULL)
    {
        vect.push_back(root->data);
        allPaths.push_back(vect);
        return;
    }
    vect.push_back(root->data);
    findAllPaths(root->left,vect,allPaths);
    findAllPaths(root->right,vect,allPaths);
}
 
vector<vector<int>> Paths(Node* root)  // -> main() calls this function
{
    // Code here
    if(root==NULL)
    {
        return {};
    }
    vector<int> vect;
    vector<vector<int>> allPaths;
    findAllPaths(root,vect,allPaths);
    return allPaths;
}