#ifndef MENU_H
#define MENU_H

#define MAX_ITEM_MENU 6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core.h"

typedef struct ItemMenu
{
	char* itemName;
	void (*func)();
} ItemMenu;

ItemMenu *menu[MAX_ITEM_MENU];
int itemCount;

void setMainMenu();
void addItemMenu(char*, void*);
void printMenu();
void freeMenu();

#endif
