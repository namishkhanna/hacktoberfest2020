using System;

namespace Methods
{
    class methods
    {
        static void Main(string[] args)
        {
            Sayhi("Aquib", 24);
            Sayhi("Maaz", 24);
            Sayhi("Nikhil", 20);
            double number = cube(5);
            Console.WriteLine(number);
        }
        static void Sayhi(string name,int age)
        {
            Console.WriteLine("Your Name is " + name + " and Age is " + age);
        }
        static double cube(double a)
        {
            double result = a * a * a;
            return result;
        }
    }
}
