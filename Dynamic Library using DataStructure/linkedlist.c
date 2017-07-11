void linkedlist()
{
         char ch;
         system("cls");
         SetColor(9);
         printf("\n\n\n\n\t\t\t****LINKED LIST****");
         while(1)
         {SetColor(11);
                  printf("\n\n\n1.SINGLE LINKED LIST ");
                  printf("\n2.DOUBLE LINKED LIST ");
                  printf("\n3.CIRCULAR LINKED LIST ");
                  printf("\n4.GO TO MAIN MENU");
                  printf("\n5.EXIT ");

                  printf("\nEnter your choice :");
                  ch=getche();
                  switch(ch)
                  {
                           case '1': singlell();
                                          break;
                           case '2' : doublell();
                                           break;
                           case '3':   circularll();
                                            break;
                           case '4' :system("cls"); return;
                           case '5':   SetColor(10);
                                                printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                               printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                                exit(0);
                           default : printf("\n\n\n\t oopsssss invalid option"); break;
                  }

         }

}
