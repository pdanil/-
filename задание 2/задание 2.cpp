// задание 2.cpp 
//Написать программу, которая преобразует одномерный массив(1D) в двумерный(2D)
//(или наоборот), в соответствии с вариантом. Необходимо оформить в отдельных
//функциях код следующих действий : 1) инициализация массива; 2) вывод массива; 3)
//преобразование массива(создание нового массива с другой структурой).Память под
//массивы выделять динамически и для доступа к элементам использовать указатели.
//Ввод - вывод данных организовать средствами iostream и iomanip

//Преобразование: 1D → 2D.Одномерный массив из 25 вещественных чисел необходимо
//разложить по двумерной сетке 5х5 слева направо и сверху вниз, но первый элемент на
//каждой строке должен содержать сумму остальных четырех.
//Инициализация : заполнить массив числами x[n] = n ∙ sin(πn / 25), n – индекс элемента.
//Вывод на экран : на каждый элемент массива отвести 10 позиций.

#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.14159265 
using namespace std;

void initArray(double* arr, size_t LENGTH) {
	for (size_t i = 0; i < LENGTH; i++) {
		*(arr + i) = i * sin((PI * i) / 25);
	}
}

void printArray1D(double* arr1D, size_t LENGTH) {
	for (size_t i = 1; i < LENGTH; i++) {
		cout << *(arr1D + i) << setw(10);
	}
	cout << "\n\n";
}

void printArray2D(double** arr2D, size_t N, size_t M) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			cout << arr2D[i][j] << setw(10);
		}
		cout << "\n";
	}
	cout << "\n";
}

double** makeArray2D(double* arr1D, size_t rows, size_t cols) {
	double** arr2D = new double* [rows];
	int cnt = 0;

	for (size_t i = 0; i < rows; i++) {
		arr2D[i] = new double[cols];
	}


	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			arr2D[i][j] = arr1D[cnt++];
		}
	}

	double sum;
	for (size_t i = 0; i < rows; ++i) {

		*(*(arr2D + i) + 0) = 0;
		sum = *(*(arr2D + i) + 0);

		for (size_t j = 0; j < cols; ++j) {
			sum += *(*(arr2D + i) + j);
		}

		*(*(arr2D + i) + 0) = sum;
	}

	return arr2D;
}

void freeArray1D(double* arr) {
	delete[] arr;
}

void freeArray2D(double** arr, size_t N) {
	for (size_t i = 0; i < N; ++i) {
		delete[] * (arr + i);
	}
	delete[] arr;
}

int main() {
	const size_t LENGTH = 25;
	const size_t N = 5;
	const size_t M = 5;
	double* arr1D = new double[LENGTH];

	setlocale(LC_ALL, "Russian");

	initArray(arr1D, LENGTH);
	cout << "Одномерный массив: \n" << endl;
	printArray1D(arr1D, LENGTH);


	double** arr2D = makeArray2D(arr1D, N, M);
	cout << "Двумерный массив, где 1 элемент каждой строки - сумма последующих элементов этой строки: \n" << endl;
	printArray2D(arr2D, N, M);


	freeArray1D(arr1D);
	freeArray2D(arr2D, N);


	system("pause");
	return 0;
}