#define mAx 50
int Linearsearch(int arr[], int n, int item)
{
	int i=0;
	while(i<n && item!=arr[i])
			i++;
	if(i < n)
		return i;
	else
		return -1;
}
void lisearch()
{
           system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t#### LINEAR SEARCH ####");
	int i, n, item, arr[mAx], index;
	SetColor(11);
	printf("\n\nEnter the number of elements : ");
	scanf("%d",&n);
	printf("Enter the elements : \n");
	for(i=0; i<n; i++)
		scanf("%d", &arr[i] );

	printf("\nEnter the item to be searched : ");
	scanf("%d", &item);

	index = Linearsearch(arr, n, item);

	if(index == -1)
		printf("%d not found in array\n", item);
	else
		printf("%d found at position %d\n", item, index);
}// END OF LINEAR SEARCH
int BinarySearch(int arr[], int size, int item)
{
	int low=0, up=size-1, mid;
	while(low<=up)
	{
		mid = (low+up)/2;
		if(item>arr[mid])
			low = mid+1;	/*Search in right half */
		else if(item<arr[mid])
			up = mid-1;		/*Search in left half */
		else
			return mid;
	}
	return -1;
}
int bisearch()
{
           system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t#### BINARY SEARCH ####");
	int i, size, item, arr[mAx], index;
	SetColor(11);
	printf("\nEnter the number of elements : ");
	scanf("%d",&size);
	printf("\nEnter the elements (in sorted order) : ");
	for(i=0; i<size; i++)
		{scanf("%d", &arr[i] );}
          printf("\nEnter the item to be searched : ");
	scanf("%d", &item);
        index = BinarySearch(arr, size, item);
         if(index==-1)
		printf("\n%d not found in array\n", item);
	else
		printf("\n%d found at position %d\n", item, index);
}// END OF BINARY SEARCH

int fibo(int a[],int n)
{
	int i;
	for(i=0; i<mAx; i++)
{
	if(a[i]>=n)
	return(i);
}
}
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}
int fibonacci(int ar[],int n,int find,int a[],int fib,int fibm1,int fibm2,int offset,int index)
{
	static int j;
	if(fibm2==0)
	return -1;
	if(ar[index]==find)
	return index;
	else if(ar[index]<find)
{
	j=fibo(a,fibm1);
	fib=a[j]; fibm1=a[j-1]; fibm2=a[j-2];
	offset=offset+fibm2;
	index=min((offset+fibm2),n);
	fibonacci(ar,n,find,a,fib,fibm1,fibm2,offset,index);
}
	else
{
	j=fibo(a,fibm2);
	fib=a[j]; fibm1=a[j-1]; fibm2=a[j-2];
	index=min((offset+fibm2),n);
	fibonacci(ar,n,find,a,fib,fibm1,fibm2,offset,index);
}
}

int fibo_search()
{
         system("cls");
         SetColor(9);
         printf("\n\n\n\t\t\t####  FIBONACCI SEARCH ####");
	SetColor(11);
	int ar[mAx],n,i,find,in,a[mAx],j;
	int fib,fibm1,fibm2,offset=0,index,k;
	printf("\n\n\nEnter  the No. Of Elements :::");
	scanf("%d",&n);
	printf("Enter the Elements(in sorted order) ::\n");
	for(i=0; i<n; i++)
{
	scanf("%d",&ar[i]);
}
	a[0]=0;
	a[1]=1;
	for(j=2; j<mAx; j++)
{
	a[j]=a[j-1]+a[j-2];
}
	printf("\nEnter the Element to be Seached\n");
	scanf("%d",&find);
	k=fibo(a,n);
	fib=a[k]; fibm1=a[k-1]; fibm2=a[k-2];
	index=min((offset+fibm2),n);
	in=fibonacci(ar,n,find,a,fib,fibm1,fibm2,offset,index);
	if(in==-1)
	printf("\nELEMENT NOT FOUND\n");
	else
	printf("\nELEMENT %d IS AT  INDEX %d\n", ar[in],in);
}// END OF FIBONACCI SEARCH

void searching()
{
         char ch;
         system("cls");
         SetColor(9);
         printf("\n\n\n\n\t\t\t**** SEARCHING ****");
         while(1)
         {SetColor(11);
                  printf("\n\n\n1. LINEAR SEARCH ");
                  printf("\n2. BINARY SEARCH ");
                  printf("\n3. FIBONACCI SEARCH");
                  printf("\n4. GO TO MAIN MENU");
                  printf("\n5. EXIT ");
                  printf("\nEnter your choice :");
                  ch=getche();
                  switch(ch)
                  {
                           case '1': lisearch();
                                          break;
                           case '2' : bisearch();
                                           break;
                           case '3':  fibo_search(); break;
                           case '4' :system("cls"); return;
                           case '5':   SetColor(10);
                                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                               printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                                exit(0);
                           default : printf("\n\n\n\t oopsssss invalid option"); break;
                  }
         }
}//END OF SEARCHING
