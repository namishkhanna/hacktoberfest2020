#include <iostream> 
using namespace std; 
  
int findSingle(int array[], int size) 
    { 
        // Do XOR of all elements and return 
        int res = array[0]; 
        for (int i = 1; i < size; i++) 
            res = res ^ array[i]; 
  
        return res; 
    } 
    
int main() 
    { 
        int array[] = {2, 7, 5, 4, 5, 7, 4,9,9}; 
        int n = sizeof(array) / sizeof(array[0]); 
        cout << "Element occurring once is " 
             << findSingle(array, n); 
        return 0; 
    } 
