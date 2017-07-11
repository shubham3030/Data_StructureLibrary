
void stackk()
{
         char ch;
         system("cls");
         SetColor(9);
         printf("\n\n\t\t\t****STACKS****");
         while(1)
         {
                  SetColor(11);
                  printf("\n\n1.ARRAY STACK");
                  printf("\n2.LINKED STACK ");
                  printf("\n3.APPLICATION OF STACK ");
                  printf("\n4.GO TO MAIN MENU");
                  printf("\n5.EXIT ");

                  printf("\nEnter your choice :");
                  ch=getche();
                  switch(ch)
                  {
                           case '1': arr_stack();
                                          break;
                           case '2' : llstack();
                                           break;
                           case '3': appstack();break;
                           case '4' :system("cls"); return;
                           case '5':  SetColor(10);printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                            printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                           exit(0);
                           default:  break;
                   }

         }
}

