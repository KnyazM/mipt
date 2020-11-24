#include <iostream>

using namespace std;

//элемент односвязного списка - структура из данных и адреса в памяти
struct subforwardlist 
{
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

////определить размер недосписка
//unsigned int size(subforwardlist** sfl) {
//
//
//	if ((*sfl)->next == NULL)
//		return 0; //?
//	subforwardlist* temp = (*sfl)->next;
//	unsigned int size = 0;
//	while (temp->next != NULL)
//	{
//		temp = temp->next; //в temp  присваиваем указатель на следующий элемент
//		size++;
//	}
//	delete temp;
//	return size;
//}

int where(subforwardlist** sfl, int index) {

	int position = 0;
	subforwardlist* temp = *sfl;
	while (temp != NULL)
	{
		if (position == index)
		{
			return temp->data;
		}
		else
		{
			temp = temp->next;
			position++;
		}
	}
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
		temp->next = new subforwardlist;
		temp->data = d;
		//temp->next->next = NULL; ??
		
	}
	//size??

	return true;
}

//удаление элемента с конца недоcписка

int pop_back(subforwardlist** sfl) {

		subforwardlist* temp = (*sfl)->next;

		while (temp->next != NULL);
		{
			temp = temp->next;
		}
		subforwardlist* last = temp->next;
		int l = last->data;
		temp->next = last->next;
		delete last;
		//size??

		return l;
}

//добавление элемента в начало недосписка
bool push_forward (subforwardlist** sfl, int d){


	if ((*sfl)->next == NULL)
	{
		*sfl = new subforwardlist;
		(*sfl)->data = d;
	}

	else
	{
		subforwardlist* temp = new subforwardlist;
		temp->data = d;
		temp->next = *sfl;
		*sfl = temp;
	}

	return true;
}

//для pop_forward и clear
//удаление первого элемента списка
void pop_front(subforwardlist** sfl){

	subforwardlist* temp = *sfl;
	*sfl = (*sfl)->next;
	delete temp;
	//size??
}

//удаление элемента из начала недосписка
int pop_forward(subforwardlist** sfl) {

	subforwardlist* temp = *sfl;
	*sfl = (*sfl)->next;
	int f = (*sfl)->data;
	delete temp;
	//size??

	return f;
}

//добавление элемента с порядковым номером where
bool push_where(subforwardlist** sfl, unsigned int where, int d) {

	//сначала нужно найти элемент, который предшествует тому, индекс которого ищем
	//если null??

	if (where == 0)
	{
		push_forward(&(*sfl), d);
	}
	else
	{
		subforwardlist* prev = nullptr; // = (*sfl);   ///->next;
		subforwardlist* cur = (*sfl);

		for (unsigned int i = 0; i != where; i++)
		{
			prev = cur;
			cur = cur->next;
			//prev = prev->next;
		}

		//значение адреса предыдущего объекта присваиваем новому: теперь новый указывает на следующий
		subforwardlist* new_el = new subforwardlist;
		new_el->next = cur->next;
		new_el->data = d;
		prev->next = new_el;
		//prev->next = new_el;

		//size??
	}
	
	return true;
}


//удаление элемента с порядковым номером where
bool erase_where(subforwardlist** sfl, unsigned int where) {

	if (where == 0)
	{
		pop_front(&(*sfl));
	}
	else
	{
		subforwardlist* prev = (*sfl)->next;

		for (unsigned int i = 0; i < where - 1; i++)
		{
			prev = prev->next;
		}
		subforwardlist* temp = prev->next;
		prev->next = temp->next;
		delete temp;
		//size??
	}
	return true;
}


//очистить содержимое недосписка
//void clear(subforwardlist** sfl) {
//
////	while (size??)
//	{
//		pop_front(&(*sfl));
//	}


int main()
{
	subforwardlist *sfl;

	init(&sfl);
	push_forward(&sfl, 5);
	push_forward(&sfl, 2);
	push_back(&sfl, 3);
	//push_back(&sfl, 4);
	//cout << where(&sfl, 1);
	//cout << size(&sfl);
	pop_front(&sfl);
	push_forward(&sfl, 2);
	push_forward(&sfl, 3);
	push_where(&sfl, 1, 7);
	cout << where(&sfl, 1) << endl;
	cout << where(&sfl, 2);

	
	return 0;
}

