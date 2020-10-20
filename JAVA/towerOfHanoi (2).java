import java.util.Scanner;

public class towerOfHanoi {
    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        System.out.println("Enter no. of pegs");
        int n=in.nextInt();
        hanoi(n,'A','B','C');
    }
    

    static void hanoi(int n,char start,char mid,char end)
    {
        if(n==1){
        System.out.println("placed 1 from "+start+" to "+end);
        return;
        }
        hanoi(n-1,start,end,mid);
        System.out.println("placed "+n+" from "+start+" to "+end);
        hanoi(n-1,mid,start,end);
    }
    
}
