bool hasPathSum(Node *node, int sum) {
    // Your code here
    if(node==NULL)
    {
        return false;
    }
    if(node->left==NULL&&node->right==NULL&&sum - node->data==0)
    {
        return true;
    }
    else if(node->left==NULL&&node->right==NULL&&(sum - node->data)!=0)
    {
        return false;
    }
    bool result=hasPathSum(node->left,sum - node->data);
    if(result==true)
    {
        /*If we got one such result where sum of all nodes from root to 
          any of the leaf node is zero then we can simply return true and 
          no need of furthur computation as we need only one such path from
          root to any of leaf which results in given sum.
        */
        return true; 
    }
    else
    {
        /* If above call returned false then we need to keep on checking
            on the right of current node if we get the desired sum in another
            path.
        */
        result=hasPathSum(node->right,sum - node->data);
    }
    return result;
}