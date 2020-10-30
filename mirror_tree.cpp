//🤑Tree problems are best to understand the recursion calls state
//problem link:https://practice.geeksforgeeks.org/problems/mirror-tree/1/?track=DSASP-Tree&batchId=154
Node* temp=new Node(0);

void mirror(Node* node)
{
    if(node==NULL)
        return ;
    mirror(node->left);
    //👀 👀 we do not calculate temp here as the value of temp changes in every
    //recursion call stack state
    mirror(node->right);

    if(node->left&&node->right)
    {
         temp=node->left;
         node->left=node->right;
         node->right=temp;

    }
    else if(!node->left&&node->right)
    {

        node->left=node->right;
        node->right=NULL;
    }
     else if(node->left&&!node->right)
    {

        node->right=node->left;
        node->left=NULL;
    }
     // Your Code Here
}
