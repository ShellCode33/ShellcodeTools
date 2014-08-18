#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "user.h"

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

//instructions
void generateAssemblyWrite();
void generateAssemblyRead();
void generateAssemblyExec();
void generateAssemblyExit();
#endif
