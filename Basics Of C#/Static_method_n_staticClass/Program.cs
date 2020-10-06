using System;

namespace Static_method_n_staticClass
{
    class Program
    {
        static void Main(string[] args)
        {

            Tools.Sayhi("Aquib");//here we class member function of class Tools without creating its object as function is static.
        }
    }
    class Tools
    {
        public static void Sayhi(string name)
        {
            Console.WriteLine("Hello " + name);
        }
    }
}
