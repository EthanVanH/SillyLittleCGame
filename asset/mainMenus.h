#ifndef menusused
#define menusused
#include <ncurses.h>


/*This function is a wrapper for all menus outside of the main game
* This function should only be called from main and only be called once
* Requires no arguments on call
* Returns an integer representing user choice
* 	0:quit
*	1: Play
*	2: **
*	3: **
*/
extern int mainMenu();

/* This function is responsible for updating the information displayed on the screen
* The arguments are the window to be updated and an integer representing which menu choice is highlighted
* void return
*/
extern void printMenu(WINDOW *menus,int highlight);

#endif
