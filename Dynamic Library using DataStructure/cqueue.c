#define Max 10

int cqueue_arr[Max];
int Front=-1;
int Rear=-1;
int EMPTY()
{
	if(Front==-1)
		return 1;
	else
		return 0;
}
int FULL()
{
	if((Front==0 && Rear==Max-1) || (Front==Rear+1))
		return 1;
	else
		return 0;
}
void insert_cq(int item)
{
	if( FULL() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if(Front == -1 )
		Front=0;

	if(Rear==Max-1)
		Rear=0;
	else
		Rear=Rear+1;
	cqueue_arr[Rear]=item ;
}
int del_cq()
{
	int item;
	if( EMPTY() )
	{
		printf("Queue Underflow\n");
		system("pause");
		return;
	}
	item=cqueue_arr[Front];
	if(Front==Rear) /* queue has only one element */
	{
		Front=-1;
		Rear=-1;
	}
	else if(Front==Max-1)
		Front=0;
	else
		Front=Front+1;
	return item;
}
int PEEKQ()
{
	if( EMPTY() )
	{
		printf("Queue Underflow\n");
		return;
	}
	return cqueue_arr[Front];
}
void display_cq()
{
	int i;
	if(EMPTY())
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	i=Front;
	if( Front<=Rear )
	{
		while(i<=Rear)
			printf("%d ",cqueue_arr[i++]);
	}
	else
	{
		while(i<=Max-1)
			printf("%d ",cqueue_arr[i++]);
		i=0;
		while(i<=Rear)
			printf("%d ",cqueue_arr[i++]);
	}

}
void cirqueue()
{
         system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t####CIRCULAR QUEUE####");
	int item,n,i;
	char ch;
	while(1)
	{
                  SetColor(11);
		printf("\n\n1.Insert item\n");
		printf("2.Delete item\n");
		printf("3.Peek\n");
		printf("4.Display\n");
		printf("5.Go to Main Menu\n");
		printf("6.Quit\n");
		printf("Enter your choice : ");
		ch=getche();
		switch(ch)
		{
		case '1' :printf("\nInput the Number of elements : ");
			       scanf("%d",&n);
                                   for(i=0;i<n;i++)
                                   {
                                     printf("value to be Enqueue : ");
                                    scanf("%d",&item);
			          insert_cq(item);
                                    }
			       break;
		case '2' :
			printf("\nElement deleted is : %d\n",del_cq());
			break;
		case '3':
			printf("\nElement at the Front is  : %d\n",PEEKQ());
			break;
		case '4':
			display_cq();
			break;
                  case '5':system("cls"); return;
		case '6':SetColor(10);printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                            printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                           exit(1);
		default:
			printf("Wrong choice\n");
		}
	}
}

