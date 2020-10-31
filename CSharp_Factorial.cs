using System;

public class Program
{
	public static void Main()
	{
		int parameter = 10;
		
		Console.WriteLine(RecursiveFatorial(parameter));
		Console.WriteLine(Fatorial(parameter));
	}

	public static int Fatorial(int i)
	{
		if (i < 2)
		{
			return 1;
		}

		for (int counter = i; counter > 1; counter--)
		{
			i = i * (counter - 1);
		}

		return i;
	}

	public static int RecursiveFatorial(int i)
	{
		if (i < 2)
		{
			return 1;
		}

		return i * RecursiveFatorial(i - 1);
	}
}