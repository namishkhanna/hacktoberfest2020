#include <bits/stdc++.h>
using namespace std;
int main(){
   //defining the array
   int arr1[] = { 1, 45, 54, 71, 76, 12 };
   int arr2[] = { 1, 7, 5, 4, 6, 12 };
   int n1 = sizeof(arr1) / sizeof(arr1[0]);
   int n2 = sizeof(arr2) / sizeof(arr2[0]);
   sort(arr1, arr1 + n1);
   sort(arr2, arr2 + n2);
   cout << "First Array: ";
   for (int i = 0; i < n1; i++)
      cout << arr1[i] << " ";
   cout << endl;
   cout << "Second Array: ";
   for (int i = 0; i < n2; i++)
      cout << arr2[i] << " ";
   cout << endl;
   vector<int> v(n1 + n2);
   vector<int>::iterator it, st;
   //finding the common elements
   it = set_intersection(arr1, arr1 + n1, arr2, arr2 + n2, v.begin());
   cout << "\nCommon elements:\n";
   for (st = v.begin(); st != it; ++st)
      cout << *st << ", ";
   cout << '\n';
   return 0;
}
