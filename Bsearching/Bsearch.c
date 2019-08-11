#include <stdio.h>

int BinarySearch(int arr[], int len, int target)
{
	int first = 0;
	int last = len-1;
	while(first <= last)
	{
		int mid = first + ((last - first)/2);
		if(arr[mid] > target)
		{
			last = mid-1;
		} else
		{
			first = mid+1;
		}
	}
	if(arr[first-1] == target)
	{
		return 1;
	}
	return 0;
}


int main()
{
	//int a[5] = {-1, 2, 3, 4, 21};
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int found = BinarySearch(a, 10, 7);
	printf("%i\n", found);
	return 0;
}
