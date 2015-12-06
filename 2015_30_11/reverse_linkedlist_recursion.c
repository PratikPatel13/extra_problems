#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
};
void display(struct node *head)
{
	while (head != NULL)
	{
		printf("%d  ", head->data);
		head = head->next;
	}
	printf("\n");
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

struct node* reverse(struct node *head)  //Reverse the list and return head of reversed list
{
    struct node *p = head;  
    struct node *r = p->next; //first element of rest of the list
	if (r == NULL) //If the list has only one element return the head
	{
		return p;
	}
	r = reverse(p->next);
	//change the direction of link. If list is 1->2->3->4 and p is at 3 then 4 points to 3 now and list becomes 1->2->3<-4 and do it recursively till first element
	p->next->next = p; 
	p->next = NULL; 
	return r;
}
int main()
{
    struct node *head = NULL;
    int i;
	int a[6] = {1,2,3,4,5,6};
	for (i = 0; i < 6; i++)
		insert(&head, a[i]);
	display(head);
	head = reverse(head);
	display(head);
	_getch();
}
