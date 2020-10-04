#include  <stdio.h>
#include  <stdlib.h>
#include  <conio.h>

struct  node
{
    int  data ;
    struct  node  *left, *right ;
} ;

struct  node  *root = NULL ;


int  ncount, lcount ;

/* This function will insert a new node as a leaf node in the BST */
void  insert(int  x)
{
    struct  node  *pnode, *p, *follow ;
    pnode=(struct node*)malloc(sizeof(struct node)) ;
    if(pnode==NULL)
        {
            printf("\nMemory overflow. Unable to create.") ;
            return ;
        }
    pnode->data=x ;
    /* A new node is always inserted as leaf node */
    pnode->left=pnode->right=NULL ;
    if(root==NULL) /* Tree is empty */
        root=pnode ;
    else
        {
            /* searching the place of insertion*/
            follow=NULL ;
            while(p!=NULL)
                {
                    follow=root;
                    if(pnode->data<root->data)
                        root=root->left ;
                    else
                        root=root->right ;
                }
            /* Actual insertion */
            if(pnode->data<follow->data)
                follow->left=pnode ;
            else
                follow->right=pnode ;
        }
}

/* This function is responsible for creating a BST with multiple nodes */
void  create()
{
    int  x, i, n ;
    printf("Enter the number of nodes required:\n") ;
    scanf("%d",&n) ;
    printf("Enter the data value of each node:\n") ;
    for(i=1 ; i<=n ; i++)
        {
            scanf("%d",&x) ;
            insert(x) ;
        }
}

/* Binary Tree Traversal methods */
void  preorder(struct  node  *root)
{
    if(root!=NULL)
        {
            printf("%d ", root->data) ;
            preorder(root->left) ;
            preorder(root->right) ;
        }
}

void  inorder(struct  node  *root)
{
    if(root!=NULL)
        {
            inorder(root->left) ;
            printf("%d ", root->data) ;
            inorder(root->right) ;
        }
}

void  postorder(struct  node  *root)
{
    if(root!=NULL)
        {
            postorder(root->left) ;
            postorder(root->right) ;
            printf("%d ", root->data) ;
        }
}


void  deletenode(int  k)
{
    struct  node  *p, *follow, *t, *f ;
    /* Searching the node to be deleted */
    p=root ;
    follow=NULL ;
    while(p!=NULL)
        {
            if(p->data==k)
                break ;
            follow=p ;
            if(k<p->data)
                p=p->left ;
            else
                p=p->right ;
        }
    if(p==NULL)
        printf("Required node not found. \n") ;
    else
        {
            /* Actual Deletion */
            /* Deleting a leaf node or a node with empty left subtree */
            if(p->left==NULL)
                if(p!=root)
                    if(follow->left==p)
                        follow->left=p->right ;
                    else
                        follow->right=p->right ;
                else
                    root=p->right ;
            /* Deleting node with empty right subtree */
            else if(p->right==NULL)
                if(p!=root)
                    if(follow->left==p)
                        follow->left=p->left ;
                    else
                        follow->right=p->left ;
                else
                    root=p->left ;
            /* Deleting a node with non-empty left and right subtrees */
            else
                {
                    t=p->right ;
                    f=p ;
                    while(t->left!=NULL)
                        {
                            f=t ;
                            t=t->left ;
                        }
                    p->data=t->data ;
                    if(f!=p)
                        f->left=t->right ;
                    else
                        f->right=t->right ;
                    p=t ; 
                }
            free(p);
        }
}

/* This fn will search a node with value k in BST */
void  search(int  k)
{
    struct  node  *p ;
    /* Searching the required node */
    p=root ;
    while(p!=NULL)
        {
            if(p->data==k)
                break ;
            if(k<p->data)
                p=p->left ;
            else
                p=p->right ;
        }
    if(p==NULL)
        printf("Required node not found. \n") ;
    else
        printf("Node found at address %X. \n",p) ;
}


void main()
{
    int  x, k, ch ;

    do
        {
            printf("1.Create. \n") ;
            printf("2.Insert. \n") ;
            printf("3.Preorder. \n") ;
            printf("4.Inorder. \n") ;
            printf("5.Postorder. \n") ;
            printf("6.Delete Node. \n") ;
            printf("7.Search \n") ;
            printf("8.Exit\n") ;
            printf("Enter your choice: ") ;
            scanf("%d",&ch) ;
            switch(ch)
                {
                case 1:
                    create() ;
                    break ;
                case 2:
                    printf("Enter the data value of new node: ") ;
                    scanf("%d",&x) ;
                    insert(x) ;
                    break ;
                case 3:
                    preorder(root) ;
                    printf("\n") ;
                    break ;
                case 4:
                    inorder(root) ;
                    printf("\n") ;
                    break ;
                case 5:
                    postorder(root) ;
                    printf("\n") ;
                    break ;
                case 6:
                    printf("Enter data of the node to be deleted: ") ;
                    scanf("%d",&k) ;
                    deletenode(k) ;
                    break ;
                case 7:
                    printf("Enter data of the node to be searched: ") ;
                    scanf("%d",&k) ;
                    search(k) ;
                    break ;

                }
        }
    while(ch!=8) ;
    getch() ;
}









