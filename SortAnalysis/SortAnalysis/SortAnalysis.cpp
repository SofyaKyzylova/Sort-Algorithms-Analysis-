// SortAnalysis.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int n;
	int* array;
	cout << " Введите количество элементов в массиве 1: ";
	cin >> n;

	//cout << " Введите элементы массива 1:" << endl;
	//array = ArrayInput(n);

	cout << " Сгенерированный массив 1:" << endl;
	array = ArrayGeneration(n);
	file_input(array, n);
	PrintArray(array, n);
	cout << endl;
	
	cout << " Сортировка пузырьком:" << endl;
	clock_t start1 = clock();
	BubleSort(array, n);
	clock_t end1 = clock();
	PrintArray(array, n);
	cout << endl;
	cout << " Время выполнения сортировки пузырьком в секундах = " << (float)(end1 - start1) / CLOCKS_PER_SEC << endl;
	cout << " Количество обменов = "  << BubleSort(array, n) << endl;
	cout << " Количество сравнений = " << compareBubleSort() << endl;
	cout << endl << endl << "-----------------------------------------------------------------------------------------" << endl << endl << endl;

	int* arr;

	//cout << " Введите элементы массива 2:" << endl;
	//arr = ArrayInput(m);
	arr = file_output(array, n);

	cout << " Сгенерированный массив 2:" << endl;
	//arr = ArrayGeneration(m);
	PrintArray(arr, n);
	cout << endl;

	cout << " Сортировка расческой:" << endl;
	clock_t start2 = clock();
	CombSort(arr, n);
	clock_t end2 = clock();
	PrintArray(arr, n);
	cout << endl;
	cout << " Время выполнения сортировки расческой в секундах = " << (float)(end2 - start2) / CLOCKS_PER_SEC << endl;
	cout << " Количество обменов = " << CombSort(arr, n) << endl;
	cout << " Количество сравнений = " << compareCombSort() << endl;
	cout << endl;
}