import java.time.LocalDate;
import java.time.Period;
import java.util.Scanner;

public class AgeCalculator {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your birth year: ");
        int year = sc.nextInt();
        System.out.println("Enter your birth month: ");
        int month = sc.nextInt();
        System.out.println("Enter your birth date: ");
        int date = sc.nextInt();
        LocalDate birthDate = LocalDate.of(year,month,date);
        LocalDate current = LocalDate.now();
        Period age = Period.between(birthDate,current);
        System.out.println("You are " +age.getYears() + " years old.");
    }
}
