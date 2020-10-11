using System;

namespace ifStatement
{
    class Program
    {
        static void Main(string[] args)
        {
            max();
        }
        static void max()
        {
            Console.Write("Enter First Number: ");
            double a = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter Second Number: ");
            double b = Convert.ToDouble(Console.ReadLine());
            if(a>b)
            {
                Console.WriteLine(a + " is Greater than " + b);
            }
            else if(a==b)
            {
                Console.WriteLine("Both Numbers are Equal");
            }
            else
            {
                Console.WriteLine(b + " is Greater than " + a);
            }
        }
    }
}
