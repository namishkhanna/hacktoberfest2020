import java.util.*;
class armstrong{
    public static void main(String args[]){
        Scanner sc=new Scanner (System.in);
        System.out.println("Enter the number till armstrong number has to be found from 100");
        int n=sc.nextInt();    
        for(int i = 100; i <= n; ++i) {
            int digits = 0;
            int result = 0;
            int ognum = i;
            while (ognum != 0) {
                ognum /= 10;
                ++digits;
            }
            ognum = i;
            while (ognum != 0) {
                int remainder = ognum % 10;
                result += Math.pow(remainder, digits);
                ognum /= 10;
            }
            if (result == i)
                System.out.print(i + " ");
        }
    }
}
    