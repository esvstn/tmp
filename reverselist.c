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
	(*temp)->num = 0;
	for(int i=1; i < 100; i++)
	{
		(*temp)->next = (struct mylist*) malloc(sizeof(struct mylist));
		*temp = (*temp)->next;
		(*temp)->num = i;
	}
	(*temp)->next = NULL;
	*temp = head;
}

void print_list(struct mylist* head)
{
	do {
		cout << head->num << " ";
		head = head->next;
	} while(head != NULL);
	cout << endl;
}

struct mylist* reverse_list(struct mylist* head)
{
	struct mylist *tmp1 = head->next;
	struct mylist *tmp2 = head->next->next;
	head->next = NULL;
	tmp1->next = head;

	while(tmp2 != NULL)	
	{
		head = tmp1;
		tmp1 = tmp2;
		tmp2 = tmp2->next;	
		tmp1->next = head;
	}
	return tmp1;
}

struct mylist* recur_reverse_list(struct mylist* first, struct mylist* second)
{
	if (second->next == NULL)
	{
		second->next = first;
		return second;
	} else
	{
		struct mylist* tmp = second->next;
		second->next = first;
		return recur_reverse_list(second, tmp);
	}
}


int main()
{
	struct mylist *head;
	fill_list(&head);
	print_list(head);
	head = reverse_list(head);
	print_list(head);
	head = recur_reverse_list(NULL, head);
	print_list(head);
	return 0;
}
