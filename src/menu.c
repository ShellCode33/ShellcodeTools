#include "menu.h"

void mainMenu()
{
	lastMenu = NULL;
	currentMenu = mainMenu;

	freeMenu(); //free just to "Back" from core.c, useless for main.c

	addItemMenu("Shellcode Generator", shellcodeGenerator);
	addItemMenu("Shellcode Creator", shellcodeCreator);
	addItemMenu("Shellcode Analyzer", shellcodeAnalyzer);
	addItemMenu("Help", printHelp);
	addItemMenu("About", about);
	addItemMenu("Exit", exitProgram);

	printMenu();
}

void addItemMenu(char *itemName, void *func)
{
	if(strlen(itemName) > 49)
	{
		printf("Item name too long.\n");
		exit(1);
	}

	if(itemCount+1 > MAX_ITEM_MENU)
	{
		printf("Too much item.\n");
		exit(1);
	}

	menu[itemCount] = (ItemMenu*) malloc(sizeof(ItemMenu));

	menu[itemCount]->itemName = (char*) calloc(50, sizeof(char));
	strcpy(menu[itemCount]->itemName, itemName);

	menu[itemCount]->func = func;
	itemCount++;
}

void printMenu()
{
	#ifdef WIN32

	system("cls");

	#elif defined (linux)

	system("clear");

	#else

	#error your platform is not supported

	#endif

	char intro[] =

"  ________.__           .__  .__                   .___      \n"
" /   _____|  |__   ____ |  | |  |   ____  ____   __| _/____  \n"
" \\_____  \\|  |  \\_/ __ \\|  | |  | _/ ___\\/  _ \\ / __ _/ __ \\ \n"
" /        |   Y  \\  ___/|  |_|  |_\\  \\__(  <_> / /_/ \\  ___/ \n"
"/_______  |___|  /\\___  |____|____/\\___  \\____/\\____ |\\___  >\n"
"        \\/     \\/     \\/___________    \\/     .__   \\/    \\/ \n"
"                        \\__    _______   ____ |  |   ______  \n"
"                          |    | /  _ \\ /  _ \\|  |  /  ___/  \n"
"                          |    |(  <_> (  <_> |  |__\\___ \\   \n"
"                          |____| \\____/ \\____/|____/____  >  \n"
"                                                        \\/   \n\n"
"----------  Menu  ----------\n";

	printf("%s", intro);

	int i;
	int newLine = 0;
	for(i = 0; i < itemCount; i++)
	{
		if(!newLine && (strcmp(menu[i]->itemName, "Back") == 0 || strcmp(menu[i]->itemName, "Help") == 0))
		{
			printf("\n");
			newLine = 1;
		}

		printf("  %i/ %s\n", i+1, menu[i]->itemName);
	}

	printf("----------------------------\n\n");
}

void freeMenu()
{
	int i;
	for(i = 0; i < itemCount; i++) //free menus
	{
		free(menu[i]->itemName);
		menu[i]->itemName = NULL;

		menu[i]->func = NULL;

		free(menu[i]);
		menu[i] = NULL;
	}

	itemCount = 0;
}

void* getLastMenu()
{
	return lastMenu;
}

void* getCurrentMenu()
{
	return currentMenu;
}
