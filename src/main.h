#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <dirent.h>

#include "core.h"
#include "user.h"
#include "menu.h"

void init();
void catchCtrl(int dummy);
void cleanFiles();

int canCatch;
int userInput;

#endif
