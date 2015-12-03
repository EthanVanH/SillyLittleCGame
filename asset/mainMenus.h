#ifndef menusused
#define menusused

#define WIDTH 30
#define HEIGHT 30

/*Variables needed by following functions, changes to them allow easy menu manipulation*/
char *choices[] = {
	"Play"
	"Load"
	"Stats"
	"Options"
	"Exit"
};
int menuChoices = sizeof(choices)/ sizeof(char*);


/*This function is a wrapper for all menus outside of the main game
* This function should only be called from main and only be called once
* Requires no arguments on call
* Returns an integer representing user choice
* 	0:quit
*	1: Play
*	2: **
*	3: **
*/
int mainMenu();

/* This function is responsible for updating the information displayed on the screen
* The arguments are the window to be updated and an integer representing which menu choice is highlighted
* void return
*/
void printMenu(WINDOW *menus,int highlight);

#endif
