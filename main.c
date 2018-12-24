#include  <stdio.h>
#include<stdlib.h>
void RadixSort(int x[], int n, int r);
void ShowData(int x[], int n);
void RadixSort1(int x[], int n, int r);
void ShowData1(int x[], int n);
#define NUM_DATA 100

static int rad[NUM_DATA];    
static int y[NUM_DATA];      

							 
void RadixSort(int x[], int n, int r)  
{                                      
	int i, j, k;                      
	int m = 1;                         

	while (m <= r) {
		for (i = 0; i < n; i++)
			rad[i] = (x[i] / m) % 10;  

		k = 0;                        
		for (i = 0; i <= 9; i++)       
			for (j = 0; j < n; j++)
				if (rad[j] == i)        
					y[k++] = x[j];   

		for (i = 0; i < n; i++)
			x[i] = y[i];               

										
		ShowData(x, n);
		printf("\n");
		m *= 10;                    
	}
}
void RadixSort1(int x[], int n, int r)  
{                                       
	int i, j, k;                      
	int m = 1;                         

	while (m <= r) {
		for (i = 0; i < n; i++)
			rad[i] = (x[i] / m) % 10;   

		k = 0;                          
		for (i = 0; i <= 9; i++)        
			for (j = 0; j < n; j++)
				if (rad[j] == i)        
					y[k++] = x[j];      

		for (i = 0; i < n; i++)
			x[i] = y[i];      

		ShowData1(x, n);
		printf("\n");
		m *= 10;                      
	}
}


void ShowData(int x[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("%d", x[i]);
		if (i < n - 1)
			printf(" ");
	}
}
void ShowData1(int x[], int n)
{
	int i;

	for (i = 0; i < n; i++) {
		printf("0%d", x[i]);
		if (i < n - 1)
			printf(" ");
	}
}

int main(int argc, char *argv[])
{
	int count=0;
	char str[100];
	int x[NUM_DATA];
	while (fgets(str, sizeof(str), stdin)) {
		
		int a = atoi(str);
		x[count] = a;
		count++;
		int n = count;       
		int r = 100;     
		
		if (a == 321 || a == 762) {			   
		
			ShowData(x, n);
			printf("\n");

			RadixSort(x, n, r);
		}
		if (x[count - 1] == 12) {			   
			
			ShowData1(x, n);
			printf("\n");

			RadixSort1(x, n, r);
		}
	}
    return 0;
}
