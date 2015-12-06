#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
};

void ascend_desc_sort(struct node *head)
{
    struct node *current = head, *temp, *p=NULL;
    while(current->next != NULL && current->data < current->next->data)  //find the first element of descending part
    {
        p = current;
        current = current->next;
    }
    if(current->next == NULL) //List is already sorted
        return;
    temp = current;
    while(temp->next != NULL && temp->data > temp->next->data) // Find the element after descending part. Example for 10->20->40->30->50 , 50 is in temp->next
        temp = temp->next;
    current = reverse(current,temp->next);  //reverse the descending part and store its head in current
   p->next = current; //append the reverse descending part head to last element of ascending part
}

struct node* reverse(struct node *head,struct node *end)  //Reverse the list from start node to node before end and return head of reversed list
{
   // Last element of reverse list should point to the element after descending part
   //Example : If list is 10->20->50->40->30->60->80  reverse 50->40->30 and 50 should point to 60( end)
    struct node *prev=end ,*temp,*temp2, *current=head;
    while(current != end)
    {
        temp = current->next;
        current->next  = prev;
        prev = current;
        current = temp;
    }
    return prev;  //prev is the head of the reversed list
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
    int i;
    int a[7] = {1,2,3,15,10,4,20};
    for (i = 0; i < 7; i++)
        insert(&head, a[i]);
    display(head);
    ascend_desc_sort(head);
    display(head);
    _getch();
    return 0;
}
