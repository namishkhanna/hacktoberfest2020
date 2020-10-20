#include<iostream>
#include<ctime>
using namespace std;
//using namespace std::clock();

#define n 3
void transpose(int a[n][n],int b[n][n])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[j][i];
        }
    }
}

int main()
{
std::clock_t c_start = std::clock();
    int x[n][n],y[n][n];
    int k=0;

    for (int i = 0; i < n; i++)
    {
       for(int j=0;j<n;j++)
        {
          x[i][j] = k + 1;
          k++;
        }
    }
    for (int i = 0; i < n; i++)
    {
       for(int j=0;j<n;j++)
        {
          cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }

    transpose(x,y);
    cout<<endl;

       for (int i = 0; i < n; i++)
    {
       for(int j=0;j<n;j++)
        {
          cout<<y[i][j]<<" ";
        }
        cout<<endl;
    }
    std::clock_t c_end = std::clock();
    long double time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
    cout << "CPU time used: " << time_elapsed_ms << " ms\n";
    cout << "CPU time used: " << time_elapsed_ms / 1000.0 << " s\n";
}
