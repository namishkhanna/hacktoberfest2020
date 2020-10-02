using System;

namespace working_with_string
{
    class workingWithStrings
    {
        static void Main(string[] args)
        {
            string phrase = "Machine Learning";
            Console.WriteLine("Hello\"World!");
            Console.WriteLine("Length of "+ phrase + " is "+ phrase.Length);
            Console.WriteLine(phrase.ToUpper());
            Console.WriteLine(phrase.ToLower());
            Console.WriteLine(phrase.Contains("Learning"));
            Console.WriteLine(phrase[0]);
            Console.WriteLine(phrase.IndexOf("Learning"));
            Console.WriteLine(phrase.Substring(8,3));// used to grab the text after particular index

        }
    }
}
