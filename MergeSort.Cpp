#include <bits/stdc++.h>
using namespace std;

int arr[1000],temp[1000],len=0;

void merge(int l, int r){
	int k=0,mid=(r+l)/2;
	int i=l, j=mid+1, n1=mid-l+1;
	int n2=r-mid;
	
	
	while (i<n1+l && j<n2+mid+1){
		len++;
		if (arr[i]<arr[j]){
			temp[k]=arr[i];
			i++;
		} else{
			temp[k]=arr[j];
			j++;
		}
		k++;
	}
	
	while (i<n1+l){ //if the left side array remained
		temp[k]=arr[i];
		i++;
		k++;
	}
	
	while (j<n2+r){ //if the right side array remained
		temp[k]=arr[j];
		j++;
		k++;
	}
	
	k=0;
		
	for (i=l; i<=r; i++){
		arr[i]=temp[k];
		k++;
	}
	
}

void mergesort(int l, int r){
	int mid=(l+r)/2;
	
	if (l<r){
		
		mergesort(l,mid);
		mergesort(mid+1,r);	
		merge(l,r);
	}
	
	
}

int main(){
	int n,i;
	
	cin>>n;
	for(i=0; i<n; i++) cin>>arr[i];
	mergesort(0,n-1);
	for (i=0; i<n; i++) cout<<arr[i]<<" ";
	cout<<endl<<len<<endl;
}
