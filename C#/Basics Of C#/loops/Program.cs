using System;

namespace loops
{
    class Program
    {
        static void Main(string[] args)
        {
            
            int a = 1;
            while(a<=5)
            {
                Console.WriteLine(a);
                a++;
            }
            for(int i = 6; i<=10;i++)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine();
            Console.WriteLine(getpow(5, 2));
        }
        static int getpow(int baseNum, int powNum)
        {
            int result = 1;
            for(int b = 0;b<powNum;b++)
            {
                result = result * baseNum;
            }
            return result;
        }
    }
}
