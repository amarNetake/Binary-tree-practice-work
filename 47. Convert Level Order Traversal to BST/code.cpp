void insertNode(Node* root,int item)
{
    Node* new_node=new Node(item);
    while(root->left!=NULL||root->right!=NULL)
    {
        if(root->data < item)
        {
            if(root->right==NULL)
            {
                break;
            }
            root=root->right;
        }
        else if(root->data >= item)
        {
            if(root->left==NULL)
            {
                break;
            }
            root=root->left;
        }
    }
    if(root->data < item)
    {
        root->right=new_node;
    }
    else
    {
        root->left=new_node;
    }
}
Node* constructBst(int arr[], int n)  //main() function calls this
{
    // Code here
    if(n==0)
    {
        return NULL;
    }
    Node* root=new Node(arr[0]);
    for(int i=1;i<n;i++)
    {
        insertNode(root,arr[i]);
    }
	return root;
}