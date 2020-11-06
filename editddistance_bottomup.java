import java.util.*;
 public class editddistance_bottomup
 {
    static int min(int x,int y,int z) 
	    { 
	        if (x <= y && x <= z) 
	        	return x; 
	        if (y <= x && y <= z) 
	        	return y; 
	        else return z; 
	    } 
	  
	    static int editDistDP(String str1, String str2, int m, int n) 
	    { 
	        int result[][] = new int[m+1][n+1]; 
	       
	        for (int i=0; i<=m; i++) 
	        { 
	            for (int j=0; j<=n; j++) 
	            { 
	                if (i==0) 
	                    result[i][j] = j;  
	                else if (j==0) 
	                    result[i][j] = i; 
	                else if (str1.charAt(i-1) == str2.charAt(j-1)) 
	                    result[i][j] = result[i-1][j-1]; 
	                else
	                    result[i][j] = 1 + min(result[i][j-1], result[i-1][j], result[i-1][j-1]); 
	            } 
	        } 
	   
	        return result[m][n]; 
	    } 
	  
	    public static void main(String args[]) 
	    { 
	    	Scanner sc=new Scanner(System.in);
		    System.out.println("Enter first string");
		    String str1=sc.nextLine();
		    System.out.println("Enter the second string");
		    String str2=sc.nextLine();	
			System.out.println( editDistDP( str1 , str2 , str1.length(), str2.length()) ); 
	    } 
}
