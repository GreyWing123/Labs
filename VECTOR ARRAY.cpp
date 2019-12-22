// умножение векторных массивов, ввод результата умножения в файл name.txt и вывод оттуда
#include "pch.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
int main(void)
{

	const int row_left = 2;
	const int col_left = 3;

	vector<vector<int> > tab_left(row_left);

	for (int i = 0; i < row_left; i++) {

		tab_left[i].resize(col_left);

		for (int j = 0; j < col_left; j++) {

			tab_left[i][j] = j + 1;

			cout << tab_left[i][j] << " ";
		}
		cout << '\n';
	}
	cout << endl;
	system("pause");

	const int row_right = 3;
	const int col_right = 2;

	vector<vector<int> > tab_right(row_right);

	for (int i = 0; i < row_right; i++) {

		tab_right[i].resize(col_right);

		for (int j = 0; j < col_right; j++) {

			tab_right[i][j] = i + 1;

			cout << tab_right[i][j] << " ";
		}
		cout << '\n';
	}
	cout << endl;
	system("pause");

	ofstream fout;

	fout.open("name.txt");

	const int row_result = row_left;

	const int col_result = col_right;

	vector<vector<int> > tab_result(row_result);

	for (int row_index = 0; row_index < row_result; row_index++) {

		tab_result[row_index].resize(col_result);

		for (int col_index = 0; col_index < col_result; col_index++) {

			tab_result[row_index][col_index] = 0;

			for (int tmp = 0; tmp < col_left; tmp++) {

				tab_result[row_index][col_index] += tab_left[row_index][tmp] * tab_right[tmp][col_index];
			}

			fout << tab_result[row_index][col_index] << " ";
		}
		cout << '\n';
	}
	cout << endl;

	fout.close();

	cout << "tab_result\n";

	char str[30];

	ifstream out;

	out.open("name.txt");

	out.getline(str, 30);

	cout << str << endl;

	out.close();

	system("pause");

	return 0;
}
