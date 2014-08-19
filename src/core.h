#ifndef CORE_H
#define CORE_H

#define FILENAME "shellcode.asm"
#define MAX_VAR 20

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "user.h"
#include "main.h"

typedef struct Variable
{
	char *varName;
	char *content;
} Variable;

Variable vars[MAX_VAR];

typedef struct Options
{
	char *arg1;
	char *arg2;

	int integer;
	
} Options;

typedef struct Instruction Instruction;
struct Instruction
{
	char *instructionName;
	Instruction *next;
	Options *options;
	
};

Instruction *firstInstruction;
Instruction *lastInstruction;

void processInstruction();
Instruction* addInstruction(char*, Options*);
void freeInstructions();

//menu functions
void shellcodeGenerator();
void shellcodeCreator();
void shellcodeAnalyzer();
void help();
void about();
void exitProgram();

//submenu functions
void shellcodeCreator_linux86();
void shellcodeCreator_linux64();
void shellcodeCreator_windows86();
void shellcodeCreator_windows64();

void createAssembly();
void printFileContent();
void createShellcode();

//instructions
void generateAssemblyWrite();
void generateAssemblyRead();
void generateAssemblyExec();
void generateAssemblyExit();
#endif
