#include<stdio.h>

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low <= high)
	{
		mid = (low + high) / 2;
		if(v[mid] < x)
		  low = mid + 1;
		else if(v[mid] > x)
		  high = mid - 1;
		else
		  return mid;
	}
	return -1;
}

int rtbinsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low + high) / 2;
	while(low <= high && v[mid] != x)
	{
		if( v[mid] > x)
		  high = mid - 1;
		else
		  low = mid + 1;
		mid = (low + high) / 2;
	}

	if(low <= high)
	  return mid;
	else
	  return -1;
}

int main()
{
	int v[] = {1, 3, 5, 7, 8, 9, 12};
	printf("%d\n", rtbinsearch(4, v, 7));
	return 0;
}
