#include <stdio.h>
#include <stdlib.h>
#include <MyLibrary.h>

int main()
{
    int i, cur = 0, Flag = 0;
    char ch;
    char menu[3][8] = { "New", "Display", "Exit" };

    do
    {
        textattr(0x07);  // NormalBrush
        clrscr();

        // Display menu with highlighting for the selected option
        for(i = 0; i < 3; i++)
        {
            if(cur == i)
                textattr(0x70);  // HighlightedBrush
            else
                textattr(0x07);  // NormalBrush

            gotoxy(15, 4 * i + 3);  // Position the menu items
            printf("-> %s", menu[i]);  // Add arrows to each menu item
        }

        ch = getche();
        switch (ch)
        {
            case -32:   // Extended Keys
            case 0:
            case 224:
                ch = getche();
                switch(ch)
                {
                    case 72:  // Up arrow
                        cur--;
                        if(cur < 0)
                            cur = 2;
                        break;

                    case 80:  // Down arrow
                        cur++;
                        if(cur > 2)
                            cur = 0;
                        break;

                    case 71:  // Home key
                        cur = 0;
                        break;

                    case 79:  // End key
                        cur = 2;  // Highlight Exit option
                        // Do not set Fla to 1 here, just highlight the exit
                        break;
                }
                break;

            case 27:  // Escape key
                Flag = 1;
                break;

            case 13:  // Enter key
                if(cur == 0)
                {
                    clrscr();
                    printf("New Page...");
                    getche();
                }
                else if(cur == 1)
                {
                    clrscr();
                    printf("Display Page...");
                    getche();
                }
                else
                    Flag = 1;  // Exit when "Exit" is selected
                break;
        }
    } while(Flag == 0);

    return 0;
}
