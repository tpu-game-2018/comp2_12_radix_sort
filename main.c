#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void print(int arr[], int n) {
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		if (c == 0)
		{
			printf("%d", arr[i]);
			c++;
		}
		else
		{
			printf(" %d", arr[i]);
		}
	}
	printf("\n");
}



int getMax(int arr[], int n) {
	int mx = arr[0];
	int i;
	for (i = 1; i < n; i++)
	{
		if (arr[i] > mx)
		{
			mx = arr[i];
		}

	}

	return mx;
}

void countSort(int arr[], int n, int exp) {
	int *output = (int *)malloc(sizeof(int) * n);
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}


	free(output);
}


void radixsort(int arr[], int n) {
	int m = getMax(arr, n);

	int exp;

	//1`100‚ÌŒ…‚Ü‚Å3‰ñ‚â‚é‚Ð‚Â‚æ‚¤‚ª‚ ‚éH
	//for (exp = 1; m / exp > 0; exp *= 10)
	//{
	//	countSort(arr, n, exp);
	//	print(arr, n);
	//}

	int i = 0;
	for (exp = 1, i = 0; i < 3; i++, exp *= 10)
	{
		countSort(arr, n, exp);
		print(arr, n);
	}
}

int main(int argc, char *argv[])
{
	char str[7];

	int tmp[100];
	int *p = tmp;

	int count = 0;
	while (fgets(str, sizeof(str), stdin))
	{
		int number = atoi(str);
		*p++ = number;
		count++;
	}

	int *data = (int *)malloc(sizeof(int) * count);
	memcpy(data, tmp, sizeof(int) * count);


	print(data, count);
	radixsort(data, count);

	free(data);

	return 0;
}