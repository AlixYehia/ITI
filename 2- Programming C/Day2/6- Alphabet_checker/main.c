#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x;
    printf("Enter a character to check whether alphabet or not: ");
    scanf("%c", &x);
    if(x >= 'a' || x >= 'A' && x >= 'z' || x >= 'Z')
    {
        printf("Character is an Alphabet");
    }
    else{
        printf("Character is not an Alphabet");
    }
    getch();
    return 0;
}
