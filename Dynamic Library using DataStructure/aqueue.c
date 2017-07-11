#define max 10
int queue_arr[max];
int rear=-1;
int front=-1;
int Empty()
{
	if( front==-1 || front==rear+1 )
		return 1;
	else
		return 0;
}
int Full()
{
	if( rear==max-1 )
		return 1;
	else
		return 0;
}
void insert_it(int item)
{
	if( Full() )
	{
		printf("Queue Overflow\n");
		return;
	}
	if( front == -1 )
		front=0;
	rear=rear+1;
	queue_arr[rear]=item ;
}
int del_it()
{
	int item;
	if( Empty() )
	{
		printf("Queue Underflow\n");
		return;
	}
	item=queue_arr[front];
	front=front+1;
	return item;
}
int Peek()
{
	if( Empty() )
	{
		printf("Queue Underflow\n");
		return;
	}
	return queue_arr[front];
}
void displayaq()
{
	int i;
	if ( Empty() )
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue is :\n");
	for(i=front;i<=rear;i++)
		printf("   %d   ",queue_arr[i]);

}
void aqueue()
{
         system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t####ARRAY QUEUE####");
	int item,i,n;
	char ch;
	while(1)
	{
                     SetColor(11);
		printf("\n\n1.Insert Element\n");
		printf("2.Delete Element\n");
		printf("3.Display element at the front\n");
		printf("4.Display all elements of the queue\n");
		printf("5.Go to Main Menu\n");
		printf("6.Quit\n");
		printf("\nEnter your choice : ");
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
			  insert_it(item);
                           }
			break;
		case '2':
			item=del_it();
			printf("\nDeleted element is  %d\n",item);
			break;
		case '3':
			printf("\nElement at the front is %d\n",Peek());
			break;
		case '4':
			displayaq();
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

