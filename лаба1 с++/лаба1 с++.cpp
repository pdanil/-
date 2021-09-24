// задание 1
//// Написать программу обработки одномерного массива с n элементами, в соответствии с 
//вариантом(приложение А).Необходимые действия должны производиться в
//функции processArray(), возвращающей определенное значение и формирующей
//еще один(выходной) массив данных(см.свой вариант).Память под массивы
//выделять статически(объявлять массивы локально в функции main) и для доступа к
//элементам использовать индексы.Ввод - вывод данных организовать средствами cstdio.

//var1
//Объявить массив из n=15 вещественных чисел, проинициализировать единицами. 
//Функция processArray() должна домножить все элементы с четными индексами на
//случайное число из диапазона[a, b](a и b ввести с клавиатуры, a < 0), подсчитать и
//вернуть количество отрицательных элементов массива и сформировать выходной
//массив, содержащий только отрицательные элементы входного(т.е.размерность
//уменьшится).Вывести на экран результирующие массивы.

#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <stdlib.h> 
#define _CRT_SECURE_NO_WARNINGS  // для возможности использования scanf

size_t processArray(double arr[], double newArr[], size_t n, int min, int max) {
	for (size_t i = 0; i < n; i += 2) {
		arr[i] = (rand() % (max - min + 1)) + min;
	}

	size_t numOfNegativeNums = 0;

	for (size_t i = 0; i < n; ++i) {
		if (arr[i] < 0) {
			numOfNegativeNums++;
		}

	}

	for (size_t j = 0; j < numOfNegativeNums; ++j) {
		for (size_t i = 0; i < n; ++i) {
			if (arr[i] < 0) {
				newArr[j] = arr[i];
				j++;
			}
		}
	}

	return numOfNegativeNums;
}

void printArray(double arr[], size_t n) {
	for (size_t i = 0; i < n; ++i) {
		printf("%3.2f  ", arr[i]);
	}
	printf("\n");
}

int main()
{

	const size_t N = 15;
	double arr[N];
	size_t result;
	double newArr[N];

	for (size_t i = 0; i < N; i++) {
		arr[i] = 1.0;
	}

	int a, b;

	system("chcp 1251"); // переходим в консоли на русский язык
	system("cls");

	printf("Введите диапазон(a и b) для случайных чисел-множителей через ENTER: \n");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	printf("\n\n");

	result = processArray(arr, newArr, N, a, b);

	printf("Массив с случайными множителями для чётных индексов: \n");
	printArray(arr, N);
	printf("\n\n");
	
	printf("Массив, отобранными отрицательными элементами: \n");
	printArray(newArr, result);
	printf("\n\n");
	
	printf("Кол-во отрицательных элементов массива: ");
	printf("%d\n", result);
	printf("\n\n");


	system("pause");
	return 0;
}