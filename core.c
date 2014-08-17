#include "core.h"

void shellcodeGenerator()
{
	printf("Not yet implemented.\n");
}

void shellcodeCreator()
{
	freeMenu();
	addItemMenu("Linux x86", shellcodeCreator_linux86);
	addItemMenu("Linux x86_x64", shellcodeCreator_linux64);
	addItemMenu("Windows x86", shellcodeCreator_windows86);
	addItemMenu("Windows x64", shellcodeCreator_windows64);
	addItemMenu("Back", setMainMenu);
	printMenu();
}

void shellcodeAnalyzer()
{
	printf("Not yet implemented.\n");
}

void help()
{
	printf("Not yet implemented.\n");
}

void about()
{
	printf(	"This tool was developped by M3nth0le.\n"
			"The project begin the Friday, 15 August.\n"
			"However the first release time is : xxx\n"
			"Version: 0.1\n");
}

void exitProgram()
{
	freeMenu();
	printf("See you soon !\n\n");
	exit(0);
}

void shellcodeCreator_linux86()
{
	freeMenu();
	addItemMenu("Write", generateAssembly);
	addItemMenu("Read", generateAssembly);
	addItemMenu("Exec", generateAssembly);
	addItemMenu("Exit", generateAssembly);
	addItemMenu("Help", generateAssembly);
	addItemMenu("Back", setMainMenu);
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
