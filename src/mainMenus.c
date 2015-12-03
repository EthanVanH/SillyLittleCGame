#include "mainMenus.h"
#include <stdlib.h>
#include <ncurses.h>

int mainMenu()
{
	WINDOW *menus;
	int highlight;
	int choice;
	int xVal;
	int yVal;
	int input;

	highlight = 1;
	choice = 0;
	xVal = (80 - WIDTH)/2;
	yVal = (24 - HEIGHT)/2;

	initscr();
	clear();
	noecho();
	cbreak();

	menus = newwin(HEIGHT, WIDTH, yVal, xVal);
	keyboard(menus,TRUE);
	refresh();

	/*Main menu loop*/
	while(1)
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
			default:
				/*laugh at the users inadequacy*/
				break;
		}
		printMenu(menus,highlight);
		if(input != 0)
		{
			break;
		}
	}

	clrtoeol();
	refresh();
	getch();
	endwin();
	
	return 0;

}

void printMenu(WINDOW *menus,int highlight)
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
			mvprintw(menus,y,x, "%s",choices[i]);
			wattroff(menus,A_REVERSE);
		}
		else
		{
			mvprintw(menus,y,x,"%s",choices[i]);
			y++;
		}	
	}

}