/*
Stack
Static Memory Allocation
Operations that can be performed:
	1. push onto stack
	2. pop from stack
	3. peep (view top os stack or tos)
*/

#include <stdio.h>
#include <stdlib.h>
#define OP_SUC 0  //operation successful. cannot be -1.
#define MAX_SIZE 10  //maximum size of stack

int get_info();
int push();
int peep();
int pop();

int stack[MAX_SIZE];
int tos =-1;    //top of stack

int main()
{
	int n;
	int x;
	tos = -1;
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

int push()
{
	if( tos == MAX_SIZE-1 ) //stack is full
	{
		printf("\nStack overflow\n");
		return -1;
	}
	stack[++tos] = get_info();	
	return OP_SUC;
}

int pop()
{
	
	if( tos == -1)  //stack is empty
	{
		printf("\nStack underflow\n");
		return -1;
	}
	printf("\n%d\n",stack[tos--]);
	return OP_SUC;
}

int peep()
{
	if(tos == -1)   //stack is empty
	{
		printf("\nStack is empty\n");
		return -1;
	}
	printf("\n%d\n",stack[tos]);
	return OP_SUC;
}