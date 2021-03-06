#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include<string.h>
#include <fstream>
#include<ctime> 

struct List
{
	int value=0;
	List* Next;

	void setNext(int value)
	{
		Next->value = value;
	}

	void show()
	{
		printf("| %d |", value);
		if (Next != NULL) { Next->show(); };
	}

	void insertNext(int newVal, List* parent, int &parentSize)
	{
		List New; New.Next = this->Next; New.value = newVal;
		parent[parentSize] = New;
		this->Next = &parent[parentSize]; parentSize++;
	}

	static List* get(int size)
	{
		List*arr=(List*)malloc(sizeof(List)*size);
		for (int i = 0; i < size; i++)
		{
			arr[i].Next = i == size - 1 ? NULL : &arr[i + 1];
		}
		return arr;
	}
};
int getSize(List*arr)
{
	int i = 0;
	while (arr[i].Next != NULL)
	{
		i++;
	}
	i++;
	return i;
}
void fillRand(List*arr)
{
	srand(time(NULL));
	for (int i = 0; i < getSize(arr); i++)
	{
		arr[i].value = rand() % 10;
	}
}
int getMaxNum(List* arr)
{
	int maxNum = 0; int max = arr[maxNum].value;
	for (int i = 0; i < getSize(arr); i++)
	{
		if (arr[i].value > max) { max = arr[i].value; maxNum = i; }
	}
	return maxNum;
}

int main()
{
	int size=10;
	List* mass=List::get(size);
	fillRand(mass);

	mass[0].show();

	printf("\nmax:%d\n", getMaxNum(mass));
	mass[getMaxNum(mass)].insertNext(100,mass,size);

	mass[0].show();

	scanf("%d");
    return 0;
}

