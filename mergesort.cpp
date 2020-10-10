//merg sort
# include <iostream>
# include <math.h>
using namespace std;
void merge(int a[],int b[],int c[],int s,int e){
	int mid = (s+e)/2;
	int i = s,j=mid+1,k=s;
	while(i<=mid&&j<=e){
		if(b[i] < c[j]){
			a[k] = b[i]; 
			k++;
			i++;
		}
		else{
			a[k++] = c[j++];
		}
	}
	while(j<=e){
		a[k++]=c[j++];
		}
	while(i<=mid){
		a[k++]=b[i++];
		}
}
void mergeSort(int *a,int s,int e){
	// base case
	if(s>=e){
		return;
	}
	// 1. Divide
	int mid = (s+e)/2;
	int b[100],c[100];
	for(int i = s;i<=mid;i++){
		b[i] = a[i];
	}
	for(int i=mid+1;i<=e;i++){
		c[i] = a[i];
	}
	// 2. Sort
	mergeSort(b,s,mid);
	mergeSort(c,mid+1,e);
	// 3. Merge
	merge(a,b,c,s,e);
}
void Print(int *a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
}
int main(){
     int i,n,a[10000];
    cin>>n;
    for ( i = 0; i < n; i++)
    {
        cin>>a[i];
    }
	mergeSort(a,0,n-1);
	Print(a,n);
	return 0;
}