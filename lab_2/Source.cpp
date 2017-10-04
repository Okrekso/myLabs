#include <iostream>
using namespace std;
void get(int arr[], int size)
{
	printf("first view of arr:");
	for (int i = 0; i < size; i++)
		printf("%d", arr[i]); printf("; ");
	
	printf("\n");
    int *newarray = new int[size];
	for (int i = 0; i < size; i++)
	{
		newarray[i] = (i + 1) % 2 == 0 ? arr[i - 1] : i == size - 1 ? arr[i] : arr[i + 1];
	}
	printf("new array: ");
	for (int i = 0; i < size; i++)
		printf("%d",newarray[i]); printf("; ");
	printf("\n");
}

int main()
{
	int *arr,size;
	printf("insert array size: ");
	scanf_s("%d",&size);
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		printf("elem #"); printf("%d", i+1); printf(": ");
		scanf_s("%d",&arr[i]);
		printf("\n");
	}	
	get(arr, size);
	
	system("pause");
	return 0;
}