/*

The question states that: 

Assume you have access to a function biased_toss() which returns 0 or 1 with a probability that's not 50-50 (but also not 0-100 or 100-0). 
You do not know the bias of the coin.

Write a function to simulate an unbiased coin toss from this biased one.

*/

/*

Solution: 

The observation is that if you have a biased coin that comes up heads with probability p, and if you flip the coin twice, then:

The probability that it comes up heads twice is p2
The probability that it comes up heads first and tails second is p(1-p)
The probability that it comes up tails first ands heads second is (1-p)p
The probability that it comes up tails twice is (1-p)2

This is a classic probability puzzle and to the best of my knowledge you can't do this with just two calls to the function. However, you can do this with a low expected number of calls to the function.

The observation is that if you have a biased coin that comes up heads with probability p, and if you flip the coin twice, then:

The probability that it comes up heads twice is p2
The probability that it comes up heads first and tails second is p(1-p)
The probability that it comes up tails first ands heads second is (1-p)p
The probability that it comes up tails twice is (1-p)2
Now, suppose that you repeatedly flip two coins until they come up with different values. If this happens, what's the probability that the first coin came up heads? Well, if we apply Bayes' law, we get that

P(first coin is heads | both coins are different) = P(both coins are different | first coin is heads) P(first coin is heads) / P(both coins are different)

P(first coin is heads | both coins are different) = p (1-p) / (2p(1-p)) = 1 / 2.

In other words, if you keep flipping two coins until they come up with different values, then take the value of the first coin you flipped, you end up making a fair coin from a biased coin!

Reference: https://stackoverflow.com/questions/5429045/c-puzzle-make-a-fair-coin-from-a-biased-coin/5429219#5429219

*/

#include <iostream>
using namespace std;

int biased_toss(); //gives 0 or 1 with unequal probability

int unbiased_toss() {
    int a = biased_toss();
    int b = biased_toss();

    while(a == b) {
        a = biased_toss();
        b = biased_toss();
    }

    return a;
}

int main() {
    return 0;
}