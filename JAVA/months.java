/*Java Program to demonstrate the example of Switch statement where print month name for the given number*/
  
import java.util.Scanner;
public class MONTH
{
    public static void main(String args[])
    {
     System.out.println("Enter Number: ");
     ABC F=new ABC();
     F.display();
   }
} 
class ABC
{
   Scanner A = new Scanner(System.in);
   int N=A.nextInt();
   public void display()
    {
   switch(N)
   {
       case 1:
   System.out.println("January");
   break;
 case 2:
           System.out.println("February");
           break;
 case 3:
           System.out.println("March");
           break;
case 4:
           System.out.println("April");
           break;
case 5:
           System.out.println("May");
           break;
case 6:
           System.out.println("June");
           break;
case 7:
           System.out.println("July");
           break;
case 8:
           System.out.println("August");
           break;
case 9:
           System.out.println("September");
           break;
case 10:
           System.out.println("October");
           break;
case 11:
           System.out.println("November");
           break;
case 12:
           System.out.println("December");
           break;
default:
           System.out.println("Not A Valid Month");
           break;
     
      }
    }
}
