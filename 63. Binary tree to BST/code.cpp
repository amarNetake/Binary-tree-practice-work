void inorder(Node* root,vector<int>& vect)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,vect);
    vect.push_back(root->data);
    inorder(root->right,vect);
}

void fillBT(Node* root,vector<int>& vect, int& pos)
{
    if(root==NULL)
    {
        return;
    }
    fillBT(root->left,vect,pos);
    root->data=vect[pos++];
    fillBT(root->right,vect,pos);
}

Node *binaryTreeToBST (Node *root)  //main() function calls this
{
    //Your code goes here
    vector<int> vect;
    inorder(root,vect);
    sort(vect.begin(),vect.end());
    int pos=0;
    fillBT(root,vect,pos);
    return root;
}