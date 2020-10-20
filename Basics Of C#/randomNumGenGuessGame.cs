using System;

namespace randomNumGenGuessGame
{
    class Program
    {
        static void Main(string[] args)
        {
            Random randomGen = new Random();
            int randomNum = randomGen.Next(0,100);
            int guess;
            int count = 0;
            int limit = 10;

            Console.WriteLine("Hello, Welcome to the RANDOM NUMBER GENERATOR GUESSING GAME! \nPlease guess a number between 0 and 100:");
            do
            {
                guess = int.Parse(Console.ReadLine());
                count++;
                if(guess < randomNum)
                {
                    Console.WriteLine("You guessed too low.  Guess again:");
                    Console.WriteLine($"You have {limit - count} guesses left.");
                }
                else if(guess > randomNum)
                {
                    Console.WriteLine("You guessed too high.  Guess again:");
                    Console.WriteLine($"You have {limit - count} guesses left.");
                }
                else
                {
                    Console.WriteLine($"YAY! You guessed the number {randomNum} in {count} guesses, great job!");
                }
            }while(guess != randomNum && count < limit);
            if(count >= limit)
            {
                Console.WriteLine($"GAME OVER!  Sorry you ran out of guesses.  The number was {randomNum}, try again.");
            }
        }
    }
}
