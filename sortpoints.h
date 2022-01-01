#ifndef sortpoints_H
#define sortpoints_H
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/mman.h>
#include<sys/wait.h>
#include <stdio.h>
#include<signal.h>
#include <unistd.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct points{
int teamno;
int won;
int lost;
int draw;
int goals_scored;
int points;
};
extern void bsort(struct points *pointstable,int n);
#endif

