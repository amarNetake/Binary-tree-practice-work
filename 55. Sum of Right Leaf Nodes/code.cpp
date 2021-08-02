/*
	When dir==1 signifies the current node is the right child of it's immediate parent and 
	 dir==0 signifies that the current node is left child of it's immediate parent
	 So we will send dir as 0 when we call left subtree and dir=1 when we call right subtree.
	When the node is leaf node(i.e. node->left==NULL and node->right==NULL) 
	and dir=1 then we will add it's data to sum oterwise we will simply ignore that node.
*/
void sumOfRightLeaves(Node* root,int& sum,int dir)
{
    if(root==NULL)
    {
        return;
    }
    // If current node is leaf and it is on right side of its immediate parent (i.e. dir=1) then print that node
    if(root->left==NULL&&root->right==NULL&&dir==1) 
    {
        sum = sum + root->data;
        return;
    }
    sumOfRightLeaves(root->left,sum,0);
    sumOfRightLeaves(root->right,sum,1);
}

int rightLeafSum(Node* root)
{
     //Code here
     if(root==NULL)
     {
         return 0;
     }
     int sum=0;
     /*
    	Since we do not want to add root's data to sum if root node
     	is having left and right child null we initialize 'dir' as 0
    */
     int dir=0;
     sumOfRightLeaves(root,sum,dir);
     return sum;
}