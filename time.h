#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	char name[30];
	int type;
	int sun[20];
	int mon[20];
	int tue[20];
	int wed[20];
	int thu[20];
	int fri[20];
	int sat[20];
} Time;

int setTimeDay(Time *t);
int createTime(Time *t);
void readTime(Time *t);
int updateTime(Time **t,int count);
int deleteTime(Time **t,int count);
