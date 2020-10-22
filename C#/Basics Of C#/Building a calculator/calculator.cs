using System;

namespace Building_a_calculator
{
    class calculator
    {
        static void Main(string[] args)
        {
            Console.Write("Enter First Number:");
            double a = Convert.ToDouble(Console.ReadLine());
            Console.Write("Enter Second Number: ");
            double b = Convert.ToDouble(Console.ReadLine());
            double sum = a + b;
            double sub = a - b;
            double mul = a * b;
            Console.WriteLine("Sum :" + sum);
            Console.WriteLine("Subtraction :" + sub);
            Console.WriteLine("Multiplication :" + mul);

        }
    }
}
