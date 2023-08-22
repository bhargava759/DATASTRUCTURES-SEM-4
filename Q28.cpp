#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int top = -1,stk[SIZE];
void push()
{
	 int ele;
	 printf("enter the element:\n");
	 scanf("%d",&ele);
	 if(top==SIZE-1)
	 {
	 	printf("stack is full/overflow:\n");
	 }
	 else
	 {
	 	top=top+1;
	 	stk[top] = ele;
	 }
}
void pop()
{
	int ele;
	if(top==-1)
	{
		printf("the stack is empty/underflow\n");
	}
	else
	{
		ele=stk[top];
		top=top-1;
		printf("the deleted element is:%d",ele);
	}
}
void peak()
{
	if(top==-1)
	{
		printf("the stack is empty/underflow\n");
	}
	else
	{
		printf("the top element is :%d",stk[top]);
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("the stack is empty");
	}
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("the elements in stack are:%d\n",stk[i]);
		}
	}
}
int main()
{
	int cho;
	do{
		printf("\n main menu");
		printf("\n 1.Push");
		printf("\n 2.Pop");
		printf("\n 3.Peak");
		printf("\n 4.Display");
		printf("\n 5.Exit\n");
		printf("enter your choice:\n");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1 :push();break;
			case 2 : pop();break;
			case 3 : peak();break;
			case 4 : display();break;
			case 5 : exit(0);
			default:
				printf("enter 1 to 5");
		}
	}
	while(cho>=1 && cho<=5);
	return 0;
}
