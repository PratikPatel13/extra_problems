#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};

void insertAtBeginning(struct node **head, int data)
{
	struct node *newNode, *current = *head;
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	if (*head == NULL)
	{
		*head = newNode;
		newNode->next = newNode;
		printf("Inserted %d\n", newNode->data);
		return;
	}
	// To insert at beginning change the pointer of last element to newNode and newNode point to head and head should be newNode now
	while (current->next != *head)
	{
		current = current->next;
	}
	newNode->next = *head;
	current->next = newNode;
	*head = newNode;
}

//Inserting at end is same as beginning and you don't need to change head pointer here
void insertAtEnd(struct node **head, int data)
{
	struct node *newNode, *current = *head;
	newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	if (*head == NULL)
	{
		*head = newNode;
		newNode->next = newNode;
		return;
	}
	while (current->next != *head)
	{
		current = current->next;
	}
	current->next = newNode;
	newNode->next = *head;
}

//To insert at given position find node before the position where newnode is to be inserted and 
//make it point to newNode and newNode point to previous node next.
void insertAtposition(struct node **head, int data, int K)
{
	int count = 1;
	struct node *newNode, *current = *head;
	newNode = (struct node *)malloc(sizeof(struct node *));
	while (count < K)
	{
		current = current->next;
		count++;
	}
	newNode->data = data;
	newNode->next = current->next;
	current->next = newNode;
}

void display(struct node *head)
{
	struct node *current = head;
	if (head == NULL)
	{
		printf("Empty List");
	}
	else
	{
		do{
			printf("%d ", current->data);
			current = current->next;
		} while (current != head);
	}
}

int main()
{
	struct node *head = NULL;
	insertAtBeginning(&head, 1);
	insertAtBeginning(&head, 0);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 5);
	insertAtposition(&head, 4, 3);
	display(head);
	_getch();
}
