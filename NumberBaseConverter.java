import com.sun.xml.internal.bind.v2.runtime.output.SAXOutput;
import com.sun.xml.internal.bind.v2.runtime.output.StAXExStreamWriterOutput;

import java.util.Scanner;

public class NumberBaseConverter {
    public static void main (String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        System.out.print("Your number in binary: ");
        System.out.println(toBinary(num));
        System.out.print("Your number in Hexadecimal: ");
        System.out.println(toHex(num));
        System.out.println("-----Happy Hacktoberfest 2020!-----");
    }
    public static String toBinary(int num) {
        String binaryNum = "";
        while (num != 0) {
            if (num % 2 == 1) {
                binaryNum = binaryNum.concat("1");
            }
            if (num % 2 == 0) {
                binaryNum = binaryNum.concat("0");
            }
            num /= 2;
        }
        return "0b" + reverseString(binaryNum);
    }
    public static String reverseString(String s) {
        String result = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            result = result + s.charAt(i);
        }
        return result;
    }
    public static String toHex(int num) {
        String hexNum = "";
        while (num != 0) {
            int r = num % 16;
            char rChar = Character.toUpperCase(Character.forDigit(r, 16));
            hexNum = hexNum + rChar;
            num /= 16;
        }
        return "0x" + reverseString(hexNum);
    }

}
