TreeNode* createBT(vector<TreeNode*> vect,int i,int n)
{
    TreeNode* root=NULL;
    if(i<n)
    {
        root=vect[i];
        root->left=createBT(vect,2*i+1,n);
        root->right=createBT(vect,2*i+2,n);
    }
    return root;
}


void convert(Node *head, TreeNode *&root)  //main() function calls this.
{
    // Your code here
    vector<TreeNode*> vect;     //create a vector of TreeNodes and store all the data Nodes from LL to vector.
    Node* itr=head;

    while(itr!=NULL)
    {
        TreeNode* new_node=new TreeNode(itr->data);
        vect.push_back(new_node);
        itr=itr->next;
    }
    int i=0;
    int n=vect.size();
    root=createBT(vect,i,n);
    return;
}