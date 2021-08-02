void findNoSiblingNodes(Node* root,vector<int>& vect)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left!=NULL&&root->right==NULL)
    {
        vect.push_back(root->left->data);
    }
    else if(root->left==NULL&&root->right!=NULL)
    {
        vect.push_back(root->right->data);
    }
    findNoSiblingNodes(root->left,vect);
    findNoSiblingNodes(root->right,vect);
}

vector<int> noSibling(Node* root)
{
    // code here
    if(root==NULL)
    {
        return {-1};
    }
    vector<int> vect;
    findNoSiblingNodes(root,vect);
    if(vect.empty()==true)
    {
        return {-1};
    }
    sort(vect.begin(),vect.end());  //No need of this but since we needed output a sorted vector in question we did this.
    return vect;
}