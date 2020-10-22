//a C++ program for finding square root of a number with precision using Binary Search.
#include <iostream>
using namespace std;

int integralPart(int number) {
	int start = 0, end = number;
	int mid,ans;

	while(start <= end) {
		mid = (start+end)/2;
		if(mid*mid == number)
			return mid;
		else if(mid*mid > number) 
			end = mid - 1;
		else {
			ans = mid;
			start = mid + 1;
		}
	}
	return ans;
}

float decimalPart(float increment,float num,int number) {
	int start = 0, end = 9;
	int mid;
	float ans;
	while(start <= end) {
		mid = (start+end)/2;
		float currNum = mid*increment + num;
		if(currNum*currNum == number)
			return currNum;
		else if(currNum*currNum > number)
			end = mid - 1;
		else {
			ans = currNum;
			start = mid + 1;
		}
	}
	return ans;
}

float squareRootWithPrecision(int number, int precision) {
	int integral_part = integralPart(number);
	float increment = 0.1;
	float answer = integral_part;
	while(precision--) {
		answer = decimalPart(increment,answer,number);
		increment /= 10;
	}
	return answer;
}

int main() {
	int number,precision;
	cin>>number>>precision;

	cout<<squareRootWithPrecision(number,precision);
	return 0;
}
