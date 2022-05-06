# include "time.h"

int setTimeDay(Time *t){

	int *pArr[7] = {t->mon, t->tue, t->wed, t->thu, t->fri, t->sat, t->sun};
	
	for (int j = 0; j < 7 ; j++)
	{
		char str[100];
		gets(str);
		char *ptr = strtok(str," ");
		int i = 0;
		while (ptr != NULL)
		{
			pArr[j][i] = atoi(ptr);
			ptr = strtok(NULL," ");
			i+=1;
		}
		pArr[j][i];
	}
	return 0;
}


int createTime(Time *t){
        char str[100];
        printf("사용자 이름은? : ");
        scanf("%s",t->name);
        printf("밥고: 1 / 팀플: 2 : ");
        scanf("%d",&t->type);
        getchar();
        printf("띄어쓰기로 시간을 입력할 것 EX)2 3 4\n");
        setTimeDay(t);
        return 0;
}
