#include "core.h"

void shellcodeGenerator()
{
	printf("Not yet implemented.\n");
}

void shellcodeCreator()
{
	lastMenu = mainMenu;
	currentMenu = shellcodeCreator;

	freeMenu();
	addItemMenu("Linux x86", shellcodeCreator_linux86);
	addItemMenu("Linux x86_x64", shellcodeCreator_linux64);
	addItemMenu("Windows x86", shellcodeCreator_windows86);
	addItemMenu("Windows x64", shellcodeCreator_windows64);
	addItemMenu("Help", printHelp);
	addItemMenu("Back", lastMenu);
	printMenu();
}

void shellcodeAnalyzer()
{
	printf("Not yet implemented.\n");
}

void about()
{
	printf(	"This tool was developped by M3nth0le.\n"
			"The project began the Friday, 15 August.\n"
			"GitHub : https://github.com/M3nth0le/ShellcodeTools/\n"
			"Ascii Art : http://patorjk.com/software/taag/\n"
			"\nVersion: 0.1\n");
}

void exitProgram()
{
	freeMenu();
	printf("See you soon !\n\n");
	exit(0);
}

void shellcodeCreator_linux86()
{
	lastMenu = shellcodeCreator;
	currentMenu = shellcodeCreator_linux86;

	freeMenu();
	addItemMenu("Write", processInstruction);
	addItemMenu("Read", processInstruction);
	addItemMenu("Exec", processInstruction);
	addItemMenu("Exit", processInstruction);

	addItemMenu("Help", printHelp);
	addItemMenu("Look Assembly", printFileContent);
	addItemMenu("Create Shellcode", createShellcode);
	addItemMenu("Back", lastMenu);
	printMenu();
}

void shellcodeCreator_linux64()
{
	printf("Not yet implemented.\n");
}

void shellcodeCreator_windows86()
{
	printf("Not yet implemented.\n");
}

void shellcodeCreator_windows64()
{
	printf("Not yet implemented.\n");
}

/*
void createAssembly()
{
	if(startAssembly == NULL)
		startAssembly = (char*) calloc(30, sizeof(char));

	FILE *file = fopen(FILENAME, "r");
	
	if(!file)
	{
		file = fopen(FILENAME, "w");

		//Generate Assembly file
		fputs("section .text\n", file);
		fputs("global _start\n\n", file);
		fputs("_start:\n", file);

		fclose(file);
		file = NULL;
	}

	else
	{
		fclose(file);
		printf("File already exists\n");
	}
}
*/

void printFileContent()
{
	FILE *file = fopen(FILENAME, "r");
	
	if(file)
	{
		printf("------ Assembly ------\n");

		char *line = (char*) calloc(600, sizeof(char));

		while(fgets(line, 600, file) != NULL)
			printf("%s", line);

		free(line);
		line = NULL;

		printf("----------------------\n");

		fclose(file);
		file = NULL;
	}

	else
		printf("Please choose an instruction before.\n");
}

void createShellcode()
{
	printf("Creating...\n");
}

/*
void generateAssemblyWrite()
{
	createAssembly();
	canCatch = 0;

	char *text = (char*) calloc(500, sizeof(char));
	char *dest;

	while(1)
	{
		printf("[text] : ");

		fgets(text, 500, stdin);

		printf("text: %s\n", text);

		if(*text != '\n')
			break;
	}

	while(1)
	{
		printf("[destination] (ex: stdin, stdout, stderr, or a filename) : ");

		fgets(text, 500, stdin);

		printf("text: %s\n", text);

		if(*text != '\n')
			break;
	}

	FILE *file = fopen(FILENAME, "a");
	
	if(file)
	{
		fputs("\n\t; write\n", file);
		fputs("\tmov eax, 4\n", file);
		fputs("\tmov ebx, 1\n", file);
		fputs("\tmov ecx, offset string\n", file);
		fputs("\tmov edx, stringSize\n", file);
		fputs("\tint 0x80\n", file);
		
		fclose(file);
		file = NULL;
	}

	else
		printf("Erreur ?\n");

	printf("ASM : write\n");
	canCatch = 1;
}
*/

void processInstruction()
{
	canCatch = 0;

	Options *options = (Options*) malloc(sizeof(Options));

	char *fileName;
	char *text;
	char *varName;

	switch(userInput)
	{
		case 1:		//write
			text = (char*) calloc(500, sizeof(char));
			fileName = (char*) calloc(500, sizeof(char));

			do
			{
				printf("[text] : ");
				fgets(text, 500, stdin);
			} while(*text == '\n');

			do
			{
				printf("[destination] (ex: stdin, stdout, stderr, file, or varName) : ");
				fgets(fileName, 500, stdin);
			} while(*fileName == '\n');

			options->arg1 = text;
			options->arg2 = fileName;
			addInstruction("write", options);
			break;

		case 2:		//read
			varName = (char*) calloc(500, sizeof(char));
			fileName = (char*) calloc(500, sizeof(char));

			do
			{
				printf("[varName] (where will be stored the content) : ");
				fgets(varName, 500, stdin);
			} while(*text == '\n');

			do
			{
				printf("[source] (ex: stdin, stdout, stderr, or a filename) : ");
				fgets(fileName, 500, stdin);
			} while(*fileName == '\n');

			options->arg1 = text;
			options->arg2 = fileName;
			addInstruction("read", options);
			break;

		case 3:		//exec
		
			break;

		case 4:		//exit
			//Options *options = (Options*) malloc(sizeof(Option));
			//options->integer = returnValue;
			break;
	}

	canCatch = 1;
}

Instruction* addInstruction(char *instructionName, Options *options)
{
	printf("Add instruction %s...\n", instructionName);
	Instruction *instruction = (Instruction*) malloc(sizeof(Instruction));
	
	if(firstInstruction == NULL)
		firstInstruction = instruction;

	instruction->instructionName = instructionName;
	instruction->next = NULL;

	if(lastInstruction != NULL)
		lastInstruction->next = instruction;

	lastInstruction = instruction;
	return instruction;
}

void freeInstructions()
{
	Instruction *instruction = firstInstruction;

	while(instruction != NULL)
	{
		free(instruction->instructionName);
		instruction->instructionName = NULL;

		if(instruction->options->arg1 != NULL)
		{
			free(instruction->options->arg1);
			instruction->options->arg1 = NULL;		
		}

		if(instruction->options->arg2 != NULL)
		{
			free(instruction->options->arg2);
			instruction->options->arg2 = NULL;		
		}

		free(instruction->options);
		instruction->options = NULL;

		Instruction *backup = instruction;
		instruction = instruction->next;
		free(backup);
		backup = NULL;
	}
}
