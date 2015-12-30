#ifndef structuresDefined
#define structuresDefined

/*This is the basic structure for our space invaders, health is a value for 
* how long it will stay on the feild and image is the character used to represent it 
* on the ncurses terminal
*/
typedef struct Invader
{
	int health;
	char image;
} Invader;

/*This is a simple List structure of invaders used to print to screen one at a time taken from our data structure library*/
/*Only change is definition of item, which is now defined as an INvader*/
typedef Invader Item;

typedef struct ListNodeTag {
	Item item;
	struct ListNodeTag *next;
} ListNode;

typedef struct {
	int size;
	ListNode *first;
} List;
#endif