/*
	When dir==1 signifies the current node is the right child of it's immediate parent and 
	 dir==0 signifies that the node is left child of it's immediate parent
	 So we will send dir as 0 when we call left subtree and dir=1 when we call right subtree.
	When the node is leaf node(i.e. node->left==NULL and node->right==NULL) 
	and dir=0 then we will add it's data to sum oterwise we will simply ignore that node.
*/

void findLeftLeafNodes(Node* root,int& sum,int dir)
{
    if(root==NULL)
    {
        return;
    }
    // If current node is leaf and it is on left side of its immediate parent (i.e. dir=0) then print that node
    if(root->left==NULL&&root->right==NULL&&dir==0)
    {
        sum=sum+root->data;
    }
    findLeftLeafNodes(root->left,sum,0);
    findLeftLeafNodes(root->right,sum,1);
}
int leftLeavesSum(Node *root)
{
    // Code here
    if(root==NULL)
    {
        return 0;
    }
    int sum=0;
    /*
    	Since we do not want to add root's data to sum if root node
     	is having left and right child null we initialize 'dir' as 1
    */
    int dir=1;
    findLeftLeafNodes(root,sum,dir); 
    return sum;
}