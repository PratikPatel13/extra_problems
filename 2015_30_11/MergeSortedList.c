#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void insert(struct node **head, int data);
void display(struct node *head);
struct node
{
	int data;
	struct node *next;
};
/*
	This method works by comparing two elements(one from each list). 
	p points to position in merge list and after each comparision between data it points to the smaller data and that list current position is incremented.
	Example : If list are 1 4 5 3 and 2 3 6 9 10. Then at start head of mergelist points to 1 as it is smaller than 2.
		and current of that list becomes 4 and current of list2 is 2. current elements (4 & 2) are compared and the mergelist current pointer(p) points to smaller element(2)
		and current pointer of that list is incremented. This is continued till one of the list is becomes empty and then all elements of other list are appended.
*/
struct node* Merge(struct node *head1,struct node *head2)
{
	struct node *p = NULL, *head = NULL;  // head is used to return starting of merged list, p is used as current pointer for merged list
	struct node *c1 = head1, *c2 = head2; // c1 and c2 are pointers for current position in two list
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	// set the head of merge list to the list whose first element is small and increment current pointer of that list
	if (c1->data < c2->data)  
	{
		p = c1;
		c1 = c1->next;
	}
	else
	{
		p = c2;
		c2 = c2->next;
	}
	head = p;
	while (c1 != NULL && c2 != NULL) 	//Traverse through the list till one of the list is empty
	{
		if (c1->data < c2->data)  //If the data of one list is small than other then the smaller data node should be pointed by p and p points to that node now
		{
			p->next = c1;
			p = c1;
			c1 = c1->next;
		}
		else
		{
			p->next = c2;
			p = c2;
			c2 = c2->next;
		}
	}
	// If one of the list is empty then append the other list to the current mergelist
	if (c1 == NULL)
		p->next = c2;
	else
		p->next = c1;
	return head;
}

int main()
{
	struct node *head1 = NULL, *head2 = NULL, *mergehead;
	int i;
	int a[6] = { 1, 6,9,10 }, b[6] = { 2, 3, 4,  5, 8 };
	for (i = 0; i < 4; i++)
		insert(&head1, a[i]);
	for (i = 0; i < 5; i++)
		insert(&head2, b[i]);
	display(head1);
	display(head2);
	mergehead = Merge(head1, head2);
	display(mergehead);
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

/* Test cases:
	Input : l1 = 1 4 5 7 l2 = 2 3 6 9 10  Output : 1 2 3 4 5 6 7 9 10
	Input : l1: 1 2 3 4  l2 : 5 6 7 8 9 Output : 1 2 3 4 5 6 7 8 9 
	Input l1 : 4 5 6 l2 : Empty Output 4 5 6 12
*/