FLAGS = -std=c99 -Wall -pedantic -Iasset

#executeable
slcg.out: mainMenus.o
	gcc $(FLAGS) slcg.c mainMenus.o -lncurses -o slgc.out -lm

#.o compilation
mainMenus.o: src/mainMenus.c
	gcc $(FLAGS) -c -lncurses src/mainMenus.c 


clean:
	rm *.o 