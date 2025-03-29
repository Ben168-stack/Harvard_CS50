#include <stdio.h>
'''
A program that recreates a half-pyramid using hashes (#) for blocks,

E.g
Height: 4
    #  #
   ##  ##
  ###  ###
 ####  ####

Specification
To make things more interesting, first prompt the user with get_int for the half-pyramid’s height, a positive integer between 1 and 8, inclusive.
If the user fails to provide a positive integer no greater than 8, you should re-prompt for the same again.
Then, generate (with the help of print and one or more loops) the desired half-pyramid.
Take care to align the bottom-left corner of your half-pyramid with the left-hand edge of your terminal window.

'''
#include <stdio.h>

int get_int(const char *prompt)
{
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1)
    {
        while (getchar() != '\n')
            ;
        printf("Invalid input. Please enter a number: ");
    }
    return value;
}

int main()
{
    int height = 0;

    while (1)
    {
        height = get_int("Height: ");

        if (height >= 1 && height <= 8)
        {
            break;
        }
    }

    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < (height - i); j++)
        {
            printf(" ");
        }

        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("  ");

        for (int x = 0; x < i; x++)
        {
            printf("#");
        }
        // Move to the next line
        printf("\n");
    }

    return 0;
}
