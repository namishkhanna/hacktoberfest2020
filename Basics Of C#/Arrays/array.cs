using System;

namespace Arrays
{
    class array
    {
        static void Main(string[] args)
        {
            int[] number = {1,2,4,6,8 };
            for(int i = 0; i <= 4; i++) 
            {
                Console.WriteLine(number[i]);
            }
            string[] lang = new string[3];
            lang[0] = "C++";
            lang[1] = "C#";
            lang[2] = "Python";
            Console.WriteLine(lang[0]);
            Console.WriteLine(lang[1]);
            Console.WriteLine(lang[2]);
        }
    }
}
