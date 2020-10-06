using System;

namespace switchStatement
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(getDay(5));
        }
        static string getDay(int dayNum)
        {
            string dayname;
            switch(dayNum)
            {
                case 1:
                    dayname = "Monday";
                    break;
                case 2:
                    dayname = "Tuesday";
                    break;
                case 3:
                    dayname = "Wednesday";
                    break;
                case 4:
                    dayname = "Thursday";
                    break;
                case 5:
                    dayname = "Friday";
                    break;
                case 6:
                    dayname = "Saturday";
                    break;
                case 7:
                    dayname = "Sunday";
                    break;
                default:
                    dayname = "Invalid Number";
                    break;
            }
            return dayname;
        }
    }
}
