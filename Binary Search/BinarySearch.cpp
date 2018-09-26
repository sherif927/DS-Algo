#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

int arr[10] = {1, 2, 2, 3, 3, 3, 4, 5, 6, 6};
int sarr[9] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
int n = 10;

//Finds First/Last Occurance of a number in an array.
int FindOccurance(int x,bool first)
{
	int low = 0,high=n-1,mid,result=-1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(x == arr[mid])
		{
			result = mid;
			if(first) high = mid - 1;
			else low = mid + 1;
		}
		else if(x < arr[mid])
		{
			high = mid - 1;
		}
		else if( x > arr[mid])
		{
			low = mid + 1;
		}

	} return result;
}

//Finds the number of occurances of a number in an array.
int FindOccurances(int x)
{
	int n = FindOccurance(x, true);
	int m = FindOccurance(x, false);
	return ((m - n) == 0) ? 1 : (m - n + 1);
}

int FindIndexInRotatedArray(int x)
{
	int low = 0, high = n - 2, mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(x == sarr[mid]) return mid;
		
		if(sarr[mid] <= sarr[high])
		{
			if(x > sarr[mid] && x <= sarr[high])
				low = mid + 1;
			else
				high = mid - 1;
		}
		else
		{
			if(x < sarr[mid] && x >= sarr[low])
				high = mid - 1;
			else
				low = mid + 1;
		}
	} 
	return -1;
}

//Finds the number of times than an array has been rotated.
int ShiftNumber()
{
	int low = 0, high = n - 2, mid, next , prev;
	while(low <= high)
	{
		if(sarr[low] <= sarr[high])
		{
			return low;
		}
		else
		{
			mid = (low + high) / 2;
			next = (mid + 1) % (n - 1);
			prev = (mid + n - 2) % (n - 1);
			if(sarr[mid] <= sarr[next] && sarr[mid] <= sarr[prev])
			{
				return mid;
			}
			else if(sarr[mid]> sarr[high])
			{
				low = mid + 1;
			}
			else if( sarr[mid] < sarr[low] )
			{
				high = mid - 1;
			}
		}
	} return -1;
}

//Finds the index of a given number in an array.
int BinarySearch(int x)
{
	int low = 0, high = n - 1, mid;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(arr[mid] == x)
			return mid;
		else if(x < arr[mid])
			high = mid - 1;
		else if(x > arr[mid])
			low = mid + 1;
	} return -1;
}


int main()
{	
	cout << FindIndexInRotatedArray(4)<<endl;
	system("pause");
}

