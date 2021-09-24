// задание 3
//Написать свой аналог стандартной функции обработки строк из файла cstring, 
//в соответствии с вариантом.В функции main на тестовых данных продемонстрировать 
//результат работы как стандартной функции, так и собственной версии.
//Ввод - вывод данных организовать средствами cstdio.

//Функция strrchr.Формат char* strrchr(char* s, int c).
//Функция находит в строке s последнее вхождение символа с 
//и возвращает подстроку, начинающуюся с этого символа.

#include <cstdio>
#include <cstdlib> 
#include <stdlib.h> 
#include <string>
#define _CRT_SECURE_NO_WARNINGS  // для scanf

char* firstChar(char* s, int c) {

	size_t len = 0; // начальный инд
	char* first_of_string = NULL;  
	
	while (s[len] != '\0')
	{
		if (s[len] == c) {
			first_of_string = s + len; 
			break;
		}
		len++;
	}	
	return first_of_string;
}

int main() {

	char symbol = '.';
	
	char s[] = "www.your_address.and_something_wrong.com";
	
	char* standard_result = strchr(s, symbol);

	char* my_result = firstChar(s, symbol);
	
	printf("Initial string: %s\n\nStandard: %s\n\nMy version: %s\n\n", s, standard_result, my_result);

	system("pause");
	return 0;
}