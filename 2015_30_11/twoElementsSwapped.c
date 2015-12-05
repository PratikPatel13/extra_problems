#include<stdio.h>
#include<malloc.h>
#include<conio.h>
void display(struct node *head);
void insert(struct node **head, int data);
struct node
{
	int data;
	struct node *next;
};

void swapUnusualElements(struct node **head1)
{
	struct node *prevX = NULL, *prevY = NULL, *curX = *head1, *curY,*temp;
	while (curX->next != NULL && curX->data < curX->next->data)  //Find the first unusual number
	{
		prevX = curX;
		curX = curX->next;
	}
	if (curX->next == NULL) //If there is no element which is in wrong position then the list is sorted
	{
		return;
	}
	curY = curX->next; // Find the next unsorted element
	while (curY->next != NULL && curY->data < curY->next->data)
	{
		curY = curY->next;
	}
	if (curY->next == NULL) //If there is no second element found then the element is adjacent to the first element Ex: 1 2 3 5 4 6 7
	{
		curY = curX->next; 
		prevY = curX;
	}
	else{   //If the second element is found than make it current Y and previous as prevY
		prevY = curY;
		curY = curY->next;
	}
	temp = curY->next; 
	if (prevX == NULL) //If prevX is NULL then the first element(head) is currentX so make head to current Y
	{
		*head1 = curY;
		curY->next = curX->next;
		curX->next = temp;
		prevY->next = curX;
	}
	else
	{
		prevX->next = curY;
		if (curX == prevY) //If elements are adjacent then there curX and prevY are same
			curY->next = curX;
		else
		{
			curY->next = curX->next;
			prevY->next = curX;

		}
		curX->next = temp;

	}
	
}

		
int main()
{
	struct node *head1 = NULL, *head2 = NULL;
	int i;
	int a[6] = {6,2,3,4,5,1};
	for (i = 0; i < 6; i++)
		insert(&head1, a[i]);
	display(head1);
	swapUnusualElements(&head1);
	display(head1);
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

/* Test Cases:

Input :1 2 5 4 3 6 (two non adjacent elements )
Output : 1 2 3 4 5 6

Input : 1 2 4 3 5 6 (two adjacent elements)
Output : 1 2 3 4 5 6

Input : 1 2 3 4 5 6 (sorted list )
Output : 1 2 3 4 5 6

Input : 6 2 3 4 5 1 (first and last elements)
Output : 1 2 3 4 5 6
*/