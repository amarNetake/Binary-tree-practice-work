class BST{
    public:
        int min;
        int max;
        bool isBST;
        Node* ROOT;
        int sizeBST;
};

BST biggestBST(Node* root)
{
    if(root==NULL)
    {
        BST t;
        t.min=INT_MAX;
        t.max=INT_MIN;
        t.isBST=true;
        t.ROOT=NULL;
        t.sizeBST=0;
        return t;
    }
    BST lh=biggestBST(root->left);
    BST rh=biggestBST(root->right);
    
    BST result;
    result.isBST= (lh.isBST==true) && (rh.isBST==true) && (root->data > lh.max) && (root->data < rh.min);
    result.min= min(min(lh.min,rh.min),root->data);
    result.max= max(max(lh.max,rh.max),root->data);
    
    if(result.isBST==true)
    {
        result.ROOT= root;
        result.sizeBST= lh.sizeBST + rh.sizeBST + 1;
    }
    else if(result.isBST==false)
    {
        if(lh.sizeBST >= rh.sizeBST)
        {
            result.ROOT=lh.ROOT;
            result.sizeBST=lh.sizeBST;
        }
        else 
        {
            result.ROOT=rh.ROOT;
            result.sizeBST=rh.sizeBST;
        }
    }
    
    return result;
}
int largestBst(Node *root)
{
	//Your code here
	if(root==NULL)
	{
	    return 0;
	}
	BST result= biggestBST(root);
	return result.sizeBST;
}