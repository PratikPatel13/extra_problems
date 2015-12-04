#include<stdio.h>
#include<malloc.h>
void insert(struct node **head, int data);
void display(struct node *head);
struct node
{
	int data;
	struct node *next;
};

/*
To find median of sorted list make two pointers at starting.
Make one pointer move 1 element at once and other pointer move 2 elements at once.
when the second pointer reaches last element then the first pointer will be at middle.
*/
float Median(struct node *head)
{
	struct node *p = head, *q = head, *prev = NULL;  //Make two pointers at starting element. prev will be used only when there are even terms.
	int flag = 0; //flag for checking if there are even terms in list or odd terms. 
	if (head == NULL) // If the list is empty
		return 0;
	while (q != NULL && q->next != NULL)
	{
		prev = p;
		p = p->next;
		q = q->next->next;
	}
	if (q == NULL)
		flag = 1;
	if (flag == 1) //If the list has even terms then need to take average of two middle elements
	{
		return (prev->data + p->data) / 2.0;
	}
	return p->data; //If there are odd terms then return the middle element
}

int main()
{
	struct node *head = NULL;
	float median;
	int i;
	int a[6] = { 1, 3, 5, 6, 7, 8 };
	for (i = 0; i < 6; i++)
		insert(&head, a[i]);
	display(head);
	median = Median(head);
	printf("\nMedian=%.2f", median);
}

void insert(struct node **head, int data)
{
	struct node *p, *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	p = *head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = newNode;
}

void display(struct node *head)
{
	while (head != NULL)
	{
		printf("%d  ", head->data);
		head = head->next;
	}
}