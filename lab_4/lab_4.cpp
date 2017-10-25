#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int**fill_matrix(int size)
{
	int**matrix = (int**)malloc(sizeof(int)*size*size);
	for (int i = 0; i < size; i++)
		matrix[i] = (int*)malloc(sizeof(int)*size);

	printf_s("random matrix generated:\n");

	for (int i = 0; i < size; i++)
	{
		for (int d = 0; d < size; d++)
		{
			//matrix[i][d] = 1;
			matrix[i][d] = rand() % 20;
			printf_s(" %d |", matrix[i][d]);
		}
		printf_s("\n");
	}

	return matrix;
}

int getMaxElement()
{
	int i=1;
	int size=i;
	

	while (true)
	{
		try
		{
			printf_s("%d) try to create matrix: %d\n",i, size);
			i++;
			size = i;
			int**matrix = (int**)malloc(sizeof(int)*size*size);
			for (int i = 0; i < size; i++)
				matrix[i] = (int*)malloc(sizeof(int)*size);

			free(matrix);
		}
		catch(int ex)
		{
			printf_s("the max size of matrix: %d", size);
			break;
		}
	}
}

int read_matrix(int**matrix,int size)
{

	int count=0;
	for (int i = 0; i < size; i++)
	{
		for (int d = 0; d < size; d++)
		{
			if (matrix[i][d] > 9) count++;
			//count += matrix[i][d] > 9 ? 1 : 0;
		}
	}
	return count;
}

int main()
{

	printf_s("insert matrix size\n>");
	int size;
	scanf_s("%d", &size);

	int **matrix = fill_matrix(size);
	int result = read_matrix(matrix, size);
	printf_s("\nresult:%d\n",result);
	system("pause");
		
}