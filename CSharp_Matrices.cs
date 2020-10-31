using System;

public class Program
{
	public static void Main()
	{
		Console.WriteLine("");
		int matriceSlots = 4;
		int[, ] matrice = new int[matriceSlots, matriceSlots];
		int[, ] secondMatrice = new int[matriceSlots, matriceSlots];
		for (int i = 0; i < matriceSlots; i++)
		{
			for (int j = 0; j < matriceSlots; j++)
			{
				matrice[i, j] = RandomNumber(-100, 100);
				secondMatrice[i, j] = RandomNumber(-100, 100);
			}
		}

		Console.WriteLine("Read 4x4 matrice and calculate the sum of the biggest and smallest element of it");
		double biggest = 0, smallest = 0, sum = 0;
		int contbiggest = 0, contsmallest= 0;
		for (int i = 0; i < matriceSlots; i++)
		{
			for (int j = 0; j < matriceSlots; j++)
			{
				double valorAtual = matrice[i, j];
				if (valorAtual > biggest)
				{
					biggest = valorAtual;
				}

				if (contbiggest == 0)
				{
					contbiggest++;
					biggest = valorAtual;
				}

				if (contsmallest == 0)
				{
					contsmallest++;
					smallest = valorAtual;
				}
				if (valorAtual < smallest)
				{
					smallest = valorAtual;
				}
			}
		}

		if (biggest < smallest)
		{
			biggest = biggest + smallest;
			smallest = biggest - smallest;
			biggest = biggest - smallest;
		}

		sum = biggest + smallest;
		
		printTwoDimensionalSquareMatrice(matrice, matriceSlots);
		Console.WriteLine("Biggest: " + biggest + " Smallest: " + smallest + " Sum: " + sum);
		Console.WriteLine("");
		Console.WriteLine("");
		Console.WriteLine("Read two matrices 4x4 and calculate the sum of both");
		printTwoDimensionalSquareMatrice(matrice, matriceSlots);
		Console.WriteLine("+");
		printTwoDimensionalSquareMatrice(secondMatrice, matriceSlots);
		Console.WriteLine("=");
		
		int[, ] matriceSum = new int[matriceSlots, matriceSlots];
		for (int i = 0; i < matriceSlots; i++)
		{
			for (int j = 0; j < matriceSlots; j++)
			{
				matriceSum[i, j] = matrice[i, j] + secondMatrice[i, j];
			}
		}

		printTwoDimensionalSquareMatrice(matriceSum, matriceSlots);
		
		Console.WriteLine("Read two matrices 4x4 and calculate the product of both");
		int[, ] matriceMultiplication = new int[matriceSlots, matriceSlots];
		
		for (int i = 0; i < matriceSlots; i++)
		{
			for (int j = 0; j < matriceSlots; j++)
			{
				matriceMultiplication[i, j] = matrice[i, j] * secondMatrice[i, j];
			}
		}
		
		printTwoDimensionalSquareMatrice(matrice, matriceSlots);
		Console.WriteLine("*");
		printTwoDimensionalSquareMatrice(secondMatrice, matriceSlots);
		Console.WriteLine("=");
		printTwoDimensionalSquareMatrice(matriceMultiplication, matriceSlots);

	}

	private static readonly Random random = new Random();
	private static readonly object syncLock = new object ();
	public static int RandomNumber(int min, int max)
	{
		lock (syncLock)
		{
			return random.Next(min, max);
		}
	}

	private static void printTwoDimensionalSquareMatrice(int[, ] matrice, int matriceSlots)
	{
		Console.WriteLine("");
		for (int i = 0; i < matriceSlots; i++)
		{
			for (int j = 0; j < matriceSlots; j++)
			{
				Console.Write(string.Format("{0} ", matrice[i, j]));
			}

			Console.Write(Environment.NewLine + Environment.NewLine);
		}

		Console.WriteLine("");
	}
}