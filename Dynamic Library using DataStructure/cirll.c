#include<stdio.h>
struct node
{
	int info;
	struct node *link;
};
struct node *last;
struct node *addempty(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	last=tmp;
	last->link=last;
	return last;
}
struct node *insert_beg(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	return last;
}
struct node *insert_end(struct node *last,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=last->link;
	last->link=tmp;
	last=tmp;
	return last;
}
struct node *insert_after(struct node *last,int data,int item)
{
	struct node *tmp,*p;
	p=last->link;
	do
	{
		if(p->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			tmp->info=data;
			tmp->link=p->link;
			p->link=tmp;
			if(p==last)
				last=tmp;
			return last;
		}
		p=p->link;
	}while(p!=last->link);
	printf("%d not present in the list\n",item);
	return last;
}
struct node *deletion(struct node *last,int data)
{
	struct node *tmp,*p;
	if(last==NULL)
	{
		printf("\nList is empty\n");
		return last;
	}
	/*Deletion of only node*/
	if(last->link==last && last->info==data)
	{
		tmp=last;
		last=NULL;
		free(tmp);
		return last;
	}
	/*Deletion of first node*/
	if(last->link->info==data)
	{
		tmp=last->link;
		last->link=tmp->link;
		free(tmp);
		return last;
	}
	/*Deletion in between*/
	p=last->link;
	while(p->link!=last)
	{
		if(p->link->info==data)
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return last;
		}
		p=p->link;
	}
	/*Deletion of last node*/
	if(last->info==data)
	{
		tmp=last;
		p->link=last->link;
		last=p;
		free(tmp);
		return last;
	}
	printf("\nElement %d not found\n",data);
	return last;
}
struct node *createcll(struct node *last)
{
	int i,n,data;
	printf("\nEnter the number of nodes : ");
	scanf("%d",&n);
	last=NULL;
	if(n==0)
		return last;
	printf("Enter the element to be inserted : ");
	scanf("%d",&data);
	last=addempty(last,data);

	for(i=2;i<=n;i++)
	{
		printf("Enter the element to be inserted : ");
		scanf("%d",&data);
		last=insert_end(last,data);
	}
	return last;
}
void displaycll(struct node *last)
{
	struct node *p;
	if(last==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	p=last->link;
	printf("\nList is : ");
	do
	{
		printf("%d ",p->info);
		p=p->link;
	}while(p!=last->link);
	printf("\n");
}
void circularll()
{
         system("cls");
         SetColor(9);
         printf("\n\n\n\t\t\t####CIRCULAR LINKED LIST####");
	int choice,data,item;
	struct node *last=NULL;
	char ch;
	while(1)
	{
	         SetColor(11);
		printf("\n\n\n1.Create List\n");
		printf("2.Display\n");
		printf("3.Add to empty list\n");
		printf("4.Add at beginning\n");
		printf("5.Add at end\n");
		printf("6.Add after \n");
		printf("7.Delete\n");
		printf("8.Quit\n");
                  printf("9.Go to Main Menu\n");
		printf("Enter your choice : ");
		//scanf("%d",&choice);
                  ch=getche();
		switch(ch)
		{
		 case '1':
			last=createcll(last);
			break;
		 case '2':
			displaycll(last);
			break;
		 case '3':
			printf("\nEnter the element to be inserted : ");
			scanf("%d",&data);
			last=addempty(last,data);
			break;
		 case '4':
			printf("\nEnter the element to be inserted : ");
			scanf("%d",&data);
			last=insert_beg(last,data);
			break;
		 case '5':
			printf("\nEnter the element to be inserted : ");
			scanf("%d",&data);
			last=insert_end(last,data);
			break;
		 case '6':
			printf("\nEnter the element to be inserted :");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&item);
			last=insert_after(last,data,item);
			break;
		 case '7':
			printf("\nEnter the element to be deleted : ");
			scanf("%d",&data);
			last=deletion(last,data);
			break;
		 case '8':  SetColor(10);
		                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                   printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                   exit(1);
                  case '9' : system("cls"); return;
		 default:
			printf("Wrong choice\n");}

	}
}

