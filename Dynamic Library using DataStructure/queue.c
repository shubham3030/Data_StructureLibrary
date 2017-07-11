void Queues()
{
         char ch;
         system("cls");
          SetColor(9);
         printf("\n\n\t\t\t****QUEUES****");
         while(1)
         {
                  SetColor(11);
                  printf("\n\n1.ARRAY QUEUE ");
                  printf("\n2.CIRCULAR QUEUE ");
                  printf("\n3.DEQUE ");
                  printf("\n4.PRIORITY QUEUE");
                  printf("\n5.APPLICATION OF QUEUES");
                  printf("\n6.GO TO MAIN MENU");
                  printf("\n7.QUIT");
                  printf("\n\nEnter your choice :");
                  ch=getche();
                  switch(ch)
                  {
                           case '1': aqueue();
                                          break;
                           case '2' : cirqueue();
                                           break;
                           case '3':   de_que();
                                            break;
                           case '4':    priorqueue(); break;
                           case '5' : appqueue();break;
                           case '6': system("cls");return;
                           case '7': SetColor(10);printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                            printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                             exit(0);
                           default:  break;
                  }
         }
}
