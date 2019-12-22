#include "pch.h"
#include "list.h"
#include <ostream>
#include <iostream>
#include <math.h>
using namespace std;
list_elem::list_elem()
{
	data = "";
	next = nullptr;
}
list_elem::list_elem(std::string new_data)
{
	data = new_data;
	next = nullptr;
}
list_elem::list_elem(std::string new_data, list_elem * new_next)
{
	data = new_data;
	next = new_next;
}
list::list() {
	list_elem * head;
}
void list::add(std::string new_data) {
	list_elem * new_elem = new list_elem(new_data, head);
	head = new_elem;
	this->count++;
}
void list::add_index(int index, std::string new_data) {
	
	if (index < 0) {
		std::cout << "индекс отрицательный. функци€ add_index не работает\n";
		return ;
	}
	if ((head == nullptr) and (index <= 0)) {
		list_elem * new_elem = new list_elem(new_data);

		head = new_elem;

		new_elem->next = new_elem->next;
	}
	 
	else if (index == 0) {
		
		list_elem * new_elem = new list_elem(new_data, head);
		auto parent_elem = find_index(head, 0);
		head = new_elem;
		new_elem->next = parent_elem;
		
		
	}
		if ((index <= this->count) and(index!=0)) {
		list_elem * new_elem = new list_elem(new_data);
		auto parent_elem = find_index(head, index - 1);
		new_elem->next = parent_elem->next;
		parent_elem->next = new_elem;
	}
	
	return ;

}


list_elem * list::find_index(list_elem * start_from, int index)
{
	if (index < 0) {
		return nullptr;
	}
	int current_index = 0;            //счетчик
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
bool list::remove(int index) 
{ list_elem * parent = head;  // создаем временный элемент(родитель)
    if (index == 0) {
		list_elem * removed_elem = parent;  // создаем элемент, который будет удален
		head = removed_elem->next;
		delete removed_elem;         // и удал€ем его
      }
    else {
	int counter=0;            //счетчик
	while (parent != nullptr)
	{
		if (counter == index - 1) {
			list_elem * removed_elem = parent->next;  // создаем элемент, который будет удален
			parent->next = parent->next->next;
			delete removed_elem;         // и удал€ем его
			break;                       //выход из цикла
		}
		counter++;
		parent = parent->next;        // присваиваем родителю указатель на следующий
      }
    }
	return true;
}
bool list::remove_all() {
	while (head != nullptr)                    
	{
		list_elem * iterator = head;                  // создаем временный элемент
		head = head->next;                  // присваиваем ему указатель на следующий
		delete iterator;                        // и удал€ем его
	}
	head = nullptr;
	return true;
}
std::string list::find_print(int index)
{   if (index < 0) 
{
	std::cout << "индекс отрицательный. функци€ find_print не работает\n";
	return "";

	}
	int counter = 0;                       //счетчик
	list_elem* iterator = head;      // создаем временный элемент
	while (iterator != nullptr)
	{
		if (counter >= index) {
			std::cout << iterator->data << "\n\n";  //вывод значение элемента под индекс index
			break;                           //выход из цикла
		}
		counter++;    
		iterator = iterator->next;      // присваиваем ему указатель на следующий
	}
	return "";
}
void list::print()
{   list_elem * iterator = head;        // создаем временный элемент
	if (iterator == nullptr) cout << "Cписок пуст";
	else {
		
		std::cout << "\nЁлементы списка : ";
		do
		{
			std::cout << iterator->data << " "; //вывод
			iterator = iterator->next;       // присваиваем ему указатель на следующий

		} while (iterator != nullptr);
	}
		std::cout << "\n\n";
}
