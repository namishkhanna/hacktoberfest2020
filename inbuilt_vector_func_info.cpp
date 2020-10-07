#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a;
	/* M2  
	int arr[]={5,10,15,20,20,23}
	int n=sizeof(arr)/sizeof(arr[0])
	vector<int> vec(arr, arr+n)
	*/
	vector<int>vec;
	int a;
	for(int i=0; i<n; i++)
	{
		cin>>a;
		arr.push_back(a);
	}
	sort(vec.begin(), vec.end());    // sorts vector
	reverse(vec.begin(), vec.end());   //reverse vector
	int c=*max_element(vec.begin(), vec.end());     // max el of vector
	int d=*min_element(vec.begin(), vec.end());     // min el of vector
	accumulate(vec.begin(), vec.end(), 0);             // sum all vector el
	count(vec.begin(), vec.end(), 2);               // count occurence of an el
	find(vec.begin(), vec.end(), 2) != vec.end ? cout<<"2 found":cout<<"Not found";
	auto p=lower_bound(vec.begin(), vec.end(), 20);      //for vec={5,10,15,20,20,23,25}
	auto q=upper_bound(vec.begin(), vec.end(), 20);
	p-vec.begin();	           // o/p = 3
	q-vec.begin();             // o/p=5
	vec.erase(vec.begin()+1);      // delete 2nd el of vector
	vec.erase(unique(vec.begin(), vec.end()), vec.end()); // delete duplicate el
	next_permutation(vec.begin(), vec.end());     // o/p={5,10,20,20,25,23}
	prev_permutation(vec.begin(), vec.end());     // o/p={5,10,20,20,23,25}
	distance(vec.begin(), max_element(vec.begin(), vec.end()));   // dist=5
	
}
