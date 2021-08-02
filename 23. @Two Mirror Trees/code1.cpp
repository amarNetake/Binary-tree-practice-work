//Return 1 if tree with root1 as root is a mirror of tree with root2 as root else 0.

void mirror(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
}

int compare(Node* root1,Node* root2)
{
    if((root1==NULL&&root2!=NULL)||(root1!=NULL&&root2==NULL))
    {
        return 0;
    }
    if(root1==NULL&&root2==NULL)
    {
        return 1;
    }
    if(root1->data!=root2->data)
    {
        return 0;
    }
    else
    {
        int lh=compare(root1->left,root2->left);
        if(lh==0)
        {
            return 0;
        }
        int rh=compare(root1->right,root2->right);
        if(rh==0)
        {
            return 0;
        }
        return 1;
    }
}
   
int areMirror(Node* root1, Node* root2) {
    // Your code here
    mirror(root1);
    int result=compare(root1,root2);
    mirror(root1);
    return result;
}