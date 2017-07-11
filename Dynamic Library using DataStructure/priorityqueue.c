#include<stdio.h>
struct node
{
	int priority;
	int info;
	struct node *link;
}*Pfront=NULL;
int PQisEmpty()
{
	if( Pfront == NULL )
		return 1;
	else
		return 0;
}
void insert_data(int item,int item_priority)
{
	struct node *tmp,*p;

	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
	{
		printf("Memory not available\n");
		return;
	}
	tmp->info=item;
	tmp->priority=item_priority;
	/*Queue is empty or item to be added has priority more than first element*/
	if( PQisEmpty() || item_priority < Pfront->priority )
	{
		tmp->link=Pfront;
		Pfront=tmp;
	}
	else
	{
		p = Pfront;
		while( p->link!=NULL && p->link->priority<=item_priority )
			p=p->link;
		tmp->link=p->link;
		p->link=tmp;
	}
}
int del_data()
{
	struct node *tmp;
	int item;
	if( PQisEmpty() )
	{
		printf("Queue Underflow\n");
		return;
	}
	else
	{
		tmp=Pfront;
		item=tmp->info;
		Pfront=Pfront->link;
		free(tmp);
	}
	return item;
}
void display_pq()
{
	struct node *ptr;
	ptr=Pfront;
	if( PQisEmpty() )
		printf("Queue is empty\n");
	else
	{	printf("Queue is :\n");
		printf("Priority  Item\n");
		while(ptr!=NULL)
		{
			printf("%d   %d\n",ptr->priority,ptr->info);
			ptr=ptr->link;
		}
	}
}
void priorqueue()
{
         system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t####PRIORITY QUEUE####");
	int item,item_priority,n,i;
	char ch;
	while(1)
	{
	         SetColor(11);
		printf("\n\n\n1.Insert  an item\n");
		printf("2.Delete item\n");
		printf("3.Display Priority queue\n");
		printf("4.Quit\n");
		printf("5.Go to Main Menu\n");
		printf("Enter your choice : ");
		ch=getche();
		switch(ch)
		{
		 case '1':printf("\nInput the Number of elements : ");
			scanf("%d",&n);
                           for(i=0;i<n;i++)
                           {
                             printf("Input the item to be added in the queue : ");
			  scanf("%d",&item);
			  printf("Enter its priority : ");
			  scanf("%d",&item_priority);
			  insert_data(item, item_priority);
                           }
                          break;
		 case '2':
			printf("Deleted item is %d\n",del_data());
			break;
		 case '3':
			display_pq();
			break;
		 case '4':SetColor(10);printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                    printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                    exit(1);
                  case '5':system("cls"); return;
		 default :
			printf("\n\tWrong choice!!!!!!!\n");
		}
	}
}







