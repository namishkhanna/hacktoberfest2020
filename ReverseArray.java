import java.io.*;
import java.util.*;
public class ReverseArray {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the size of the array: ");
        int x = Integer.parseInt(br.readLine());
        
        int[] arr = new int[x];
        System.out.println("Enter the elements of the Array: ");
        String[] st = br.readLine().split(" ");
        
        for(int i=0;i<x;i++){
            arr[i] = Integer.parseInt(st[i]);
        }
        
        int temp;
        int start = 0;
        int end = x-1;
        
        while(start<end){
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }

        for(int i=0;i<x;i++){
            System.out.print(arr[i]+" ");
        }
    }
}
