#include <iostream>
using namespace std;

int fibonacci(int n)
{
	int *arr = new int[n + 1];

	if (n < 2)
	{ 
		return 0;
	}
	if (2 == n) 
	{ 
		return 1; 
	}
	arr[1] = 0;
	arr[2] = 1;

	for (int i = 3; i <= n; i++) 
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	return arr[n];

}


template<typename T>
int compare(const T a,const T b)
{
	if (a > b)
	{
		return 1;
	}
	if (a < b)
	{
		return -1;
	}
	return 0;	
}


typedef char * ptr;
template<>
int compare<char *>(const ptr a, const ptr b)
{
	if (strcmp(a,b)>0)
	{
		return 1;
	}
	if (strcmp(a,b)<0)
	{
		return -1;
	}
	return 0;
}

template <typename T, typename L, typename PRE>
int Binarysearch(T a, L val, int left, int right, PRE compare)
{
	if (left>right)
	{
		return -1;
	}
	while (left <= right)
	{
		int mid = (right - left+1) / 2 + left;
		if (compare(val, a[mid]) == 1)
		{
			left = mid + 1;
		}
		if (compare(val, a[mid]) == -1)
		{
			right = mid - 1;
		}
		if(compare(val, a[mid]) == 0)
		{
			return mid;
			break;
		}
	}	
	return -1;
}


int main()
{
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	/*int m=fibonacci(9);
	cout << m<<endl;*/

	int m = Binarysearch(arr, 6, 0, 9, compare<int>);
	cout << m << endl;
	return 0;
}