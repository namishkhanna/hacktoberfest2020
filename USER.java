import java.util.*;
class user
{
    public static void main()
    {
        Scanner in=new Scanner(System.in);
        int x, y;
        System.out.println("Enter the number");
        y=in.nextInt();
        System.out.println("Enter choice");
        x=in.nextInt();
        user obj=new user();
        switch(x)
        {
            case 1:obj.isMagic(y);
            break;
            case 2:obj.sort();
            break;
            default:System.out.println("Invalid choice");
            break;
        }
    }
    public void isMagic(int n)
    {
        int d, s=0;
        do
        {
            while(n>0)
            {
                d=n%10;
                s=s+d;
                n=n/10;
            }
            n=s;
            s=0;
        }
        while(n>9);
        if(n==1)
        System.out.println("Magic Number");
        else
        System.out.println("Not a Magic Number");
    }
    void sort()
    {
        Scanner in=new Scanner(System.in);
        System.out.println("Enter the length of array");
        int n=in.nextInt();
        int arr[]=new int[n];
        System.out.println("Enter the numbers in the array");
        for(int i=0;i<n;i++)
        {
            arr[i]=in.nextInt();
        }
        System.out.println("The numbers in the array are :");
        for(int i=0;i<n;i++)
        {
            System.out.println(arr[i]);
        }
        int temp=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]<arr[j])
                {
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                }
            }
        }
        System.out.println("The sorted array in descending order is :");
        for(int i=0;i<n;i++)
        {
            System.out.println(arr[i]);
        }
    }   
}
