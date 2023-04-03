/*
 *
 *
        Author    : Eslam Yasser
        program   : Magic Box
        Modified  : 02 April 2023

    Notes :
    - this written and tested on Ubuntu Based Linux OS(Unity).

*/

#include <stdio.h>
#include <stdlib.h>
//
#define Spacing 5

int main()

{
    //declaration of Co-ordinations x,y and value for every loop.
    unsigned int val =1, x = 1, y;
    unsigned int SizeOfBox;
    printf("\n \t MagicBox by Eslam....\n Enter a Numeric Value :\n\n");


    /*
       - Because we are in a Linux 'gotoxy()' won't work at all
         so we will creates our own 'MoveAndSetValue()'

       - this Method will Jump to a specific Place(x, y) and put a value in it.
         Allow you to control the spacing between

       - where v parameter is for Value you want to print.
    */
    void MoveAndSetValue(int xCord, int yCord, int v)
    {

        xCord *= Spacing-3;
        yCord *= Spacing;
        printf("\033[%d;%dH",xCord, yCord);
        printf("(%d)",v);
    }

// Creates and And Positions elements of the box

    void TheBox()
    {
        y = (SizeOfBox+1)/2; //init y here cuz just get size
        do
        {
            MoveAndSetValue(x, y, val);
            switch (val%SizeOfBox != 0)
            {
            case 0:
                x++;
                break;

            default:
                x--;
                y--;
            } // switch end

            if(x==0)x=SizeOfBox;
            if(y==0)y=SizeOfBox;
            val++;
        }//do end to while(exit cond)
        while(val <= SizeOfBox*SizeOfBox);
        printf("\n\n Keda El Gadwal Tamam\n \t By Eslam Yasser");
    }

    //Get the UserInput(Size) and Check it via if.
    fflush(stdout);
    scanf("%d", &SizeOfBox);
    char Scondition = (SizeOfBox%2 != 0 && SizeOfBox >= 0);
    switch(Scondition)
    {
    case 0:
        printf("this Value Is Not Valid .... \n the program Will Restart\n");
        fflush(stdin);
        main();
        break;
    default:
        printf("\033[2J \a\a");
        TheBox();
    }
    return 0;
}//main end
