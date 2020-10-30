#include <bits/stdc++.h>
using namespace std;
int main() {
   long long  int T;
    cin>>T;
    while(T--){
        long long int M, N,K;
        cin>>M>>N>>K;
       long long  int arr[M];
       long long  int sum=0;
        for(int i=0;i<M;i++){
            cin>>arr[i];
        }
           sort(arr, arr+M);
           for(long long int i=0 ;i<M;i++){
                  if(i<K){
               arr[i]=N-arr[i];}
               sum=sum+arr[i];
           }
           cout<<sum;
        cout<<"\n";
    }
    return 0;
}
