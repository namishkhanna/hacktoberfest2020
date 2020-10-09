import java.util.Scanner;

public class InsertionSort {
    public static void main(String[] args) {
        int n;
        Scanner input = new Scanner(System.in);
        System.out.print("array size: ");
        n = input.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }

        int x, temp;
        for (int i = 1; i < n; i++) {
            x = i;
            for (int j = x - 1; j >= 0; j--) {
                if (arr[j] > arr[x]) {
                    temp = arr[x];
                    arr[x] = arr[j];
                    arr[j] = temp;
                    x--;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
