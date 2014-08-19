#include "main.h"

int main(int argc, char **argv)
{
	init();

	while(1)
	{
		printf("choice> ");
		userInput = getUserSelection();

		if(userInput <= 0 || userInput > itemCount)
			printf("Choice unexpected.\n");

		else
			menu[userInput-1]->func();

		printf("\n");
	}

	return 0;
}

void init()
{
	cleanFiles();
	signal(SIGINT, catchCtrl);

	itemCount = 0;
	canCatch = 1;
	firstInstruction = NULL;
	lastInstruction = NULL;

	mainMenu();
}

void catchCtrl(int dummy)
{
	if(canCatch)
	{
		mainMenu();
		write(STDOUT_FILENO, "CTRL+C: Go to the main menu.\nchoice> ", 37); //KeyBoardInterrupt
	}

	else
		write(STDOUT_FILENO, "\b\b  \b\b", 6); //Delete ^C
}

void cleanFiles()
{
	DIR *d = opendir(".");
	struct dirent *dir;

	while ((dir = readdir(d)) != NULL)
	{
		char *asmFile = strcasestr(dir->d_name, ".asm"); //search asm extenssion to delete it
		
		if(asmFile != NULL)
		{		
			if(strlen(asmFile) == 4)//We test if the length string (pointer) returned by strcasestr is 4 (because strlen(".asm") == 4 )
				remove(dir->d_name);
		}
	}

	closedir(d);
}
