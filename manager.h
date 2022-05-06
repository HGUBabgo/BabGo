#include "time.h"

int selectMenu();
void listTime(Time **t, int count);
void listPurpose(Time *t, int count);
void searchTime(Time *t, int count);
void selectDataNum(Time *t, int count);
void saveData(Time *t, int count);
int loadData(Time *t);
