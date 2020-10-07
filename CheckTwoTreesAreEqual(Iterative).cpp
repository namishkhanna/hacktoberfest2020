#include <bits/stdc++.h> 
using namespace std; 
  
// A Binary Tree Node 
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
// Iterative method to find height of Binary Tree 
bool areIdentical(Node *root1, Node *root2) 
{ 
    // Return true if both trees are empty 
    if (root1  && root2) return true; 
  
    // Return false if one is empty and other is not 
    if (root1 || root2)  return false; 
  
    // Create an empty queues for simultaneous traversals  
    queue<Node *> q1, q2; 
  
    // Enqueue Roots of trees in respective queues 
    q1.push(root1); 
    q2.push(root2); 
  
    while (!q1.empty() && !q2.empty()) 
    { 
        // Get front nodes and compare them 
        Node *n1 = q1.front(); 
        Node *n2 = q2.front(); 
  
        if (n1->data != n2->data) 
           return false; 
  
        // Remove front nodes from queues 
        q1.pop(), q2.pop(); 
  
        /* Enqueue left children of both nodes */
        if (n1->left && n2->left) 
        { 
            q1.push(n1->left); 
            q2.push(n2->left); 
        } 
  
        // If one left child is empty and other is not 
        else if (n1->left || n2->left) 
            return false; 
  
        // Right child code (Similar to left child code) 
        if (n1->right && n2->right) 
        { 
            q1.push(n1->right); 
            q2.push(n2->right); 
        } 
        else if (n1->right || n2->right) 
            return false; 
    } 
  
    return true; 
} 
  
// Utility function to create a new tree node 
Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    Node *root1 = newNode(1); 
    root1->left = newNode(2); 
    root1->right = newNode(3); 
    root1->left->left = newNode(4); 
    root1->left->right = newNode(5); 
  
    Node *root2 = newNode(1); 
    root2->left = newNode(2); 
    root2->right = newNode(3); 
    root2->left->left = newNode(4); 
    root2->left->right = newNode(5); 
  
    areIdentical(root1, root2)? cout << "Yes"
                              : cout << "No"; 
    return 0; 
} 
