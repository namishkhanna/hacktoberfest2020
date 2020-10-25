import java.util.Scanner;

public class Calculator {
   public static void main(String [] args) {
       Scanner scnr = new Scanner(System.in); // Scanner will now read keyboard inputs

       double operand_1; // First operand entered by the user
       double operand_2; // Second operand entered by the user
       double response; // Response entered by the user for which calculation they want to perform

       System.out.print("Enter first operand:");
       operand_1 = scnr.nextDouble(); // Double value to allow for numbers with decimals

       System.out.print("Enter second operand: ");
       operand_2 = scnr.nextDouble();

       System.out.println("Calculator Menu");
       System.out.println("---------------");
       System.out.println("1. Addition");
       System.out.println("2. Subtraction");
       System.out.println("3. Multiplication");
       System.out.println("4. Division");
       System.out.print("Which operation do you want to perform? ");
       response = scnr.nextInt(); // Integer value because there is no need for a floating-point value

       if (response == 1) {
           System.out.print("The result of the operation is " + (operand_1 + operand_2) + ". Goodbye!");
       }
       else if (response == 2) {
           System.out.print("The result of the operation is " + (operand_1 - operand_2) + ". Goodbye!");
       }
       else if (response == 3) {
           System.out.print("The result of the operation is " + (operand_1 * operand_2) + ". Goodbye!");
       }
       else if (response == 4) {
           System.out.print("The result of the operation is " + (operand_1 / operand_2) + ". Goodbye!");
       }
       else {
           System.out.print("Error: Invalid selection! Terminating program."); // Program only allows responses 1-4
       }
   }
}
