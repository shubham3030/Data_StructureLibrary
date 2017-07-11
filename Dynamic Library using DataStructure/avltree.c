#include<stdio.h>
#define FALSE 0
#define TRUE 1
struct node
{
	struct  node *lchild;
	int info;
	struct  node *rchild;
	int balance;
};
struct node *RotateLeft(struct node *pptr)
{
	struct node *aptr;
	aptr = pptr->rchild;
	pptr->rchild = aptr->lchild;
	aptr->lchild = pptr;
	return aptr;
}
struct node *RotateRight(struct node *pptr)
{
	struct node *aptr;
	aptr = pptr->lchild;
	pptr->lchild = aptr->rchild;
	aptr->rchild = pptr;
	return aptr;
}
struct node *insert_LeftBalance(struct node *pptr)
{
	struct node *aptr, *bptr;

	aptr = pptr->lchild;
	if(aptr->balance == 1)
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else
	{
		bptr = aptr->rchild;
		switch(bptr->balance)
		{
		case -1:
			pptr->balance = 0;
			aptr->balance = 1;
			break;
		case 1:
			pptr->balance = -1;
			aptr->balance = 0;
			break;
		case 0:
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}
struct node *insert_RightBalance(struct node *pptr)
{
	struct node *aptr, *bptr;
	aptr = pptr->rchild;
	if(aptr->balance == -1)
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);
	}
	else
	{
		bptr = aptr->lchild;
		switch(bptr->balance)
		{
		case -1:
			pptr->balance = 1;
			aptr->balance = 0;
			break;
		case 1:
			pptr->balance = 0;
			aptr->balance = -1;
			break;
		case 0:
			pptr->balance = 0;
			aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}

struct node *insert_left_check(struct node *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0:
		pptr->balance = 1;
		break;
	 case -1:
		pptr->balance = 0;
		*ptaller = FALSE;
			break;
	 case 1:
		pptr = insert_LeftBalance(pptr);
		*ptaller = FALSE;
	}
	return pptr;
}

struct node *insert_right_check(struct node *pptr, int *ptaller )
{
	switch(pptr->balance)
	{
	 case 0:
		pptr->balance = -1;
		break;
	 case 1:
		pptr->balance = 0;
		*ptaller = FALSE;
		break;
	 case -1:
		pptr = insert_RightBalance(pptr);
		*ptaller = FALSE;
	}
	return pptr;
}
struct node *insert_avl(struct node *pptr, int ikey)
{
	static int taller;
	if(pptr==NULL)
	{
		pptr = (struct node *) malloc(sizeof(struct node));
		pptr->info = ikey;
		pptr->lchild = NULL;
		pptr->rchild = NULL;
		pptr->balance = 0;
		taller = TRUE;
	}
	else if(ikey < pptr->info)
         {
		pptr->lchild = insert_avl(pptr->lchild, ikey);
		if(taller==TRUE)
			pptr = insert_left_check( pptr, &taller );
	}
	else if(ikey > pptr->info)
	{
		pptr->rchild = insert_avl(pptr->rchild, ikey);
		if(taller==TRUE)
			pptr = insert_right_check(pptr, &taller);
	}
	else
	{
		printf("Duplicate key\n");
		taller = FALSE;
	}
	return pptr;
}
struct node *del_LeftBalance(struct node *pptr,int *pshorter)
{
	struct node *aptr, *bptr;
	aptr = pptr->lchild;
	if( aptr->balance == 0)
	{
		pptr->balance = 1;
		aptr->balance = -1;
		*pshorter = FALSE;
		pptr = RotateRight(pptr);
	}
	else if(aptr->balance == 1 )
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateRight(pptr);
	}
	else
	{
		bptr = aptr->rchild;
		switch(bptr->balance)
		{
			case 0:
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:
				pptr->balance = -1;
				aptr->balance = 0;
				break;
			case -1:
			         pptr->balance = 0;
				aptr->balance = 1;
		}
		bptr->balance = 0;
		pptr->lchild = RotateLeft(aptr);
		pptr = RotateRight(pptr);
	}
	return pptr;
}
struct node *del_RightBalance(struct node *pptr,int *pshorter)
{
	struct node *aptr, *bptr;

