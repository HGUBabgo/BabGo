# include "time.h"

int setTimeDay(Time *t){

    int *pArr[7] = {t->mon, t->tue, t->wed, t->thu, t->fri, t->sat, t->sun};
    char *dArr[7] = {"월요일 :", "화요일 :", "수요일 :", "목요일 :", "금요일 :", "토요일 :", "일요일 :"};
    
    for (int j = 0; j < 7 ; j ++)
    {
        printf("%s",dArr[j]);
        char str[100];
        gets(str);
        char *ptr = strtok(str, " ");
        int i = 0;
        while (ptr != NULL)
        {
            pArr[j][i] = atoi(ptr);
            ptr = strtok(NULL, " ");
            i+=1;
        }
        pArr[j][i] = -1;

    }
    return 0;
}


int createTime(Time *t){
    printf("사용자 이름은? : ");
    scanf("%s",t->name);
    printf("밥고: 1 / 팀플: 2 : ");
    scanf("%d",&t->type);
    getchar();
    printf("띄어쓰기로 시간을 입력할 것 EX)2 3 4\n");
    setTimeDay(t);
    printf("=================== 저장 완료 ===================\n");
    return 0;
}

int updateTime(Time **t, int count){
    int s;
    listTime(t,count);
    printf("수정할 사용자 데이터의 번호를 입력하십시오 :");
    scanf("%d",&s);
    getchar();
    printf("사용자 이름은? : ");
    scanf("%s",t[s-1]->name);
    printf("밥고: 1 / 팀플: 2 : ");
    scanf("%d",&t[s-1]->type);
    getchar();
    printf("띄어쓰기로 시간을 입력할 것 EX)2 3 4\n");
    setTimeDay(t[s-1]);
    printf("=================== 변경 완료 ===================\n");
    return 0;
}

int deleteTime(Time **t, int count){
    int s,ans ;
    listTime(t,count);
    printf("삭제할 사용자 데이터의 번호를 입력하십시오 :");
    scanf("%d",&s);
    getchar();
    printf("정말로 삭제 하시겠습니까? 예(1) / 아니오(2) :");
    scanf("%d",&ans);
    if (ans == 1) t[s-1]->type = -1;
    else if (ans == 2) return 0;
    else {
        printf("잘못된 입력입니다. 메뉴로 돌아갑니다.");
        return 0;
    }
    count-=1;
    return 0;
}

void readTime(Time *t){

    int *pArr[7] = {t->mon, t->tue, t->wed, t->thu, t->fri, t->sat, t->sun};
    char *dArr[7] = {"월요일 :", "화요일 :", "수요일 :", "목요일 :", "금요일 :", "토요일 :", "일요일 :"};
    
    printf("사용자 : %s\n",t->name);
    if (t->type == 1) printf("밥고 목적\n");
    else printf("팀플 목적\n");
    for (int k = 0; k < 7; k++){
        printf("%s",dArr[k]);
        for (int j = 0; j < sizeof(pArr[k]) ; j++){
            if (pArr[k][j] == -1) break;
            printf(" %d ",pArr[k][j]);
            printf("교시 ");
        }
        printf("\n");    
    }
    printf("\n");
}

