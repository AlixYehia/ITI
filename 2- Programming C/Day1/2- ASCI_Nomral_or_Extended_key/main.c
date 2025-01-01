#include <stdio.h>
#include <stdlib.h>

int main()
{

    int ch;

    printf("Press any key: ");
    ch = getch();

    // Check if it's a normal or extended key
    if (ch == 0 || ch == 224)
    {
        int ext_ch = getch();
        printf("\nExtended key pressed: ASCII value = %d\n", ext_ch);
    }

    else
    {
        printf("\nNormal key pressed: ASCII value = %d\n", ch);
    }

    getch();



    return 0;
}
