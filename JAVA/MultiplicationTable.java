public class MultiplicationTable {
    public static void main(String args[]) {
        int[][] table = new int[10][10];

        for (int row=0; row < table.length; row++){
            for (int col=0; col<table.length; col++){
                table[row][col] = (row+1) * (col+1);
            }
        }

        // Prints column headings
        System.out.printf("%6s", "");
        for (int col = 0; col < table[0].length; col++) {
            System.out.printf("%6d", col+1);
        }
        System.out.println();

        for (int row = 0; row < table.length; row++) {
            // Prints row headings
            System.out.printf("%6d", row+1);

            for (int col = 0; col < table[row].length; col++) {
                System.out.printf("%6d", table[row][col]);
            }
            System.out.println();
        }
    }
}
