//Лабораторная работа 3. Функция с указателем
#include "pch.h"
#include <iostream>

using namespace std;

void printArray(int pointerArray[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << pointerArray[i]<< " " ;
	}

}
void main()
{
	int array[5] = { 1, 2, 3, 4, 5 };

	int *pointerArray = array;

	printArray(pointerArray);

}


