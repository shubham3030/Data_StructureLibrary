#include<stdio.h>
struct node
{
	int info;
	struct node *link;
};
struct node *addatbeg(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}

struct node *addatend(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
		p=p->link;
	p->link=tmp;
	tmp->link=NULL;
	return start;
}

struct node *addafter(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	p=start;
	while(p!=NULL)
	{
		if(p->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("%d not present in the list\n",item);
	return start;
}

struct node *addbefore(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	if(start==NULL )
	{
		printf("List is empty\n");
		return start;
	}
	/*If data to be inserted before first node*/
	if(item==start->info)
	{
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->info=data;
		tmp->link=start;
		start=tmp;
		return start;
	}
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			return start;
		}
		p=p->link;
	}
	printf("%d not present in the list\n",item);
	return start;
}

struct node *addatpos(struct node *start,int data,int pos)
{
	struct node *tmp,*p;
	int i;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	if(pos==1)
	{
		tmp->link=start;
		start=tmp;
		return start;
	}
	p=start;
	for(i=1; i<pos-1 && p!=NULL; i++)
		p=p->link;
	if(p==NULL)
		printf("\nThere are less than %d elements\n",pos);
	else
	{
		tmp->link=p->link;
		p->link=tmp;
	}
	return start;}
struct node *create_list(struct node *start)
{
	int i,n,data;
	printf("\nEnter the number of nodes : ");
	scanf("%d",&n);
	start=NULL;
	if(n==0)
		return start;

	printf("\nEnter the element to be inserted : ");
	scanf("%d",&data);
	start=addatbeg(start,data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		start=addatend(start,data);
	}
	return start;
}

void display(struct node *start)
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
		p=p->link;
	}
	printf("\n");
}

struct node *del(struct node *start,int data)
{
	struct node *tmp,*p;
	if(start==NULL)
	{
		printf("\nList is empty\n");
		return start;
	}
	/*Deletion of first node*/
	if(start->info==data)
	{
		tmp=start;
		start=start->link;
		free(tmp);
		return start;
	}
	/*Deletion in between or at the end*/
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==data)
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return start;
		}
		p=p->link;
	}
	printf("\nElement %d not found\n",data);
	return start;
}
struct node *reverse(struct node *start)
{
	struct node *prev, *ptr, *next;
	prev=NULL;
   	ptr=start;
	while(ptr!=NULL)
	{
		next=ptr->link;
		ptr->link=prev;
		prev=ptr;
		ptr=next;
	}
	start=prev;
	return start;
}
void  singlell()
{
         system("cls");
         SetColor(9);
         printf("\n\n\n\t\t\t####SINGLE LINKED LIST####");
	struct node *start=NULL;
	int data,item,pos;
         char ch;
	while(1)
	{
                  SetColor(11);
                  printf("\n\n1.Create List\n");
		printf("2.Display\n");
		printf("3.Add to empty list / Add at beginning\n");
		printf("4.Add at end\n");
		printf("5.Add after node\n");
		printf("6.Add before node\n");
		printf("7.Add at position\n");
		printf("8.Delete\n");
		printf("9.Reverse\n");
		printf("A.Go to Main Menu\n");
		printf("B.Quit\n\n");
                  printf("\nEnter your choice :");
		ch=getche();
		switch(ch)
		{
		 case '1':
			start=create_list(start);
			break;
		 case '2':
			display(start);
			system("pause");
			break;
		 case '3':
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatbeg(start,data);
			break;
		 case '4':
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=addatend(start,data);
			break;
		 case '5':
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			start=addafter(start,data,item);
			break;
		 case '6':
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which to insert : ");
			scanf("%d",&item);
			start=addbefore(start,data,item);
			break;
		 case '7':
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the position at which to insert : ");
			scanf("%d",&pos);
			start=addatpos(start,data,pos);
			break;
		 case '8':
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			start=del(start, data);
			break;
		 case '9':
			start=reverse(start);
			break;
                  case 'A' : system("cls");return;
		 case 'B':SetColor(10);printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                            printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                           exit(1);
		 default:
			 printf("Wrong choice\n");
		}

	}
}


