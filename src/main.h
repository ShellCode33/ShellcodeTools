#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

#include "core.h"
#include "user.h"
#include "menu.h"

void init();
void catchCtrl(int dummy);

#endif
