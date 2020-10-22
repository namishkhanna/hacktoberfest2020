#include<bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> arr, int target){
//check if any subset of array sums up to target
  int n = arr.size();
  int powerSet = pow(2, n);
  int s;
  for(int i = 0;i < powerSet; i++){
    s=0;
    for(int j = 0; j < n ; j++){
      if(i & 1<<j){
        //include jth element in subset
        s = s + a[j]; 
      }
    }
    if(s == target)
      return true;
  }
  return false;
}

int main(){

  //call here
  cout<<isSubsetSum({1,2,3,4,5}, 20); //false
  cout<<isSubsetSum({1,2,3,4,5}, 7); //true
  
}
