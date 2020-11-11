import java.util.Scanner;

class CheckEvenOdd
{
  public static void main(String args[])
  {
    int num;
    System.out.println("Enter an Integer number:");
    Scanner input = new Scanner(System.in);
    num = input.nextInt();    
    if ( num & 1 )
        System.out.println("Entered number is odd");
     else
        System.out.println("Entered number is even");
  }
}
