#define maX 100
void Select_sort()
{
           system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t#### SELECTION SORT ####");
         SetColor(11);
	int arr[maX],i,j,n,temp,min;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &arr[i]);
	}
	for(i=0; i<n-1; i++)
	{
		min=i;
		for(j=i+1; j<n ; j++)
		{
			if(arr[min] > arr[j])
				min=j ;
		}
		if(i!=min)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp ;
		}
	}
	printf("\nSorted list is : \n");
	for(i=0; i<n; i++)
		printf("  %d  ", arr[i]);
}// END OF SELECTION SORT
void Bubble_sort()
{
           system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t#### BUBBLE SORT ####");
         SetColor(11);
	int arr[maX],i,j,temp,n,xchanges;
	printf("\nEnter the number of elements : ");
	scanf("%d",&n);
         for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d",&arr[i]);
	}
        for(i=0; i<n-1; i++)
	{
		xchanges=0;
		for(j=0; j<n-1-i; j++)
		{
			if(arr[j] > arr[j+1])
			{         temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				xchanges++;}
                  }
		if(xchanges==0)
			break;
	}
	printf("\nSorted list is :\n");
	for(i=0; i<n; i++)
		printf(" %d  ",arr[i]);
}// END OF BUBBLE SORT
void Insert_sort()
{
           system("cls");
          SetColor(9);
         printf("\n\n\n\t\t\t#### INSERTION SORT####");
         SetColor(11);
	int arr[maX],i,j,k,n;
	printf("\n\nEnter the number of elements : ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		printf("Enter element %d : ",i+1);
		scanf("%d", &arr[i]);
	}
        for(i=1; i<n; i++)
	{
		k=arr[i];

		for(j=i-1; j>=0 && k<arr[j]; j--)
			arr[j+1]=arr[j];
		arr[j+1]=k;
	}
         printf("Sorted list is :\n");
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
}// END OF INSERTION SORT
void div_conq(int arr[],int low,int up)
{
    int temp[60];
    int mid;
    if(low<up)
    {
    mid=(low+up)/2;
    div_conq(arr,low,mid);
    div_conq(arr,mid+1,up);
    merge(arr,temp,low,mid,mid+1,up);
    out_arr(arr,temp,low,up);
    }
}
void merge(int arr[],int temp[],int low1,int up1, int low2,int up2)
{
    int i=low1,j=low2,k=low1;
    while(i<=up1 &&j<=up2)
    {
        if(arr[i]<=arr[j])
           {
            temp[k++]=arr[i++];
             }
        else
        {
            temp[k++]=arr[j++];
        }
    }
    while(i<=up1)
    {
        temp[k++]=arr[i++];
    }
    while(j<=up2)
    {
        temp[k++]=arr[j++];
     }
}
void out_arr(int arr[],int temp[],int low,int up)
{
  int i;
  for(i=low;i<=up;i++)
  {
      arr[i]=temp[i];
  }
}
void merge_sort()
{
         system("cls");
         SetColor(9);
         printf("\n\n\n\t\t\t#### MERGE SORT ####");
         SetColor(11);
    int arr[60],n,i;
    printf("\n\nEnter the number of elements :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the element :");
        scanf("%d",&arr[i]);
    }
    div_conq(arr,0,n-1);
    printf("\n Sorted Array is :");
    for(i=0;i<n;i++)
    {
        printf("  %d  ",arr[i]);
    }
    return;
}// END OF MERGE SORT
void sorting()
{
         char ch;
         system("cls");
         SetColor(9);
         printf("\n\n\n\n\t\t\t**** SORTING ****");
         while(1)
         {SetColor(11);
                  printf("\n\n\n\n1. SELECTION SORT ");
                  printf("\n2. BUBBLE SORT");
                  printf("\n3. INSERTION SORT");
                  printf("\n4. HEAP SORT");
                  printf("\n5. MERGE SORT");
                  printf("\n6. GO TO MAIN MENU");
                  printf("\n7. EXIT ");
                  printf("\nEnter your choice :");
                  ch=getche();
                  switch(ch)
                  {
                           case '1':  Select_sort();  break;
                           case '2':  Bubble_sort(); break;
                           case '3':  Insert_sort();   break;
                           case '4':  heapsort();      break;
                           case '5' : merge_sort(); break;
                           case '6' : system("cls"); return;
                           case '7':  SetColor(10);
                                            printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                            printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                            exit(0);
                           default : printf("\n\n\n\t oopsssss invalid option"); break;
                  }
         }
}
// END OF SORTING
