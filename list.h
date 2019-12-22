#pragma once
#include <string>
using namespace std;
class list_elem
{
public:

	std::string data;

	list_elem * next;

	list_elem();

	list_elem(std::string new_data);

	list_elem(std::string new_data, list_elem * new_next);
};
class list {

	list_elem * head;

	int count;

	list_elem * find_index(list_elem * start_from, int index);	//получить значение элемента под индекс index

public:

	list();
	
	void add(std::string new_data);//добавить в начало списка
	
	void add_index(int index, std::string new_data);//добавить в список в место под индексом index
	
	bool remove(int index);//удалить элемент под индексом index

	bool remove_all();// удалить все элементы списка
	
	std::string find_print(int index);// получить значение элемента под индекс index и вывод
	
	void print();// вывод списка
};
