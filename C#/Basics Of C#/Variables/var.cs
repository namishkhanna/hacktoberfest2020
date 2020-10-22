using System;
namespace Variables
{
    class Program
    {
        static void Main(string[] args)
        {
            string characterName = "Aquib";
            int age = 24;
            string subject;
            subject = "C#";
            Console.WriteLine("My name is " + characterName + ".\nMy age is " + age + " and i love to learn " + subject);
            subject = "Machine Learning";
            Console.WriteLine("I also love " + subject);
        }
    }
}
