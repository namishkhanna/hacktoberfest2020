#include <iostream>
using namespace std;

void display(int* arr,int n) {
	for(int i=0; i<n; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void merge(int* arr,int start,int end){
	int* temp = new int[end-start+1];
	int mid = (start+end)/2;
	int k = 0, i = start, j = mid+1;
	while(i <= mid and j <= end){
		if(arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}

	while(i <= mid) {
		temp[k++] = arr[i++];
	}

	while(j <= end) {
		temp[k++] = arr[j++];
	}

	for(int i=start; i<=end; ++i) {
		arr[i] = temp[i-start];
	}
}

void mergesort(int* arr,int start,int end) {
	if(start == end)
		return;
	int mid = (start+end)/2;
	mergesort(arr,start,mid);
	mergesort(arr,mid+1,end);
	merge(arr,start,end);
}

int main() {
	int n;
	cin>>n;

	int* arr = new int[n];
	for(int i=0; i<n; ++i) 
		cin>>arr[i];
	mergesort(arr,0,n-1);
	display(arr,n);
	return 0;
}
