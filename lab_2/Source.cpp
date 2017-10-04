#include <iostream>
using namespace std;
void get(int arr[], int size)
{
	cout << "first view of arr:";
	for (int i = 0; i < size; i++)
		cout << arr[i] << "; ";
	
	cout << endl;
    int *newarray = new int[size];
	for (int i = 0; i < size; i++)
	{
		newarray[i] = (i + 1) % 2 == 0 ? arr[i - 1] : i == size - 1 ? arr[i] : arr[i + 1];
	}
	cout << "new array: ";
	for (int i = 0; i < size; i++)
		cout << newarray[i] << "; ";
	cout << endl;
}

int main()
{
	int *arr,size;
	cout << "insert array size: ";
	cin >> size;
	arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "elem #" << i + 1 << ": ";
		cin >> arr[i];
		cout << endl;
	}	
	get(arr, size);
	
	system("pause");
	return 0;
}