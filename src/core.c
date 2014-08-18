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
	addItemMenu("Write", generateAssemblyWrite);
	addItemMenu("Read", generateAssemblyRead);
	addItemMenu("Exec", generateAssemblyExec);
	addItemMenu("Exit", generateAssemblyExit);

	addItemMenu("Help", printHelp);
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

void generateAssemblyWrite()
{
	printf("ASM : write\n");
}

void generateAssemblyRead()
{
	printf("ASM : read\n");
}

void generateAssemblyExec()
{
	printf("ASM : exec\n");
}

void generateAssemblyExit()
{
	printf("ASM : exit\n");
}
