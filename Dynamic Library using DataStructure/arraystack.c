
#define MAX 10

int stack_arr[MAX];
int Top = -1;
int isempty()
{
	if( Top == -1 )
		return 1;
	else
		return 0;
}

int isfull()
{
	if( Top == MAX-1 )
		return 1;
	else
		return 0;
}
void push_item(int item)
{
	if( isfull() )
	{
		printf("\nStack Overflow\n");
		return;
	}
	Top = Top+1;
	stack_arr[Top] = item;
}
int pop_item()
{
	int item;
	if( isempty() )
	{
		printf("\nStack Underflow\n");
		system("pause");
	}
	item = stack_arr[Top];
	Top = Top-1;
	return item;
}
int PEEK()
{
	if( isempty() )
	{
		printf("\nStack Underflow\n");
		system("pause");
	}
	return stack_arr[Top];
}

void displaystack()
{
	int i;
	if( isempty() )
	{
		printf("\nStack is empty\n");
		return;
	}
    printf("\nStack elements :\n");
	for(i=Top;i>=0;i--)
		{printf("  %d  ", stack_arr[i] );}

}
void arr_stack()
{
         system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t####ARRAY STACK####");
	int choice,item,n,i;
	char ch;
	while(1)
	{
	         SetColor(11);
		printf("\n\n\n1.Push\n");
		printf("2.Pop\n");
		printf("3.Display the Top element\n");
		printf("4.Display all stack elements\n");
		printf("5.Go to Main Menu\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		ch=getche();
		switch(ch)
		{
		 case '1' :
                           printf("\nEnter the number of values to be pushed\n");
		         scanf("%d",&n);
		         for(i=0;i<n;i++)
                           {
                              printf("value to be push : ");
			   scanf("%d",&item);
			   push_item(item);
                           }
                           break;
                  case '2':
			item = pop_item();
			printf("\nPopped item is : %d\n",item );
			break;
		 case '3':
			printf("\nItem at the Top is : %d\n", PEEK() );
			break;
		 case '4':
			displaystack();
			break;
                  case '5':system("cls");return;
		 case '6':SetColor(10);printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                            printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                           exit(1);
		 default:
			printf("Wrong choice\n");
		}

	}
}





