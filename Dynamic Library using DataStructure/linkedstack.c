#include<stdio.h>
struct node
{
	int info;
	struct node *link;
}*top=NULL;
int isEmpty()
{
	if(top == NULL)
		return 1;
	else
		return 0;
}
void push(int item)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=item;
	tmp->link=top;
	top=tmp;
}
int pop()
{
	struct node *tmp;
	int item;
	if( isEmpty() )
	{
		printf("\nStack Underflow\n");
		system("pause");
		return;
	}
	tmp=top;
	item=tmp->info;
	top=top->link;
	free(tmp);
	return item;
}
int peek()
{
	if( isEmpty() )
	{
		printf("\nStack Underflow\n");
		system("pause");
		return;
	}
	return top->info;
}
void displaylstack()
{
	struct node *ptr;
	ptr=top;
	if(isEmpty())
	{
		printf("\nStack is empty\n");
		return;
	}
	printf("\nStack elements :\n\n");
	while(ptr!=NULL)
	{
		printf(" %d\n",ptr->info);
		ptr=ptr->link;
	}
	printf("\n");
}
void llstack()
{
          system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t####LINKED STACK####");
         char ch;
	int choice,item,n,i;
	while(1)
	{
                    SetColor(11);
		printf("\n1.Push\n");
		printf("2.Pop\n");
		printf("3.Display item at the top\n");
		printf("4.Display all items of the stack\n");
		printf("5.Go to Main Menu\n");
		printf("6.Quit\n");
		printf("Enter your choice : ") ;
		//scanf("%d", &choice);
                  ch=getche();
		switch(ch)
		{
		case '1':
		         printf("\nEnter the number of values to be pushed\n");
		         scanf("%d",&n);
		         for(i=0;i<n;i++)
			{printf("value to be push : ");
			scanf("%d",&item);
			push(item);}
			break;
		case '2':
			item=pop();
			printf("Popped item is : %d\n",item);
			break;
		case '3':
			printf("Item at the top is %d\n",peek());
			break;
		case '4':
			displaylstack();
			system("pause");
			break;
                  case '5' : system("cls");return;
		case '6':SetColor(10);printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                            printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                           exit(1);
		default :
			printf("Wrong choice\n");
		}

	}
}
