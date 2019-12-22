// Лабораторная работа 4. Односвязный список
#include "pch.h"
#include <iostream>
#include <string>
#include "list.h"

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	list my_list_1;
	my_list_1.add("value 1");
	my_list_1.add("value 2");
	my_list_1.add("value 3");
	my_list_1.add("value 4");
	my_list_1.print();
	my_list_1.find_print(0); 
	my_list_1.remove(0);
	std::cout << "after removing:\n";
	my_list_1.print();
	my_list_1.add_index(0, "value 5"); 
	my_list_1.print();
	my_list_1.remove_all();
	my_list_1.print();
	return 0;
}

