#include <iostream>

using namespace std;

//элемент односвязного списка - структура из данных и адреса в памяти
struct subforwardlist {

	int data;
	subforwardlist* next;

};

//инициализация пустого недосписка
bool init(subforwardlist** sfl) {

	*sfl = new subforwardlist;

	(*sfl)->data = 0;
	(*sfl)->next = NULL;

	return true;
}
//добавление элемента в конец недосписка
bool push_back(subforwardlist** sfl, int d) {
	
	if ((*sfl)->next == NULL)
	{
		*sfl = new subforwardlist;
		(*sfl)->data = d;
	}
	else
	{
		subforwardlist* temp = (*sfl)->next; //создали временный указатель
		while (temp->next != NULL)
		{
			temp = temp->next; //в temp  присваиваем указатель на следующий элемент
		}
		temp->next = new subforwardlist;//инициализируем значение по адресу - d
		temp->data = d;

	}

	

	return true;
}

int main()
{
	subforwardlist *sfl;

	cout << init(&sfl);

 
	cout << push_back(&sfl, 3);
	return 0;
}

