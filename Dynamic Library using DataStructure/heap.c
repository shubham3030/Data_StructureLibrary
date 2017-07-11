#define MaX 100
void display_h(int arr[], int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf(" %d  ",arr[i]);
}
void restoreDown(int arr[], int i, int size )
{
	int left=2*i, right=left+1;
	int num=arr[i];
	while(right<=size)
	{
		if( num>=arr[left] && num>=arr[right] )
		{
			arr[i] = num;
			return;
		}
		else if(arr[left] > arr[right])
		{
			arr[i] = arr[left];
			i = left;
		}
		else
		{
			arr[i] = arr[right];
			i = right;
		}
		left = 2 * i;
		right = left + 1;
	}
	if(left == size && num < arr[left] )
	{
		arr[i]=arr[left];
		i = left;
	}
	arr[i]=num;
}
void buildHeap(int arr[], int size)
{
	int i;
	for(i=size/2; i>=1; i--)
		restoreDown(arr,i,size);
}
int del_root(int arr[], int *size)
{
	int max = arr[1];
	arr[1] = arr[*size];
	(*size)--;
	restoreDown(arr,1,*size);
	return max;
}
void heap_sort(int arr[], int size)
{
	int max;
	buildHeap(arr, size);
	printf("\nHeap is : \n");
	display_h(arr,size);
         while(size>1)
	{
		max = del_root(arr,&size);
		arr[size+1]=max;
	}
}

void heapsort()
{
           system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t#### HEAP SORT ####");
         SetColor(11);
	int i;
	int arr[MaX],n;
	printf("\nEnter number of elements : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter element %d : ",i);
		scanf("%d",&arr[i]);
	}
	printf("\nEntered list is :\n");
	display_h(arr,n);
          heap_sort(arr,n);
          printf("\nSorted list is :\n");
	  display_h(arr,n);
}




