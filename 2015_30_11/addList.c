#include<stdio.h>
#include<malloc.h>
#include<conio.h>
void display(struct node *head);
struct node* addList(struct node *head1, struct node *head2);
void insert(struct node **head, int data);
struct node
{
	int data;
	struct node *next;
};
struct node* addList(struct node *head1, struct node *head2)
{
	struct node *head;
	head = head1;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	while (head1 != NULL && head2 != NULL)
	{
		head1->data = head1->data + head2->data;
		if (head1->next == NULL)
			break;
		head1 = head1->next;
		head2 = head2->next;
	}
	if (head2 != NULL)
	{
		head1->next = head2->next;
	}
	return head;
}

int main()
{
	struct node *head1 = NULL, *head2 = NULL, *result;
	int i;
	int a[6] = { 1, 2, 4,5 }, b[6] = { 1, 2, 3, 4};
	for (i = 0; i < 4; i++)
		insert(&head1, a[i]);
	for (i = 0; i < 4; i++)
		insert(&head2, b[i]);
	display(head1);
	display(head2);
	result = addList(head1, head2);
	display(result);
	_getch();
}

void insert(struct node **head, int data)
{
	struct node *p, *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	if (*head == NULL)
	{
		*head = newNode;
		newNode->next = NULL;
		return;
	}
	p = *head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	newNode->next = NULL;
	p->next = newNode;
}

void display(struct node *head)
{
	while (head != NULL)
	{
		printf("%d  ", head->data);
		head = head->next;
	}
	printf("\n");
}
