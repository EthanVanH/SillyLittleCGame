#include <stdlib.h>
#include "mainMenus.h"


int main(int argc, char const *argv[])
{
	int i;

	i = mainMenu();

	switch(i)
	{
		case 1:
			/*Play game*/
			break;
		case 2:
			/*Load game*/
			break;
		case 3:
			/*Stats*/
			break;
		case 4:
			/*Options*/
			break;
		default:
			/*quit on 5*/
			break;
	}
	return 0;
}