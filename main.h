#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int exec_mgr(char **argv);
char *find_cmd(char *incommand);
int executor(char *my_args[]);
int free_me(char *argv);
int free_my_long(long *argv);

#endif
