all: autocomplete1 autocomplete2

autocomplete1: main1.c func.c func.h
	gcc -Wall -o autocomplete1 main1.c func.c

autocomplete2: main2.c func.c func.h sorting.c
	gcc -Wall -o autocomplete2 main2.c func.c sorting.c
