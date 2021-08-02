class Status{
    public:
        Node* par;  // Address of parent of leaf node
        int chldPos;  //childPos is the position of the leaf with respect to its parent 0=>leaf is on left of its parent
        Status()
        {
            par=NULL;
            chldPos=-1;
        }
};

void preorder(Node* root,Status& parent,Node* curr,int pos)
{
    if(root==NULL)
    {
        return;
    }
    
    /* 
       The 'curr' will be having the address of parent of leaf node and 'pos' signifies the position of leaf
       with respect to its parent that is 0=>left and 1=>right
    */
    if(root->left==NULL && root->right==NULL&& parent.par==NULL)
    {
        parent.par=curr;
        parent.chldPos=pos;
    }

    else if(root->left==NULL&&root->right==NULL&&parent.par!=NULL)
    {
        if(parent.chldPos==0)
        {
            if(pos==0)
            {
                swap(parent.par->left,curr->left);
                parent.par=NULL;    // After swapping we want to take the next two leafs into consideration hence reinitialize
                parent.chldPos=-1;
            }
            else if(pos==1)
            {
                swap(parent.par->left,curr->right);
                parent.par=NULL;
                parent.chldPos=-1;
            }
        }
        else if(parent.chldPos==1)
        {
            if(pos==0)
            {
                swap(parent.par->right,curr->left);
                parent.par=NULL;
                parent.chldPos=-1;
            }
            else if(pos==1)
            {
                swap(parent.par->right,curr->right);
                parent.par=NULL;
                parent.chldPos=-1;
            }
        }
    }
    preorder(root->left,parent,root,0);
    preorder(root->right,parent,root,1);
}
void pairwiseSwap(Node *root)
{
    // code here
    if(root==NULL)
    {
        return;
    }
    Status parent;
    preorder(root,parent,NULL,0);
}