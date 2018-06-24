/*
Queue
Operations that can be performed:
	1. enqueue
	2. dequeue
*/

#include <stdio.h>
#include <stdlib.h>
#define OP_SUC 0  //operation successful. cannot be -1.

int get_info();
struct node* create();
int enqueue();
int display();
int dequeue();

struct node{
	int info;
	struct node* next;
};

struct node* head ;
struct node* rear ;
 
int main()
{
	int n;
	int x;
	head = NULL;
	rear = NULL;
	while(1)
	{
		printf("\n1 enqueue\n2 dequeue\n3 display\n4 exit\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: x = enqueue();
					break;
			case 2: x = dequeue();
					break;
			case 3: x = display();
					break;
			case 4: exit(0);
			default: x = -1;
		}
		if(x!=OP_SUC)
		{
			printf("\nOperation unsuccessful\n");
		}
	}
	return 0;
}

int  get_info()
{
	int info;
	printf("\nEnter num to be inserted: ");
	scanf("%d",&info);
	return info;
}

struct node* create()
{
	int info = get_info();
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	// if malloc doesnt work return NULL;
	newnode->info = info;
	newnode->next = NULL;
	return newnode;
}

int enqueue()
{
	struct node* newnode;
	newnode = create();
	//if(newnode == NULL) return -1; //if failed malloc is to be handled
	if( head == NULL)
	{
		head = newnode;
		rear = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}
	return OP_SUC;
} 

int dequeue()
{
	
	if( head == NULL)
	{
		printf("\nQueue is empty\n");
		return -1;
	}
	if( head->next == NULL)
	{
		printf("\n%d\n",head->info);
		free(head);
		head = NULL;
		rear = NULL;
	}
	else
	{
		printf("\n%d\n",head->info);
		struct node *temp;
		temp = head;
		head = temp->next;
		free(temp);
	}
	return OP_SUC;
}

int display()
{
	
	printf("\n");
	if(head == NULL)
	{
		printf("Queue is empty\n");
		return -1;
	}
	if(head->next == NULL)
	{
		printf("%d\n",head->info);
	}
	else
	{	struct node* temp;
		temp = head;
		while(temp!=rear)
		{
			printf("%d <- ",temp->info);
			temp = temp->next;
		}
		printf("%d\n",temp->info);
	}
	return OP_SUC;
}
