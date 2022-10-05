import java.util.*;
class Solution {
    void printArray(int arr[], int n) {
        
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
   
    }//printing the elements of the Array.
    
    
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the Size of the Array");
        int n=sc.nextInt();
        System.out.println("Enter the elements of the Array");
        int A[]=new int[n];
        for(int i=0;i<n;i++)
            A[i]=sc.nextInt();
        Solution ob=new Solution();
            ob.printArray(A,n);
      }// Inputting the elements of the Array and calling the function using object of the class.
 }
