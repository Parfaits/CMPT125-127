#include <stdio.h>


int rBinarySearch(int arr[], int len, int target)
{
	int firsthalf, secondhalf;
	if(len <= 0) return 0;
	int mid = len/2;
	if(target == arr[mid]) return 1;
	firsthalf = rBinarySearch(arr, mid, target);
	secondhalf = rBinarySearch(arr+mid+1, len-mid-1, target);
	return firsthalf+secondhalf;
}


int main()
{
	//int a[5] = {-1, 2, 3, 4, 21};
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int found = rBinarySearch(a, 10, 7);
	printf("%i\n", found);
	return 0;
}
