#include<stdio.h>
#define maxs 30
struct node *stacc[maxs];
struct node *queues[maxs];
int tOp=-1;
int f=-1;int r=-1;
struct node
{
         int data;
         struct node *right;
         struct node *left;
};
struct node *root;
struct node  *insert_ss(int item)
{
         struct node *p,*prev,*cur;
         p=(struct node *)malloc(sizeof(struct node));
         if(p==NULL)
         {
                  printf("\n Out of memory");

         }
         p->data=item;
         p->right=NULL;
         p->left=NULL;
         if(root==NULL)
         {
                  root=p;
                  return;
         }
         prev=NULL;
         cur=root;
         while(cur!=NULL)
         {
                  prev=cur;
                  if(p->data<cur->data)
                           cur=cur->left;
                  else
                           cur=cur->right;
         }
         if(prev->data >p->data)
                  prev->left=p;
         else
                  prev->right=p;

};
void Push( struct node *value)
{
         if(tOp==maxs-1)
         {
                  printf("stacc overflows");
                  return;
         }
         else
                  tOp=tOp+1;
                  stacc[tOp]=value;
}
struct node * PoP()
{
         struct node *t;
         if(tOp==-1)
         {
                  printf("\n stack is empty");
                  exit(0);
         }
         t=stacc[tOp];
         tOp=tOp-1;
         return t;
}
void Preorder(struct node *ptr)
{
         if(ptr==NULL)
                  return;
         printf(" %d ",ptr->data);
         Preorder(ptr->left);
         Preorder(ptr->right);
}
void Inorder(struct node *ptr)
{
         if(ptr==NULL)
                  return;
         Inorder(ptr->left);
         printf(" %d ",ptr->data);
         Inorder(ptr->right);
}
void Postorder(struct node *ptr)
{
         if(ptr==NULL)
                  return;
         Postorder(ptr->left);
         Postorder(ptr->right);
          printf(" %d ",ptr->data);
}
void insert_ques(struct node *item)
{
	if( r==maxs-1 )
	{
		printf("\nQueue Overflow\n");
		return;
	}
	if( f == -1 )
		f=0;
	r=r+1;
	queues[r]=item ;
}
struct node *del_ques()
{
	struct node * item;
	if( f==-1 || f==r+1 )
	{
		printf("\nQueue Underflow\n");
		return 0;
	}
	item=queues[f];
	f=f+1;
	return item;
}
int Queue_empty()
{
         if(f==-1|| f==r+1)
                  return 1;
         else
                  return 0;
}
 void levelorder(struct node *root)
 {
          struct node *ptr=root;
          if(ptr==NULL)
          {
                   printf("\nTree is Empty\n");
                   return;
          }
          insert_ques(ptr);
          while(!Queue_empty())
          {
                   ptr=del_ques();
                   printf(" %d ",ptr->data );
                   if(ptr->left!=NULL)
                           insert_ques(ptr->left);
                  if(ptr->right!=NULL)
                           insert_ques(ptr->right);
         }
 }
void appstack()
{
         int a,b,n;
         system("cls");
         SetColor(9);
         printf("\n\n\n\t\t\t#### APPLICATION OF STACK ####");
         SetColor(13);
         printf("\n\n\n\n....Stack is used in Tree Traversals......");
         SetColor(11);
         root=(struct node *)malloc(sizeof(struct node));
         root->data=20;
         root->left=NULL;
         root->right=NULL;
            printf("\n\n\nEnter the no. of elements :>");
            scanf("%d",&n);
            for(a=0;a<n;a++)
            {
                     printf("Enter the element ::");
                     scanf("%d",&b);
                     insert_ss(b);
            }
            printf("\nINORDER TRAVERSAL IS ::  ");
            Inorder(root);
            printf("\nPOSTORDER TRAVERSAL IS :: ");
            Postorder(root);
            printf("\nPREORDER TRAVERSAL IS ::  ");
            Preorder(root);
            printf("\n\n\t***************************************************\n");
             SetColor(10);
            printf("\n Other Applications ::");
            printf("\n\n1. Reversal of string");
            printf("\n2. Validity of parentheses");
            printf("\n3. Conversion of one form to other");
            printf("\n4. Evaluation of an Expression");
            printf("\n");
            system("pause");
            system("cls");
           return;
}
void appqueue()
{
         int a,b,n;
         system("cls");
         SetColor(9);
         printf("\n\n\n\t\t\t#### APPLICATION OF QUEUE ####");
         SetColor(13);
         printf("\n\n\n\n....Queue is used in Level Order Tree Traversal......");
         SetColor(11);
         root=(struct node *)malloc(sizeof(struct node));
         root->data=6;
         root->left=NULL;
         root->right=NULL;
            printf("\n\n\nEnter the no. of elements :>");
            scanf("%d",&n);
            for(a=0;a<n;a++)
            {
                     printf("Enter the element::");
                     scanf("%d",&b);
                     insert_ss(b);
            }
            printf("\nLEVEL ORDER TRAVERSAL IS :: \n ");
            levelorder(root);
            printf("\n\n\t***************************************************\n");
             SetColor(10);
            printf("\n Other Applications ::");
            printf("\n\n1. Breadth First Search Traversal");
            printf("\n2. CPU Scheduling/Disk Scheduling ");
            printf("\n3. Input-Output Buffer");
            printf("\n4. Handling of Interupts");
            printf("\n");
            system("pause\n");
            system("cls");
           return;
}
