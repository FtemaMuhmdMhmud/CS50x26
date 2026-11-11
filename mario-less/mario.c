#include <stdio.h>
#include <cs50.h>
int main (void)
{
    int times;
    do
    {
        times = get_int("enter number of times\n");
    }
    while (times <1 || times >8);

    for (int row =1; row <=times; row++)
    {

        for (int column =0; column <times-row; column++)
        {
            printf(" ");
        }

        for (int column =1; column<=row; column++)
        {
            printf ("#");
        }

        printf("\n");
    }
}

