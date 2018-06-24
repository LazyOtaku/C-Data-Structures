/*
Singly Linked list
Operations that can be performed:
	1. Insertion in the beginning
	2. Insertion at the end of the list
	3. Deletion in the beginning
	4. Deletion at the end of the list
	5. Display the linked list
	6. Insertion at desired position
	7. Deletion at desired position in the list
*/

#include <stdio.h>
#include <stdlib.h>
#define OP_SUC 0  //operation successful. cannot be -1.

int get_info();
struct node* create();
int front_insertion();
int end_insertion();
int display();
int front_deletion();
int end_deletion();
int position_insertion();
int position_deletion();

struct node{
	int info;
	struct node* next;
};

int num_entries = 0; //length of list
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
		printf("\n1 front_insertion\n2 end_insertion\n3 display\n4 front_deletion\n5 end_deletion\n6 position_insertion\n7 position_deletion\n8 exit\nEnter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1: x = front_insertion();
					break;
			case 2: x = end_insertion();
					break;
			case 3: x = display();
					break;
			case 4: x = front_deletion();
					break;
			case 5: x = end_deletion();
					break;
			case 6: x = position_insertion();
					break;
			case 7: x = position_deletion();
					break;
			case 8: exit(0);
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

int front_insertion()
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
		newnode->next = head;
		head = newnode;
	}
	num_entries++;
	return OP_SUC;
}

int end_insertion()
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
	num_entries++;
	return OP_SUC;
} 

int front_deletion()
{
	
	if( head == NULL)
	{
		printf("\nList is empty\n");
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
		head = temp->next;
		free(temp);
	}
	num_entries--;
	//printf("\nEntry removed");
	return OP_SUC;
}

int end_deletion()
{
	
	if( head == NULL)
	{
		printf("\nList is empty\n");
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

int display()
{
	
	printf("\n");
	//printf("\n%d entries: ",num_entries)
	if(head == NULL)
	{
		printf("List is empty\n");
		return -1;
	}
	if(head->next == NULL)
	{
		printf("%d -> ",head->info);
	}
	else
	{	struct node* temp;
		temp = head;
		while(temp!=rear)
		{
			printf("%d -> ",temp->info);
			temp = temp->next;
		}
		printf("%d -> ",temp->info);
	}
	printf("\n");
	return OP_SUC;
}


int position_insertion()
{
	int pos;
	int x = -1;
	printf("\nEnter position for insertion(1,2,3...): ");
	scanf("%d",&pos);

	if( pos > num_entries+1 || pos < 1 )
	{
		printf("\nIncorrect value for position\n");
		return -1;
	}
	if( pos == 1)
	{
		x = front_insertion();
		return x;
	}
	if( pos == num_entries+1 )
	{
		x = end_insertion();
		return x;
	}

	int i = 1;
	struct node* temp;
	struct node* prev;
	temp = head;
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

int position_deletion()
{
	int pos;
	int x = -1;
	printf("\nEnter position for deletion(1,2,3...): ");
	scanf("%d",&pos);

	if( pos > num_entries || pos < 1 )
	{
		printf("\nIncorrect value for position\n");
		return -1;
	}
	if( pos == 1)
	{
		x = front_deletion();
		return x;
	}
	if( pos == num_entries )
	{
		x = end_deletion();
		return x;
	}

	int i = 1;
	struct node* temp;
	struct node* prev;
	temp = head;
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
