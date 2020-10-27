// C program for recursive level order traversal in spiral form
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newnode(int data) //function to create new node
{
  struct node * temp=(struct node*) malloc(sizeof(struct node));
  temp->data=data;
  temp->left=temp->right=NULL;
  return temp;
}

struct node* insert(int arr[],struct node*root,int i,int n)
{
  if (i<n)
  {
    struct node*temp=newnode(arr[i]);
    root=temp;
    root->left=insert(arr,root->left,2*i+1,n);
    root->right=insert(arr,root->right,2*i+2,n);
  }
  return root;
}

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level, int ltr)
{
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1) {
		if (ltr) {
			printGivenLevel(root->left, level - 1, ltr);
			printGivenLevel(root->right, level - 1, ltr);
		}
		else {
			printGivenLevel(root->right, level - 1, ltr);
			printGivenLevel(root->left, level - 1, ltr);
		}
	}
}

int height(struct node* node)
{
	if (node == NULL)
		return 0;
	else {
		/* compute the height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

		/* use the larger one */
		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
	}
}

/* Function to print spiral traversal of a tree*/
void printSpiral(struct node* root)
{
	int h = height(root);
	int i;

	/*ltr -> Left to Right. If this variable is set,
	then the given level is traversed from left to right. */
	bool ltr = false;
	for (i = 1; i <= h; i++) {
		printGivenLevel(root, i, ltr);

		/*flip the ltr to traverse next level in opposite direction*/
		ltr = !ltr;
	}
}

/* Driver program*/
int main()
{
	int n,i;
  printf("Enter no.of nodes");
  scanf("%d",&n);
  int *A=(int*)malloc(n*sizeof(int)) ;
	printf("\nEnter nodes:\n");
	for(i=0;i<n;i++)
    scanf("%d",A+i);
  struct node *root=insert(A,root,0,n);
	printf("Level Order traversal in Spiral form: \n");
	printSpiral(root);
	return 0;
}
