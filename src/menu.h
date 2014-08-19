#ifndef MENU_H
#define MENU_H

#define MAX_ITEM_MENU 8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "core.h"
#include "user.h"

typedef struct ItemMenu
{
	char* itemName;
	void (*func)();
} ItemMenu;

void *lastMenu; //Used to "Back" to another menu
void *currentMenu; //Used for the "Help", for know what help needs to be print
ItemMenu *menu[MAX_ITEM_MENU];
int itemCount;

void mainMenu();
void addItemMenu(char*, void*);
void printMenu();
void freeMenu();

void* getLastMenu();
void* getCurrentMenu();

#endif
