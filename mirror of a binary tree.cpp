#include<bits/stdc++.h> 
using namespace std; 

struct Node  
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
    
    Node(int x)
    {
    	data = x;
    	left = right = NULL;
	}
}; 
  
/* Helper function that allocates a new node with  
the given data and NULL left and right pointers. */

  
  
/* Change a tree so that the roles of the left and  
    right pointers are swapped at every node. 
  
So the tree... 
    4 
    / \ 
    2 5 
    / \ 
1 3 
  
is changed to... 
    4 
    / \ 
    5 2 
        / \ 
    3 1 
*/
void mirror(struct Node* node)  
{ 
    if (node == NULL)  
        return;  
    else
    { 
        //struct Node* temp; 
        mirror(node->left); 
        mirror(node->right); 

       	/*temp = node->left; 
        node->left = node->right; 
        node->right = temp;*/
		swap(node->left,node->right); 
    } 
}  
  
/* Helper function to print  
Inorder traversal.*/
void inOrder(struct Node* node)  
{ 
    if (node == NULL)  
        return; 
      
    inOrder(node->left); 
    cout << node->data << " "; 
    inOrder(node->right); 
}  
  
  
// Driver Code 
int main() 
{ 
    struct Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);  
      
    /* Print inorder traversal of the input tree */
    cout << "Inorder traversal of the constructed"
         << " tree is" << endl; 
    inOrder(root); 
      
    /* Convert tree to its mirror */
    mirror(root);  
      
    /* Print inorder traversal of the mirror tree */
    cout << "\nInorder traversal of the mirror tree"
         << " is \n";  
    inOrder(root); 
      
    return 0;  
} 
