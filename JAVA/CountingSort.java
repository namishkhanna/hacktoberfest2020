import java.util.Scanner;

public class CountingSort {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the length of the array: ");
        int length = sc.nextInt();
        System.out.print("Enter the value of the minimum possible array element: ");
        int min = sc.nextInt();
        System.out.print("Enter the value of the maximum possible array element: ");
        int max = sc.nextInt();

        int[] intArray = new int[length];

        System.out.print("Enter the array elements: ");
        for (int i = 0; i < length; i++) {
            intArray[i] = sc.nextInt();
        }

        //input example
        //int[] intArray = {4, 6, 2, 8, 3, 9, 3, 6, 1, 8};

        countingSort(intArray, min, max);

        System.out.print("Sorted array: ");
        for (int i = 0; i < intArray.length; i++) {
            System.out.print(intArray[i] + " ");
        }
        //output example
        //Sorted array: 

    }

    public static void countingSort(int[] input, int min, int max) {

        int[] countArray = new int [(max - min) + 1];

        for (int i = 0; i < input.length; i++) {
            countArray[input[i] - min]++;
        }

        int j = 0;
        for (int i = min; i <= max ; i++) {
            while (countArray[i - min] > 0) {
                input[j++] = i;
                countArray[i - min]--;
            }
        }

    }
}
