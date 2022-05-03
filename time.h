#include <stdio.h>
#include <string.h>

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

int createTime(Time *t);
void readTime(Time *t);
int updateTime(Time *t);
int deleteTime(Time *t);
