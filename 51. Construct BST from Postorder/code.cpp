// For a given BST and postorder traversal OR for a given BST and preorder traversal there is a unique tree possible.
void insertNode(Node* root,int item)
{
    if(root==NULL)
    {
        return;
    }
    Node* new_node=new Node(item);
    while(root!=NULL)
    {
        if(root->data < item)
        {
            if(root->right==NULL)
            {
                break;
            }
            root=root->right;
        }
        if(root->data >= item)
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

Node *constructTree (int post[], int n)
{
//code here
    if(n==0)
    {
        return NULL;
    }
    Node* root=new Node(post[n-1]);
    for(int i=n-2;i>=0;i--)
    {
        insertNode(root,post[i]);
    }
    return root;
}