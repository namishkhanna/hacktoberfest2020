public static void main(String[] args) throws IOException {

             int quantity = 10000;
             int[] vector = new int[quantity];

             for (int i = 0; i < vector.length; i++) {
                     vector[i] = (int) (Math.random()*quantity);
             }

             long startTime = System.currentTimeMillis();

             quickSort(vector,0,vector.length-1);

             long finalTime = System.currentTimeMillis();

             System.out.println("Execution in = " + (finalTime - startTime) + " ms");

       }

       private static void quickSort(int[] vector, int start, int fim) {
             if (start < fim) {
                    int pivotPosition = split(vector, start, fim);
                    quickSort(vector, start, posicaoPivot - 1);
                    quickSort(vector, posicaoPivot + 1, fim);
             }
       }

       private static int split(int[] vector, int start, int fim) {
             int pivot = vector[start];
             int i = start + 1, f = fim;
             while (i <= f) {
                    if (vector[i] <= pivot)
                           i++;
                    else if (pivot < vector[f])
                           f--;
                    else {
                           int change = vector[i];
                           vector[i] = vector[f];
                           vector[f] = change;
                           i++;
                           f--;
                    }
             }
             vector[start] = vector[f];
             vector[f] = pivot;
             return f;
       }