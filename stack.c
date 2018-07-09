/*
Stack
Dynamic Memory Allocation
Operations that can be performed:
	1. push onto stack
	2. pop from stack
	3. peep (view top os stack or tos)
*/

#include <stdio.h>
#include <stdlib.h>
#define OP_SUC 0  //operation successful. cannot be -1.

int get_info();
struct node* create();
int push();
int peep();
int pop();

struct node{
	int info;
	struct node* next;
};

struct node* tos ;   //top of stack
struct node* bos ;   //bottom of stack
 
int main()
{
	int n;
	int x;
	tos = NULL;
	bos = NULL;
	while(1)
	{
		printf("\n1 push\n2 pop\n3 peep\n4 exit\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: x = push();
					break;
			case 2: x = pop();
					break;
			case 3: x = peep();
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

int get_info()
{
	int info;
	printf("\nEnter num to be pushed: ");
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

int push()
{
	struct node* newnode;
	newnode = create();
	//if(newnode == NULL) return -1; //if failed malloc is to be handled
	if( tos == NULL)
	{
		tos = newnode;
		bos = newnode;
	}
	else
	{
		newnode->next = tos;
		tos = newnode;
	}
	return OP_SUC;
}

int pop()
{
	
	if( tos == NULL)
	{
		printf("\nStack is empty\n");
		return -1;
	}
	if( tos->next == NULL)
	{
		printf("\n%d\n",tos->info);
		free(tos);
		tos = NULL;
		bos = NULL;
	}
	else
	{
		struct node *temp;
		temp = tos;
		tos = temp->next;
		printf("\n%d\n",temp->info);
		free(temp);
	}
	//printf("\nEntry removed");
	return OP_SUC;
}

int peep()
{
	//printf("\n%d entries: ",num_entries)
	if(tos == NULL)
	{
		printf("\nStack is empty\n");
		return -1;
	}
	printf("\n%d\n",tos->info);
	return OP_SUC;
}