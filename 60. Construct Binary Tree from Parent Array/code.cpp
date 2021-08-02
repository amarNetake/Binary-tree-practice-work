Node *createTree(int parent[], int n)
{
    // Your code here
    vector<Node*> vect;
    int root;
    for(int i=0;i<n;i++)
    {
        Node* new_node=new Node(i);
        vect.push_back(new_node);
    }
    for(int i=0;i<n;i++)
    {
        if(parent[i]==-1)
        {
            root=i;
        }
        else if(parent[i]!=-1 && vect[parent[i]]->left==NULL)
        {
            vect[parent[i]]->left=vect[i];
        }
        else if(parent[i]!=-1 && vect[parent[i]]->right==NULL)
        {
            vect[parent[i]]->right=vect[i];
        }
    }
    return vect[root];
}