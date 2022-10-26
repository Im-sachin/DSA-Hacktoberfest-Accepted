#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int sum(int arr[], int n)
{
	int sum = 0; 

	for (int i = 0; i < n; i++)
	{
	sum += arr[i];
	}
	return sum;
}

// Driver code
int main()
{
	//int arr[] = {12, 3, 4, 15};
	int n,arr[50],i;
	cout << "Enter the size of the array:";
	cin >> n;
	cout << "Enter the Elements of the array: ";
	for (i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	//int n = sizeof(arr) / sizeof(arr[0]);
	sum(arr,n);
	cout << "Sum of given array is " << sum(arr,n);
	return 0;
}