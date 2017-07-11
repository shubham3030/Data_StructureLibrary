
#define dMAX 20

int deque_arr[dMAX];
int dfront=-1;
int drear=-1;
int DQisFull()
{
	if ( (dfront==0 && drear==dMAX-1) || (dfront==drear+1) )
		return 1;
	else
		return 0;
}
int DQisEmpty()
{
	if( dfront == -1)
		return 1;
	else
		return 0;
}
void insert_dfrontEnd(int item)
{
	if( DQisFull() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if( dfront==-1 )/*If queue is initially empty*/
	{
		dfront=0;
		drear=0;
	}
	else if(dfront==0)
		dfront=dMAX-1;
	else
		dfront=dfront-1;
	deque_arr[dfront]=item ;
}

void insert_drearEnd(int item)
{
	if( DQisFull() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if(dfront==-1)  /*if queue is initially empty*/
	{
		dfront=0;
		drear=0;
	}
	else if(drear==dMAX-1)  /*rear is at last position of queue */
		drear=0;
	else
		drear=drear+1;
	deque_arr[drear]=item ;
}

int delete_dfrontEnd()
{
	int item;
	if( DQisEmpty() )
	{
		printf("Queue Underflow\n");
		return;
	}
	item=deque_arr[dfront];
	if(dfront==drear) /*Queue has only one element */
	{
		dfront=-1;
		drear=-1;
	}
	else
		if(dfront==dMAX-1)
			dfront=0;
		else
			dfront=dfront+1;
	return item;
}

int delete_drearEnd()
{
	int item;
	if( DQisEmpty() )
	{
		printf("Queue Underflow\n");
		return;
	}
	item=deque_arr[drear];

	if(dfront==drear) /*queue has only one element*/
	{
		dfront=-1;
		drear=-1;
	}
	else if(drear==0)
		drear=dMAX-1;
	else
		drear=drear-1;
	return item;
}


void display_dq()
{
	int i;
	if( DQisEmpty() )
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue elements :\n");
	i=dfront;
	if( dfront<=drear )
	{
		while(i<=drear)
			printf("%d ",deque_arr[i++]);
	}
	else
	{
		while(i<=dMAX-1)
			printf("%d ",deque_arr[i++]);
		i=0;
		while(i<=drear)
			printf("%d ",deque_arr[i++]);
	}
	printf("\n");
}

void de_que()
{
         system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t####DOUBLY ENDED QUEUE####");
	int item,n,i;
	char ch;
	while(1)
         {
                  SetColor(11);
		printf("\n\n1.Insert at the front end\n");
		printf("2.Insert at the rear end\n");
		printf("3.Delete from front end\n");
		printf("4.Delete from rear end\n");
		printf("5.Display\n");
		printf("6.Go to Main Menu\n");
		printf("7.Quit\n");
		printf("Enter your choice : ");
                  ch=getche();
		switch(ch)
		{
		case '1':
			printf("\nInput the Number of elements : ");
			scanf("%d",&n);
                           for(i=0;i<n;i++)
                           {
                              printf("value to be Enqueue : ");
			   scanf("%d",&item);
			 insert_dfrontEnd(item);
                           }
			break;
		case '2':
			printf("\nInput the Number of elements : ");
			scanf("%d",&n);
                           for(i=0;i<n;i++)
                           {
                              printf("value to be Enqueue : ");
			   scanf("%d",&item);
			  insert_drearEnd(item);
                           }
			break;
		 case '3':
			printf("Element deleted from dfront end is : %d\n",delete_dfrontEnd());
			break;
		 case '4':
			printf("Element deleted from drear end is : %d\n",delete_drearEnd());
			break;
		 case '5':
			display_dq();
			break;
                  case '6':system("cls"); return;
		 case '7':SetColor(10);printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                            printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                            exit(1);
		 default:
			printf("Wrong choice\n");
		}
		printf("dfront = %d, drear =%d\n", dfront , drear);
		display_dq();
	}
}




