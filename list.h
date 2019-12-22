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

	list_elem * find_index(list_elem * start_from, int index);	//�������� �������� �������� ��� ������ index

public:

	list();
	
	void add(std::string new_data);//�������� � ������ ������
	
	void add_index(int index, std::string new_data);//�������� � ������ � ����� ��� �������� index
	
	bool remove(int index);//������� ������� ��� �������� index

	bool remove_all();// ������� ��� �������� ������
	
	std::string find_print(int index);// �������� �������� �������� ��� ������ index � �����
	
	void print();// ����� ������
};
