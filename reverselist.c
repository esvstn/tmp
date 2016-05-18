#include <iostream>
#include <cstdlib>
using namespace std;

struct mylist {
	int num;
	struct mylist * next;
};

void fill_list(struct mylist** temp)
{
	struct mylist* head = *temp = (struct mylist*) malloc(sizeof(struct mylist));
	for(int i=0; i < 100; i++)
	{
		(*temp)->num = i;
		(*temp)->next = (struct mylist*) malloc(sizeof(struct mylist));
		*temp = (*temp)->next;
	}
	(*temp)->next = NULL;
	*temp = head;
	cout << endl;
}

void print_list(struct mylist* temp)
{
	while(temp->next != NULL)
	{
		cout << temp->num << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	struct mylist *head;
	fill_list(&head);
	
	print_list(head);
	return 0;
}
