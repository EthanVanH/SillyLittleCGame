#include "mainMenus.h"
#include <stdlib.h>
#include <ncurses.h>

/*Variables needed by following functions, changes to them allow easy menu manipulation*/
#define WIDTH 30
#define HEIGHT 10

char *choices[] = {
	"Play",
	"Load",
	"Stats",
	"Options",
	"Exit",
};
int menuChoices = sizeof(choices)/ sizeof(char*);

	
extern int mainMenu()
{
	WINDOW *menus;
	int highlight;
	int xVal;
	int yVal;
	int input;

	highlight = 1;
	xVal = (80 - WIDTH)/2;
	yVal = (24 - HEIGHT)/2;

	initscr();
	clear();
	noecho();
	cbreak();
	curs_set(0);

	menus = newwin(HEIGHT, WIDTH, yVal, xVal);
	keypad(menus,TRUE);
	refresh();

	printMenu(menus,highlight);
	/*Main menu loop*/
	while(input != highlight)
	{
		input = wgetch(menus);
		switch(input)
		{
			case KEY_UP:
				if(highlight==1)
				{
					highlight = menuChoices;
				}
				else
				{
					highlight--;
				}
				break;
			case KEY_DOWN:
				if(highlight ==menuChoices)
				{
					highlight =1;
				}
				else
				{
					highlight++;
				}
				break;
			case 10:
				input = highlight;
			default:
				/*laugh at the users inadequacy*/
				break;
		}
		printMenu(menus,highlight);
	}

	clrtoeol();
	refresh();
	getch();
	endwin();
	
	return 0;

}

extern void printMenu(WINDOW *menus,int highlight)
{
	int x;
	int y;
	int i;

	x = 2;
	y = 2;

	box(menus,0,0);

	for (i = 0; i < menuChoices; i++)
	{
		if(highlight ==i+1)
		{
			wattron(menus,A_REVERSE);
			mvwprintw(menus,y,x, "%s",choices[i]);
			wattroff(menus,A_REVERSE);
		}
		else
		{
			mvwprintw(menus,y,x,"%s",choices[i]);
		}	
		y++;
		wrefresh(menus);

	}
}