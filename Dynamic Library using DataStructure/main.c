#include"header.h"
void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}
int main()
{
    char ch;
    while(1)
    {
        system("cls");
        SetColor(9);
        printf("\n\n\t\t*******WELCOME TO DATA STRUCTURES********");
        SetColor(11);
        printf("\n\n\n1. LINKED LIST");
        printf("\n2. STACK");
        printf("\n3. QUEUES");
        printf("\n4. SEARCHING  ");
        printf("\n5. SORTING  ");
        printf("\n6. AVL TREE  ");
        printf("\n7. QUIT");
        printf("\n\n\n\nEnter your choice :> ");
        ch=getche();
        switch(ch)
        {
            case '1':   linkedlist();
                        break;
            case '2':   stackk();
                        break;
            case '3':   Queues();
                        break;
            case '4': searching();break;
            case '5':  sorting();break;
            case '6':  avltree();break;
            case '7':      SetColor(10);
                                 printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t THANK YOU!!!!!!!");
                                 printf("\t\t\t\t\t\t\t\tBY-SHUBHAM MITTAL\n\n");
                                 system("pause");
                                  exit(0);
        }
    }

}





