#include <stdio.h>
// code add new element in the begining of list
struct node 
{
	int value;
	struct node* next;
};

void print_list(struct node* head) 
{
	while (1) 
	{
		if (head == NULL) break;
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

void insert(struct node** head, int t) 
{
	struct node* temp = malloc(sizeof(struct node));
	temp->value = t;
	temp->next = *head;
	*head = temp;
}

void delete(struct node** head, int t) 
{
	struct node* prev = *head;

	// CASE WHEN ELEMENT TO DELETE IS LOCATED AT THE HEAD OF LIST
	if ((*head)->value == t) {
		*head = (*head)->next;
		return 0;
	}

	// WE ITERATE THROUGH LIST AND TRY TO FIND THE NEEDED VALUE,IF IT IS NOT PRESENT prev=NULL,OTHERWISE prev=NEEDED VALUE
	while (prev->next != NULL && prev->next->value != t)
	{
		prev = prev->next;
	}

	if (prev->next != NULL) 
	{
		struct node* del = prev->next;
		prev->next = del->next;
	}
}
