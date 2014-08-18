#include "user.h"

int getUserSelection()
{
	char *buf = (char*) calloc(3, sizeof(char)); //3 bytes, the first is the choise, the second, is to detect if user enter a number which is bigger than 9, (with 2 digits, like 10, 11, 12...) and the last one, is for the null byte.
	fgets(buf, 3, stdin);

	if(*buf != '\n' && *(buf+1) != '\n') //Need to test the first byte too, to see if the user don't do just "enter"
		flushStdin();

	strtok(buf, "\n"); //delete \n from string

	int userInput = 0;

	if(isdigit(*buf) && (isdigit(*(buf+1)) || *(buf+1) == '\0')) //Test if it's a valid number
		userInput = atoi(buf); //Convert string to integer

	free(buf);
	buf = NULL;
	return userInput;
}

void flushStdin()
{
	char c;

	do
	{
		c = getchar();		
	} while(c != EOF && c != '\n');
}

void printHelp()
{
	void *func = getCurrentMenu();
	
	if(func == mainMenu)
	{
		printf("Help du main menu\n");
	}

	else if(func == shellcodeCreator)
	{
		printf("Help du Shellcode Creator menu\n");
	}

	else if(func == shellcodeCreator_linux86)
	{
		printf("Help du Shellcode Creator Linux x86 menu\n");
	}
}
