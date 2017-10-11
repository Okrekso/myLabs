void get(int arr[], int size)
{
	printf("first view of arr:");
	for (int i = 0; i < size; i++)
		printf("%d", arr[i]); printf("; ");

	printf("\n");
	int *newarray = (int*)malloc(size);
	for (int i = 0; i < size; i++)
	{
		newarray[i] = (i + 1) % 2 == 0 ? arr[i - 1] : i == size - 1 ? arr[i] : arr[i + 1];
	}
	printf("new array: ");
	for (int i = 0; i < size; i++)
		printf("%d", newarray[i]); printf("; ");
	printf("\n");
}

int main()
{
	int *arr, size;
	printf("insert array size: ");
	scanf("%d", &size);
	arr = (int*)malloc(size);

	for (int i = 0; i < size; i++)
	{
		printf("elem #"); printf("%d", i + 1); printf(": ");
		scanf("%d", &arr[i]);
		printf("\n");
	}
	get(arr, size);

	system("pause");
	return 0;
}