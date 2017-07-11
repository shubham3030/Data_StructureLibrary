#include<stdio.h>
struct node
{
	struct node *prev;
	int info;
	struct node *next;
};
struct node *insert_empty(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
}
struct node *add_at_beg(struct node *start,int data)
{
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=start;
	start->prev=tmp;
	start=tmp;
	return start;
}
struct node *add_atend(struct node *start,int data)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->next!=NULL)
		p=p->next;
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}
struct node *add_after(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			tmp->prev=p;
			tmp->next=p->next;
			if(p->next!=NULL)
				p->next->prev=tmp;
			p->next=tmp;
			return start;
		}
		p=p->next;
	}
	printf("\n%d not present in the list\n\n",item);
	return start;
}
struct node *add_before(struct node *start,int data,int item)
{
	struct node *tmp,*q;
	if(start==NULL )
	{
		printf("\nList is empty\n");
		return start;
	}
	if(start->info==item)
	{
		tmp = (struct node *)malloc(sizeof(struct node));
		tmp->info=data;
		tmp->prev=NULL;
		tmp->next=start;
		start->prev=tmp;
		start=tmp;
		return start;
	}
	q=start;
	while(q!=NULL)
	{
		if(q->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->prev=q->prev;
			tmp->next = q;
			q->prev->next=tmp;
			q->prev=tmp;
			return start;
		}
		q=q->next;
	}
	printf("\n%d not present in the list\n",item);
	return start;
}
struct node *delete(struct node *start,int data)
{
	struct node *tmp;
	if(start==NULL)
	{
		printf("\nList is empty\n");
		return start;
	}
	if(start->next==NULL)	/*only one node in the list*/
		if(start->info==data)
		{
			tmp=start;
			start=NULL;
			free(tmp);
			return start;
		}
		else
		{
			printf("\nElement %d not found\n",data);
			return start;
		}
	/*deletion of first node*/
	if(start->info==data)
	{
		tmp=start;
		start=start->next;
		start->prev=NULL;
		free(tmp);
		return start;
	}
	/*deletion in between*/
	tmp=start->next;
	while(tmp->next!=NULL )
	{
		if(tmp->info==data)
		{
			tmp->prev->next=tmp->next;
			tmp->next->prev=tmp->prev;
			free(tmp);
			return start;
		}
		tmp=tmp->next;
	}
	if(tmp->info==data)
	{
		tmp->prev->next=NULL;
		free(tmp);
		return start;
	}
	printf("\nElement %d not found\n",data);
	return start;
}
struct node *createdll(struct node *start)
{
	int i,n,data;
	printf("\nEnter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	start=insert_empty(start,data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=add_atend(start,data);
	}
	return start;
}
void displaydll(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	p=start;
	printf("\nList is :\n");
	while(p!=NULL)
	{
		printf("%d ",p->info);
		p=p->next;
	}
}
void doublell()
{
         system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t####DOUBLY LINKED LIST####");
	int choice,data,item;
         char ch;
	struct node *start=NULL;
	while(1)
	{
                  SetColor(11);
		printf("\n\n\n1.Create List\n");
		printf("2.Display \n");
		printf("3.Add to empty list\n");
		printf("4.Add at beginning\n");
		printf("5.Add at end\n");
		printf("6.Add after\n");
		printf("7.Add before\n");
		printf("8.Delete\n");
		printf("9.Quit\n");
		printf("A.Go to Main menu\n");
		printf("\nEnter your choice : ");
		ch=getche();
		switch(ch)
		{
		 case '1':
			start=createdll(start);
			break;
		 case '2':
			displaydll(start);
			system("pause");
			break;
		 case '3':
			printf("\nEnter the element to be inserted : ");
			scanf("%d",&data);
			start=insert_empty(start,data);
			break;
		 case '4':
	        printf("\nEnter the element to be inserted : ");
			scanf("%d",&data);
			start=add_at_beg(start,data);
			break;
		 case '5':
			printf("\nEnter the element to be inserted : ");
			scanf("%d",&data);
			start=add_atend(start,data);
			break;
		 case '6':
			printf("\nEnter the element to be inserted: ");
			scanf("%d",&data);
			printf("\nEnter the element after which to insert : ");
			scanf("%d",&item);
			start=add_after(start,data,item);
			break;
		 case '7':
			printf("\nEnter the element to be inserted : ");
			scanf("%d",&data);
			printf("\nEnter the element before which to insert : ");
			scanf("%d",&item);
			start=add_before(start,data,item);
			break;
		 case '8':
			printf("\nEnter the element to be deleted : ");
			scanf("%d",&data);
			start=delete(start,data);
	   		break;
		 case '9':SetColor(10);printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                            printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                           exit(1);
                  case 'A':  system("cls");return;
		 default:
			printf("Wrong choice\n");
	}
   }
}

