#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Header.h"

using namespace std;

int* ArrayGeneration(int n)
{
	int* array = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
        array[i] = rand() % 1000;
    return array;
}

int* ArrayInput(int n)
{
	int* array = new int[n];
	for (int i = 0; i < n; i++)
		cin >> array[i];
	return array;
}

int exch = 0;
int comp = 0;

int BubleSort(int* array, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			comp++;
			if (array[j] > array[j + 1])
			{
				int a = array[j + 1];
				array[j + 1] = array[j];
				array[j] = a;
				exch++;
			}
		}
	return exch;
}

int compareBubleSort()
{
	return comp;
}

int exch1 = 0;
int comp1 = 0;

int CombSort(int* array, int n)
{
	double factor = 1.2473309; 
	int step = n - 1; 
	while (step >= 1)
	{
		for (int i = 0; i + step < n; i++)
		{
			comp1++;
			if (array[i] > array[i + step])
			{
				swap(array[i], array[i + step]);
				exch1++;
			}
		}
		step /= factor; 
	}
	return exch1;
}

int compareCombSort()
{
	return comp1;
}

void PrintArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
}

void file_input(int* D, int n)
{
	ofstream outfile("../array.txt");
	fstream file;
	file.open("../array.txt");

	for (int i = 0; i < n; i++)
	{
		file << D[i] << endl;
	}
	file.close();
}

int* file_output(int* D, int n)
{
	fstream file;
	file.open("../array.txt");

	for (int i = 0; i < n; i++)
	{
		file >> D[i];
	}
	file.close();

	return D;
}