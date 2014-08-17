#include "main.h"

int main(int argc, char **argv)
{
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
	itemCount = 0;
	setMainMenu();
}
