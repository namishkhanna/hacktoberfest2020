
package rmi;
import java.rmi.*;
public class Client {
   public static void main(String args[]) throws Exception 
   {
       AddI obj = (AddI)Naming.lookup("ADD");
       int n = obj.add(5,4);
       System.out.println("Addition is : "+n);
   }
}
