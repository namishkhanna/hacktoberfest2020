//Shikhar Gupta

//How does a template work : A simple program using template to add two numbers.
#include <iostream>
using namespace std;

template<class T>
T add(T a, T b)
{
    return a+b;
};

int main()
{
  int a,b;
  cout << "Enter two numbers: ";
  cin >> a >> b;
  cout << add(a,b);
  float x,y;
  cout << "\nEnter two numbers: ";
  cin >> x >> y;
  cout << add(x,y);
}
