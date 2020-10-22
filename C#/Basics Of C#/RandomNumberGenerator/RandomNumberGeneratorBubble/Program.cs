using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RandomNumberGeneratorBubble
{
    class Program
    {
        static void Main(string[] args)
        {

            int min = 0;
            int max = 100;
            Console.WriteLine("enter the size of the array = ");
            int x = Int32.Parse(Console.ReadLine());

            int[] array = new int[x];
            Random rn = new Random();
            for (int i = 0; i < array.Length; i++)
            {
                array[i] = rn.Next(min, max);
                Console.WriteLine((i + 1) + " element of array=" + array[i]);
            }


            Program p1 = new Program();
            p1.BubbleSort(array, x);


            Console.ReadKey();
        }

        public void BubbleSort(int[] arr, int size)
        {
            DateTime start;
            DateTime end;
            start = DateTime.Now;
            Console.WriteLine("Time 1 : " + start);



            for (int i = 0; i < size - 1; i++)
                for (int j = 0; j < size - i - 1; j++)
                    if (arr[j] > arr[j + 1])
                    {
                        // swap temp and arr[i] 
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }

            Console.WriteLine("\n\n");

            Console.Write("Sorted array is: ");

            for (int i = 0; i < size; i++)
            {
                Console.Write(arr[i] + " ");
            }

            Console.WriteLine("\n\n");


            end = DateTime.Now;

            Console.WriteLine("Time 2 = " + end);

            Console.WriteLine("\n\n");

            String dif = end.Subtract(start).Milliseconds.ToString();

            Console.WriteLine("the time difference = " + dif);






        }








    

    }
}
