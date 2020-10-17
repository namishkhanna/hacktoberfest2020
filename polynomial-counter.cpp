#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"derajat: ";
	cin>>n;
	int arr[n];
	
	int a0;
	cout<<"konstanta: ";
	cin>>a0;
	
	for(int i =0;i<n;i++){
		cout<<"koefisien pangkat "<<i+1<<": ";
		cin>>arr[i];
	}
	
	int x0;
	cout<<"pada titik x= ";
	cin>>x0;
	
	int hasil = a0;
	int pangkat = 1;

	for(int i=1;i<=3;i++){
		pangkat = pangkat*x0;
		hasil+= arr[i-1]*pangkat;		
	}
	cout<<"hasil: "<<hasil<<endl;
}
