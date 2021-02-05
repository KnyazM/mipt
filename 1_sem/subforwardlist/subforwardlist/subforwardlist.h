#ifndef __SUBLIST_H__
#define __SUBLIST_H__


using namespace std;

struct subforwardlist
{
	int data;
	subforwardlist* next;
};

//initialization of an empty list
bool init(subforwardlist** sfl) {

	*sfl = nullptr;

	return true;
}

//determine the size of the list
unsigned int size(subforwardlist** sfl) {

	unsigned int size = 1;

	if ((*sfl) != nullptr)
	{
		subforwardlist* temp = (*sfl);
		while (temp->next != nullptr)
		{
			temp = temp->next;
			size++;
		}

		return size;
	}

	else
	{
		return 0;
	}
}


//add an element to the end of the list
bool push_back(subforwardlist** sfl, int d) {

	if (*sfl != nullptr)
	{
		subforwardlist* temp = (*sfl);

		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new subforwardlist;
		temp->next->data = d;
		temp->next->next = nullptr;
	}
	else
	{
		*sfl = new subforwardlist;
		(*sfl)->data = d;
		(*sfl)->next = nullptr;
	}

	return true;
}


//delete an element from the end of the list
int pop_back(subforwardlist** sfl) {

	if (*sfl != nullptr)
	{
		subforwardlist* cur = (*sfl);
		int l = 0;

		if (cur->next != nullptr)
		{
			subforwardlist* prev = nullptr;
			while (cur->next != nullptr)
			{
				prev = cur;
				cur = cur->next;
			}

			l = cur->data;

			prev->next = nullptr;
			delete cur;
			return l;
		}
		else
		{
			l = cur->data;
			delete cur;
			(*sfl) = nullptr;
			return l;
		}

	}
	else
		return 0;
}

//add an element to the top of the list
bool push_forward(subforwardlist** sfl, int d) {

	if (*sfl == nullptr)
	{
		*sfl = new subforwardlist;
		(*sfl)->data = d;
		(*sfl)->next = nullptr;
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

//for clear
//delete an element from the beginning of the list
void pop_front(subforwardlist** sfl) {

	subforwardlist* temp = *sfl;
	*sfl = (*sfl)->next;
	delete temp;
}

//delete an element from the beginning of the list
int pop_forward(subforwardlist** sfl) {

	if (*sfl != nullptr)
	{	
		int f = (*sfl)->data;
		pop_front(&(*sfl));
		return f;
	}
	else
		return 0;

}

//add the element number "where"
bool push_where(subforwardlist** sfl, unsigned int where, int d) {


	if (where == 0 || *sfl == nullptr)
	{
		push_forward(&(*sfl), d);
	}
	else
	{
		subforwardlist* prev = nullptr;
		subforwardlist* cur = (*sfl);

		for (unsigned int i = 0; i != where; i++)
		{
			prev = cur;
			cur = cur->next;
		}

		subforwardlist* new_el = new subforwardlist;
		new_el->data = d;
		new_el->next = cur;
		prev->next = new_el;
		cur = cur->next;
	}

	return true;
}


//delete the element number "where"
bool erase_where(subforwardlist** sfl, unsigned int where) {

	if (where == 0)
	{
		pop_front(&(*sfl));
	}
	else
	{
		subforwardlist* prev = nullptr;
		subforwardlist* cur = (*sfl);

		for (unsigned int i = 0; i != where; i++)
		{
			prev = cur;
			cur = cur->next;
		}
		subforwardlist* next_el = cur->next;
		prev->next = next_el;
		delete cur;
	}
	return true;
}


//clear the contents of the list
void clear(subforwardlist** sfl) {

	unsigned int s = size(&(*sfl));
	for (unsigned int i = 0; i < s; i++)
	{
		pop_front(&(*sfl));
	}

}




#endif //__SUBLIST_H__
