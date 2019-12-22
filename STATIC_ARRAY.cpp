#include "pch.h" //лабораторная работа 1. статический массив
#include <iostream>
using namespace std;
int main()
{ //array 1
	const int array1_r = 2;
	const int array1_c = 3;
	int array1[array1_r][array1_c];
	for (int row_index = 0; row_index < array1_r; row_index++)
	{
		for (int column_index = 0; column_index < array1_c; column_index++)
		{
			array1[row_index][column_index] = column_index + 1;

			cout << array1[row_index][column_index];
		}
		cout << "\n";
	}
	cout << "\n";
	//array 2
	const int array2_r = 3;
	const int array2_c = 2;
	int array2[array2_r][array2_c];
	for (int row_index2 = 0; row_index2 < array2_r; row_index2++)
	{
		for (int column_index2 = 0; column_index2 < array2_c; column_index2++)
		{
			array2[row_index2][column_index2] = row_index2 + 1;

			cout << array2[row_index2][column_index2];
		}
		cout << "\n";
	}
	cout << "\n";
	//array1*array2
	int array3[array1_r][array2_c];
	for (int row_index = 0; row_index < array1_r; row_index++)
	{
		for (int column_index = 0; column_index < array2_c; column_index++)
		{
			array3[row_index][column_index] = 0;
			for (int tmp = 0; tmp < array2_c; tmp++)
			{
				array3[row_index][column_index] = array1[row_index][tmp] * array2[tmp][column_index];

				cout << array3[row_index][column_index];
			}

		}
		cout << "\n";
	}
}
