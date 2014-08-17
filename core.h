#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

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
#endif
