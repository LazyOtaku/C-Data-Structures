#include <stdio.h>
#include <stdlib.h>
#define OP_SUC 0  //operation successful. cannot be -1.

int get_info();
struct node* create();
int front_insertion(struct node* h, struct node* r);
int end_insertion(struct node* h, struct node* r);
int display(struct node* h, struct node* r);
int front_deletion(struct node* h, struct node* r);
int end_deletion(struct node* h, struct node* r);
int position_insertion(struct node* h, struct node* r);
int position_deletion(struct node* h, struct node* r);

struct node{
	int info;
	struct node* next;
};

int num_entries = 0; //length of list

int main()
{
	int n;
	int x;
	struct node *head = NULL;
	struct node *rear = NULL;
	while(1)
	{
		printf("\n1 front_insertion\n2 end_insertion\n3 display\n4 front_deletion\n5 end_deletion\n6 position_insertion\n7 position_deletion\n8 exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1: x = front_insertion(head,rear);
					break;
			case 2: x = end_insertion(head,rear);
					break;
			case 3: x = display(head,rear);
					break;
			case 4: x = front_deletion(head,rear);
					break;
			case 5: x = end_deletion(head,rear);
					break;
			case 6: x = position_insertion(head,rear);
					break;
			case 7: x = position_deletion(head,rear);
					break;
			case 8: exit(0);
			default: x = -1;
		}
		if(x!=OP_SUC)
		{
			printf("\nOperation unsuccessful");
		}
	}
	return 0;
}

int get_info()
{
	int info;
	printf("\nEnter num to be inserted: ");
	scanf("%d",&info);
	return info;
}

struct node* create()
{
	int info = get_info();
	struct node* newnode = malloc(sizeof(struct node));
	// if malloc doesnt work return NULL;
	newnode->info = info;
	newnode->next = NULL;
	return newnode;
}

int front_insertion(struct node* head,struct node* rear)
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
		newnode->next = head->next;
		head = newnode;
	}
	num_entries++;
	return OP_SUC;
}

int end_insertion(struct node* head,struct node* rear)
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
		rear->next = newnode->next;
		rear = newnode;
	}
	num_entries++;
	return OP_SUC;
} 

int front_deletion(struct node* head,struct node* rear)
{
	if( head == NULL)
	{
		printf("\nList is empty");
		return -1;
	}
	if( head->next == NULL)
	{
		free(head);
		head = NULL;
		rear = NULL;
	}
	else
	{
		struct node *temp;
		temp = head;
		head = head->next;
		free(temp);
	}
	num_entries--;
	//printf("\nEntry removed");
	return OP_SUC;
}

int end_deletion(struct node* head,struct node* rear)
{
	if( head == NULL)
	{
		printf("\nList is empty");
		return -1;
	}
	if( head->next == NULL)
	{
		free(head);
		head = NULL;
		rear = NULL;
	}
	else
	{
		struct node *temp;
		temp = head;
		while(temp->next!=rear)
			temp = temp->next;
		temp->next = NULL;
		free(rear);
		rear = temp;
	}
	num_entries--;
	//printf("\nEntry removed");
	return OP_SUC;
} 

int display(struct node* head, struct node* rear)
{
	struct node* temp;
	temp = head;
	//printf("\n%d entries: ",num_entries)
	if(head == NULL)
	{
		printf("\nList is empty");
		return -1;
	}
	else if(head->next == NULL)
	{
		printf("%d",temp->info);
	}
	else
	{	
		while(temp!=rear)
		{
			printf("%d\t",temp->info);
			temp = temp->next;
		}
	}
	printf("\n");
	return OP_SUC;
}


int position_insertion(struct node* head,struct node* rear)
{
	int pos;
	int x = -1;
	printf("\nEnter position for insertion(1,2,3...): ");
	scanf("%d",&pos);

	if( pos > num_entries+1 || pos < 1 )
	{
		printf("\nIncorrect value for position");
		return -1;
	}
	if( pos == 1)
	{
		x = front_insertion(head,rear);
		return x;
	}
	if( pos == num_entries+1 )
	{
		x = end_insertion(head,rear);
		return x;
	}

	int i = 2;
	struct node* temp;
	struct node* prev;
	temp = head->next;
	prev = head;

	//while( i != pos || temp->next != NULL )
	while( i != pos )
	{
		i++;
		prev = temp;
		temp = temp->next; 
	}

	struct node* newnode;
	newnode = create();

	prev->next = newnode;
	newnode->next = temp;

	num_entries++;
	return OP_SUC;
}

int position_deletion(struct node* head,struct node* rear)
{
	int pos;
	int x = -1;
	printf("\nEnter position for deletion(1,2,3...): ");
	scanf("%d",&pos);

	if( pos > num_entries || pos < 1 )
	{
		printf("\nIncorrect value for position");
		return -1;
	}
	if( pos == 1)
	{
		x = front_deletion(head,rear);
		return x;
	}
	if( pos == num_entries )
	{
		x = end_deletion(head,rear);
		return x;
	}

	int i = 2;
	struct node* temp;
	struct node* prev;
	temp = head->next;
	prev = head;

	//while( i != pos || temp->next != NULL )
	while( i != pos )
	{
		i++;
		prev = temp;
		temp = temp->next; 
	}
	if( temp->next == NULL )
		prev->next = NULL;
	else 
		prev->next = temp->next;
	free(temp);
	
	num_entries--;
	//printf("Entry removed");
	return OP_SUC;
} 
