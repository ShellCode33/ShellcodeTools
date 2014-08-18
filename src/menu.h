#ifndef MENU_H
#define MENU_H

#define MAX_ITEM_MENU 6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core.h"
#include "user.h"

typedef struct ItemMenu
{
	char* itemName;
	void (*func)();
} ItemMenu;

void *lastMenu;
void *currentMenu;
ItemMenu *menu[MAX_ITEM_MENU];
int itemCount;

void mainMenu();
void addItemMenu(char*, void*);
void printMenu();
void freeMenu();

void* getLastMenu();
void* getCurrentMenu();

#endif