	aptr = pptr->rchild;
	if (aptr->balance == 0)
                  {pptr->balance = -1;
		aptr->balance = 1;
		*pshorter = FALSE;
		pptr = RotateLeft(pptr);
	}
	else if(aptr->balance == -1 )
	{
		pptr->balance = 0;
		aptr->balance = 0;
		pptr = RotateLeft(pptr);
	}
	else
	{
		bptr = aptr->lchild;
		switch(bptr->balance)
		{
			case 0:
				pptr->balance = 0;
				aptr->balance = 0;
				break;
			case 1:
				pptr->balance = 0;
				aptr->balance = -1;
				break;
			case -1:
				pptr->balance = 1;
				aptr->balance = 0;
		}
		bptr->balance = 0;
		pptr->rchild = RotateRight(aptr);
		pptr = RotateLeft(pptr);
	}
	return pptr;
}
struct node *del_left_check(struct node *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0:
			pptr->balance = -1;
			*pshorter = FALSE;
			break;
		case 1:
			pptr->balance = 0;
			break;
		case -1:
			pptr = del_RightBalance(pptr, pshorter);
	}
	return pptr;
}
struct node *del_right_check(struct node *pptr, int *pshorter)
{
	switch(pptr->balance)
	{
		case 0:
			pptr->balance = 1;
			*pshorter = FALSE;
			break;
		case -1:
			pptr->balance = 0;
			break;
		case 1:
			pptr = del_LeftBalance(pptr, pshorter );
	}
	return pptr;
}
struct node *del_avl(struct node *pptr, int dkey)
{
	struct node *tmp, *succ;
	static int shorter;

	if( pptr == NULL) /*Base Case*/
	{
		printf("Key not present \n");
		shorter = FALSE;
		return(pptr);
	}
	if( dkey < pptr->info )
	{
		pptr->lchild = del_avl(pptr->lchild, dkey);
		if(shorter == TRUE)
			pptr = del_left_check(pptr, &shorter);
	}
	else if( dkey > pptr->info )
	{
		pptr->rchild = del_avl(pptr->rchild, dkey);
		if(shorter==TRUE)
			pptr = del_right_check(pptr, &shorter);
	}
	else
	{
                  if( pptr->lchild!=NULL  &&  pptr->rchild!=NULL )
		{
			succ = pptr->rchild;
			while(succ->lchild)
				succ = succ->lchild;
			pptr->info = succ->info;
			pptr->rchild = del_avl(pptr->rchild, succ->info);
			if( shorter == TRUE )
				pptr = del_right_check(pptr, &shorter);
		}
		else
		{
			tmp = pptr;
			if( pptr->lchild != NULL ) /*only left child*/
				pptr = pptr->lchild;
			else if( pptr->rchild != NULL) /*only right child*/
				pptr = pptr->rchild;
			else	/* no children */
				pptr = NULL;
			free(tmp);
			shorter = TRUE;
		}
	}
	return pptr;
}
void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("  %d  ",ptr->info);
		inorder(ptr->rchild);
	}
}
void avltree()
{
         system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t####ADELSON-VELSKI-LANDIS TREE####");
	int key,n,i;
	char ch;
	struct node *root = NULL;
         while(1)
	{
	          SetColor(11);
		printf("\n\n\n1. Insert Element\n");
		printf("2. Delete Element\n");
		printf("3. Inorder Traversal\n");
		printf("4. Go to Main menu\n");
		printf("5. Quit\n");
		printf("\nEnter your choice : ");
		ch= getche();
		switch(ch)
		{
		 case '1':printf("\nEnter the number of values ::");
		               scanf("%d",&n);
		               for(i=0;i<n;i++)
                                 {
                                    printf("Enter the key to be inserted :: ");
			         scanf("%d",&key);
			          root = insert_avl(root,key);
                                 }
			      break;
		 case '2':
			printf("\nEnter the key to be deleted : ");
			scanf("%d",&key);
			root = del_avl(root,key);
			break;
		 case '3':printf("\nThe inorder traversal is ::");
			      inorder(root);
			      break;
                   case '4' : system("cls"); return;
		 case '5': SetColor(10);
                                   printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                   printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                   exit(1);
		 default:
			printf("\nWrong choice\n");
		}
	}
}


