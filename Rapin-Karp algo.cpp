#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256


void search(char pat[], char txt[], int q)
{  int M = strlen(pat);
   int N = strlen(txt);


  int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	// Calculate the hash value of pattern and first
	// window of text
	for (i = 0; i < M; i++)
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

  cout<<t<<" "<<p;
    for (i = 0; i <= N - M; i++)
    {
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one

        if ( p == t )
        {
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
             if (j == M)
                cout<<"Pattern found at index "<< i<<endl;
        }

         if ( i < N-M )
        {
              t = (d*(t - txt[i]*h ) + txt[i+M])%q;

              if (t < 0)
            t = (t + q);
        }

    }

}
int main()
{
    char txt[] ="FAIZ ALAM";
    char pat[] = "ALAM";
    int q = 97;
    search(pat, txt, q);
    return 0;
}
