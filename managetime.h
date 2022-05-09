#include <stdio.h>

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

int selectMenu();
void listTime(Time **t,int count);
void listPurpose(Time **p,int p_count);
void saveData(Time **t,int count,Time **p,int p_count);
int loadUserData(Time **t);
int loadPurposeData(Time **p);
int createTime(Time *t);
void readTime(Time *t);
int updateTime(Time **t,int count);
int deleteTime(Time **t,int count);
int setTimeDay(Time *t);
int setPurpose(Time **t,int count,Time **p,int p_count);
int settingBaseTime(Time *p, Time *t);
int settingTime(Time *p, Time *t);
int makePurpose(Time **p,int p_count);
int savePurpose(Time **p,int p_count);
int saveUserData(Time **t,int count);
