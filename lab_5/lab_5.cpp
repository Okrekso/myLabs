#include <iostream>
#include <stdio.h>
#include<string.h>
#include <fstream>
using namespace std;


struct city
{
	char name[100];
	int population;
	int size;
	int gustota;
};
city generateCity(int size)
{
	city d;
	char name1[50]; char name2[50];
	int r = rand() % 5;
	switch (r)
	{
	case(1): strcpy_s(name1, "Holy"); break;
	case(2): strcpy_s(name1, "Big"); break;
	case(3): strcpy_s(name1, "High"); break;
	case(4): strcpy_s(name1, "Width"); break;
	case(5): strcpy_s(name1, "Salty"); break;
	}
	r = rand() % 5;
	switch (r)
	{
	case(1): strcpy_s(name1, " Springs"); break;
	case(2): strcpy_s(name1, " Rivers"); break;
	case(3): strcpy_s(name1, " Fields"); break;
	case(4): strcpy_s(name1, " Views"); break;
	case(5): strcpy_s(name1, " Sides"); break;
	}
	strcpy_s(d.name, name1);
	d.population = rand() % 1000000 + 800;
	d.size = rand() % 800 + 20;
	d.gustota = d.size / d.population;
	return d;
}

void sort(int size, city arr[])
{
	for (int i = 0; i < size; i++)
	{
		for (int d = 0; d < size; d++)
		{
			if (d != size - 1 && arr[d].gustota < arr[d + 1].gustota)
			{
				city temp = arr[d];
				arr[d] = arr[d + 1];
				arr[d + 1] = temp;
			}
		}
	}
}

city* getCities(city* arr)
{
	FILE *stream;
	
	int cities=0;
	if (fopen_s(&stream, "infos.txt", "r+") == 0)
	{
		while(true)
		{
			char name[100];
			int i = 0; char temp = 'a';
			int e;
			while (temp != ':')
			{
				e=fscanf_s(stream, "%c", &temp);
				if (e == -1) { break; }
				//printf_s("element%d:%d\n", i,e);
				name[i] = temp;
				i++;
			}
			if (e == -1) break;
			name[i-1] = '\0';

			int size; fscanf_s(stream, "%d", &size); fscanf_s(stream, "%c"); int pop; fscanf_s(stream, "%d", &pop);
			fscanf_s(stream, "%c");
			
			city cityTEMP; strcpy_s(cityTEMP.name, name);  cityTEMP.population = pop; cityTEMP.size = size;
			cityTEMP.gustota = cityTEMP.size / cityTEMP.population;
			city*tmp = arr;
			cities++;
			arr = (city*)malloc(sizeof(city)*cities);
			for (int k = 0; k < cities - 1; k++) arr[k] = tmp[k];
			arr[cities-1] = cityTEMP;

		}
		fclose(stream);
		return arr;
	}
	else printf_s("ERROR WHILE OPEN SAVE FILE!");
	return 0;
}
int getCitiesCount(city* arr)
{
	FILE *stream;

	int cities = 0;
	if (fopen_s(&stream, "infos.txt", "r+") == 0)
	{
		while (true)
		{
			char name[100];
			int i = 0; char temp = 'a';
			int e;
			while (temp != ':')
			{
				e = fscanf_s(stream, "%c", &temp);
				if (e == -1) { break; }
				//printf_s("element%d:%d\n", i,e);
				name[i] = temp;
				i++;
			}
			if (e == -1) break;
			name[i - 1] = '\0';

			int size; fscanf_s(stream, "%d", &size); fscanf_s(stream, "%c"); int pop; fscanf_s(stream, "%d", &pop);
			fscanf_s(stream, "%c");

			city cityTEMP; strcpy_s(cityTEMP.name, name);  cityTEMP.population = pop; cityTEMP.size = size;

			city*tmp = arr;
			cities++;
			arr = (city*)malloc(sizeof(city)*cities);
			for (int k = 0; k < cities - 1; k++) arr[k] = tmp[k];
			arr[cities - 1] = cityTEMP;

		}
		fclose(stream);
		return cities;
	}
	else printf_s("ERROR WHILE OPEN SAVE FILE!");
	return 0;
}
int main()
{
	city* cities;
	cities = (city*)malloc(sizeof(city));
	cities = getCities(cities);
	int count = getCitiesCount(cities);
	for (int i = 0; i < count; i++)
	{
		//cities[i] = generateCity(1);
		cout << "============\n";
		sort(count, cities);
		cout << "city:" << cities[i].name << "\npop:" << cities[i].population << "\nsize:" << cities[i].size << "\ngustota:"<<cities[i].gustota;
		cout << "==========\n";
	}
	system("pause");
	return 0;
}