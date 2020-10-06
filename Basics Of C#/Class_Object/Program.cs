using System;

namespace Class_Object
{
    class Program
    {
        static void Main(string[] args)
        {
            Book b1 = new Book();
            b1.title = "Machine Learning";
            b1.author = "Andrew Ng";
            b1.pageNumber = 100;
            Console.WriteLine(b1.title);
            Console.WriteLine(b1.author);
            Console.WriteLine(b1.pageNumber);

            Student s1 = new Student("Aquib", "Machine Learning", 5);
            Student s2 = new Student("XYZ", "Data Science", 2);
            Console.WriteLine(s1.hasHonour());
            Console.WriteLine(s2.hasHonour());
        }
    }
    class Book
    {
        public string title;
        public string author;
        public int pageNumber;

        //lets create a constructor
        public Book()
        {
            Console.WriteLine("Welcome To the World of AI");
        }
    }

    class Student
    {
        public string name;
        public string subject;
        public int gpa;
        public Student(string n,string sub,int GPA)
        {
            name = n;
            subject = sub;
            gpa = GPA;
        }
        public bool hasHonour()
        {
            if(gpa>3)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
