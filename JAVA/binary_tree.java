package MyPackage;
  
public class Tree { 
    static class Node {    
    int value; 
        Node left, right; 
          
        Node(int value){ 
            this.value = value; 
            left = null; 
            right = null; 
        } 
    } 
       
    public void insert(Node node, int value) {
        if (value < node.value) { if (node.left != null) { insert(node.left, value); } else { System.out.println(" Inserted " + value + " to left of " + node.value); node.left = new Node(value); } } else if (value > node.value) {
          if (node.right != null) {
            insert(node.right, value);
          } else {
            System.out.println("  Inserted " + value + " to right of "
                + node.value);
            node.right = new Node(value);
          }
        }
      }
     public void traverseInOrder(Node node) {
        if (node != null) {
            traverseInOrder(node.left);
            System.out.print(" " + node.value);
            traverseInOrder(node.right);
        }
     }
     
     public static void main(String args[]) 
    { 
    Tree tree = new Tree();
                Node root = new Node(5);
                System.out.println("Binary Tree Example");
                System.out.println("Building tree with root value " + root.value);
                tree.insert(root, 2);
                tree.insert(root, 4);
                tree.insert(root, 8);
                tree.insert(root, 6);
                tree.insert(root, 7);
                tree.insert(root, 3);
                tree.insert(root, 9);
                System.out.println("Traversing tree in order");
                tree.traverseLevelOrder();
                
              }
}
