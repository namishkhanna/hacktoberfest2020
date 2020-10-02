using System;

namespace Geeting_Input_from_User
{
    class getting_input
    {
        static void Main(string[] args)
        {
            Console.Write("Enter Your Name: ");
            string name = Console.ReadLine();
            Console.WriteLine("Hello!!! " + name);
            Console.Write("Enter the First Number:");
            int a = Convert.ToInt32(Console.ReadLine());
            Console.Write("Enter the Second Number:");
            int b = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Max is " + Math.Max(a,b));
        }
    }
}
