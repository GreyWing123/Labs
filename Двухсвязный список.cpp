#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <math.h>

using namespace std;
class list_elem
{
public:

	std::string data;

	list_elem * next;

	list_elem * prev;

	list_elem();

	list_elem(std::string new_data);

	list_elem(std::string new_data, list_elem * new_next, list_elem * new_prev);
};
class list {

	list_elem * head;
	list_elem * tail;
	int count;
	list_elem * find_index(list_elem * start_from, int index);	//поиск индекса

public:

	list();

	void add_head(std::string new_data);//добавить в начало списка

	void add_index(int index, std::string new_data);//добавить в список в место под индексом index

	bool remove(int index);//удалить элемент под индексом index

	bool remove_all();// удалить все элементы списка

	std::string find_print(int index);// получить значение элемента под индекс index и вывод

	void print();// вывести список в консоли
};

list_elem::list_elem()
{
	data = "";
	next = nullptr;
	prev = nullptr;
}

list_elem::list_elem(std::string new_data)
{
	data = new_data;
	next = nullptr;
	prev = nullptr;
}

list_elem::list_elem(std::string new_data, list_elem * new_next, list_elem * new_prev)
{
	data = new_data;
	next = new_next;
	prev = new_prev;
}

list::list() {
	head = nullptr;
	tail = nullptr;
	this->count = 0;
}


list_elem * list::find_index(list_elem * start_from, int index)
{
	if (index < 0) {
		return nullptr;
	}
	int current_index = 0;
	list_elem* iterator = start_from;
	while (iterator != nullptr)
	{
		if (current_index >= index) {
			break;
		}
		current_index++;
		iterator = iterator->next;
	}
	return iterator;
}


void list::add_head(std::string new_data) { //заполнение с начала
	list_elem * new_elem;
	if (head == nullptr &&tail == nullptr) {
		new_elem = new list_elem(new_data, nullptr, nullptr);
		new_elem->next;
		new_elem->prev = nullptr;
		tail = new_elem;
	}
	else {
		new_elem = new list_elem(new_data, head, nullptr);
	}
	head = new_elem;
	this->count++;
}

void list::add_index(int index, std::string new_data) {

	if (index < 0) {
		std::cout << "Индекс отрицательный. Функция add_index не работает\n ";
		return;
	}
	if (index > this->count) {
		std::cout << "индекс больше длины списка. функция add_index не работает\n";
		return;
	}
	if ((head == nullptr) and (index == 0)) {
		list_elem * new_elem = new list_elem(new_data);
		head = new_elem;
		tail = new_elem;
		new_elem->next = new_elem->next;
	}
	else if (index == 0) {
		list_elem * new_elem = new list_elem(new_data, head, tail);
		//auto parent_elem = find_index(head, 0);
		head = new_elem;
		//new_elem->next = new_elem->next;
	}
	if ((index < this->count) and (index != 0)) {
		list_elem * new_elem = new list_elem(new_data);
		auto parent_elem = find_index(head, index - 1);
		new_elem->next = parent_elem->next;
		parent_elem->next = new_elem;
	}
	this->count++;
	return;
}

bool list::remove(int index)
{
	if (index < 0) {
		std::cout << "Индекс отрицательный. Функция remove не работает\n ";
		return false;
	}
	if (index >= this->count) {
		std::cout << "индекс больше размера массива. функция remove не работает\n";
		return false;
	}

	list_elem * parent = head;
	if ((index >= 0) and (index >= this->count)) {
		return false;
	}
	if (index == 0) {
		head = head->next;
		delete parent;

	}
	else {
		int counter = 0;
		while (parent != nullptr)
		{
			if (counter == index - 1) {
				list_elem * removed_elem = parent->next;
				parent->next = parent->next->next;
				removed_elem->next->prev = parent;
				delete removed_elem;
				return true;
			}
			counter++;
			parent = parent->next;
		}
	}
	this->count--;
	return true;
}

bool list::remove_all() {
	while (head != nullptr)
	{
		list_elem * iterator = head;                  // создаем временный элемент
		head = head->next;                  // присваиваем ему указатель на следующий
		delete iterator;                        // и удаляем его
	}
	head = nullptr;
	return true;
}
std::string list::find_print(int index) {
	if (index < 0) {
		std::cout << "Индекс отрицательный. Функция find_print не работает\n ";
		return"";
	}
	if (index > this->count) {
		std::cout << "индекс больше длины списка. функция find_print не работает\n";
		return"";
	}
	if (index < this->count / 2)
	{
		int counter = 0;
		list_elem* iterator = this->head;
		while (iterator != nullptr)
		{
			if (counter == index) {
				std::cout << iterator->data << "\n\n";
				return iterator->data;
				break;
			}
			counter++;
			iterator = iterator->next;
		}
	}
	else {
		int counter = this->count - 1;
		auto iterator = find_index(head, index - 1);
		std::cout << iterator->data << "\n\n";
		/*list_elem * iterator = this->tail;

		while (iterator != nullptr)
		{
			if (counter == index) {
				std::cout << iterator->data << "\n\n";
				return iterator->data;
				break;
			}
			counter--;
			iterator = iterator->prev;
		}*/
	}
	return "";
}

void list::print()
{
	list_elem * iterator = head;
	if (iterator == nullptr) cout << "Cписок пуст";
	else {

		std::cout << "\nЭлементы списка : ";
		do
		{
			std::cout << iterator->data << " ";
			iterator = iterator->next;
		} while (iterator != nullptr);
	}
	std::cout << "\n\n";
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	list my_list_1;
	my_list_1.add_head("value 1");
	my_list_1.add_head("value 2");
	my_list_1.add_head("value 3");
	my_list_1.add_head("value 4");
	my_list_1.add_head("value 5");
	my_list_1.add_head("value 6");
	my_list_1.print();
	my_list_1.find_print(7);
	my_list_1.remove(3);
	my_list_1.print();
	my_list_1.add_index(0, "value 10");
	my_list_1.print();
	my_list_1.remove_all();
	my_list_1.print();
	return 0;
}