#include "main.h"

int main(int argc, char **argv)
{
	printf("This is a test.\n");
	init();

	int userInput;

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
	//cleanFiles(); //TODO : remove all asm files
	signal(SIGINT, catchCtrl);
	itemCount = 0;
	mainMenu();
}

void catchCtrl(int dummy)
{
	write(STDOUT_FILENO, "\nchoice> ", 9); //KeyBoardInterrupt
}
