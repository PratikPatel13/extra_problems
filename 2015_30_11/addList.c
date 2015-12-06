#include<stdio.h>
#include<malloc.h>
#include<conio.h>
int carry = 0;
struct node
{
	int data;
	struct node *next;
};
struct node* addList(struct node *head1,struct node *head2)
{
    struct node *head=head1; //head pointer for result list
    int l1,l2,d; // l1 and l2 for length and d for difference between list
    if(head1 == NULL) //If one of the list is empty return other
        return head2;
    if(head2 == NULL)
        return head1;
    l1 = length(head1);
    l2=length(head2);
   if(l1 == l2)
        recAdd(head1,head2);
    else  //If one list is bigger than other then move the second list d elements forward and then add the list of same size
    {
        d = abs(l1-l2);
        if(l1 > l2)
        {  //If list 1 is bigger than we need to store result in list1, so set head of result list to head of bigger list
            head = head1;
            while(d>0) //Move bigger list d elements forward so both list becomes same size and they can be added
            {
                head1 = head1->next;
                d--;
            }
            recAdd(head1,head2); //Add list of same size first
            addExtra(head,head1); // Add the extra part of bigger list to result
        }
        else
        {
            head = head2;
            while(d>0)
            {
                head2 = head2->next;
                d--;
            }
            recAdd(head2,head1);
            addExtra(head,head2);
        }
    }
    //If there is any carry left then create newnode and add carry to it
    if(carry == 1)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node*));
        newNode->data = carry;
        newNode->next = head;
        head = newNode;
    }
    return head;

}
/* This method is used to add two list of same size. We need to move till least significant bit and then
    add each digit from least significant bit and add carry if needed
*/
void recAdd(struct node *head,struct node *head2)
{
    struct node *p1 = head;
    struct node *p2 = head2;
	if (p1 == NULL)
	{
		return;
	}
	 recAdd(p1->next,p2->next);
    p1->data = p1->data + p2->data + carry;
    carry = 0;
    if(p1->data > 9)
    {
        carry = 1;
        p1->data = p1->data % 10;
    }
}

/* This function adds extra part of list to the result
    Example : if list are 2->4->3->5->6 and 4->5->6 then we first add 3->5->6 and 4->5->6 and get 8->1->2
    Now we need to add 2-4 part to 8->1->2 and that is done by addExtra
*/

void addExtra(struct node *head,struct node *end)
{
    if(head == end)
        return;
    addExtra(head->next,end);
    head->data = head->data + carry;
    carry = 0;
    if(head->data > 9)
    {
        carry = 1;
        head->data = head->data % 10;
    }
}

int length(struct node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
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

int main()
{
    struct node *head = NULL;
    struct node *head1 = NULL;
    int i;
	int a[6] = {9,9,9,9};
	int b[6] = {9,9,9,9};
	for (i = 0; i < 4; i++)
		insert(&head, a[i]);
    for (i = 0; i < 4; i++)
		insert(&head1, b[i]);
	display(head);
	display(head1);
	printf("\n");
    head = addList(head,head1);
	display(head);
	_getch();
}
/* Test cases:
Input : 1->2->3->4 1->2->3->4 Output: 1->2->3->4
Input : 1->5->6->7 4->6->5 Output : 2->0->3->2
Input:  9->9->9->9 9->9->9Output : 1->0->9->9->8
Input : 9->9->9-> 9->9->9->9 Output: 1->9->9-9->8

*/
