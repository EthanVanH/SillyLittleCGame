#ifndef gamePlayDef
#define gamePlayDef
#include <ncurses.h>
/*
 * start game should be the only function called from main and or used in any other sense
 * all other functions defined in this file are for local use only 
 * 
 * initGame functions as a wrapper for the functions neeeded to begin
 * a call to start game will
 *	1. Create the gameplay area
 *	2. Draw the gameplay area
 *	3. Create the list of "invaders"
 * 	4. Create any other necessary constructs
 * takes no arguments
 * returns -1 on failure
 * return 0 on success
*/
extern void initGame();

/* prepScreen
 * This function is responsible for creating an ncurses window that meets specifications as defined in settings
 * retruns a ncurses Window pointer on success
 * returns -1 on failure
*/
extern *WINDOW prepScreen();

/* drawScreen
 * This function is responsible for drawing the game screen in the terminal
 *	Requires an ncurses window 
 *	Returns 0 on success
 * Returns -1 on failures
*/
extern void drawScreen(*WINDOW gameArea);

/*
 * Need to edit and include our list structture also so we can have a linked list here to represent the invaders 
*/

#endif