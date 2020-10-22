using System;

namespace inheritance
{
    class Program
    {
        static void Main(string[] args)
        {
            Chef c = new Chef();
            c.makeDish();
            c.makeBBQ();
            IndianChef i = new IndianChef();
            i.info();
            i.makeDish();
            i.makeBBQ();
        }
    }
    class Chef
    {
        public void makeDish()
        {
            Console.WriteLine("Chef makes Dish.");
        }
        public void makeSalad()
        {
            Console.WriteLine("Chef makes Salad");
        }
        public virtual void makeBBQ()
        {
            Console.WriteLine("Ched makes BBQ ribs.");
        }
    }
    class IndianChef : Chef
    {
        public override void makeBBQ()
        {
            Console.WriteLine("This is Overiding.");
        }
        public void info()
        {
            Console.WriteLine("Here I have Performed Inheritnce");
        }
    }

}
