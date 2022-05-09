#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "managetime.h"


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
    return 1;
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

int selectMenu(){
    int select;
    printf("\n\n=================== HGU Babgo ===================\n");
    printf("===================   Menu    ===================\n\n");
    printf("        1.  밥고(팀플)시간 조회\n");
    printf("        2.  사용자 시간 추가\n");
    printf("        3.  사용자 시간 변경\n");
    printf("        4.  사용자 시간 삭제\n");
    printf("        5.  전체 사용자 시간 조회\n");
    printf("        6.  밥고(팀플) 시간 설정\n");
    printf("        7.  밥고 시간 / 사용자 시간 저장\n");
    printf("        0.  프로그램 종료\n\n");
    printf("메뉴를 선택하세요: ");
    scanf("%d",&select);
    return select;
}


void readTime(Time *t){
    int *pArr[7] = {t->mon, t->tue, t->wed, t->thu, t->fri, t->sat, t->sun};
    char *dArr[7] = {"월요일 :", "화요일 :", "수요일 :", "목요일 :", "금요일 :", "토요일 :", "일요일 :"};
    
    printf("사용자 : %s\n",t->name);
    if (t->type == 1) printf("밥고 목적\n");
    else printf("팀플 목적\n");
    for (int k = 0; k < 7; k++){
        printf("%s",dArr[k]);
        for (int j = 0; j < 10 ; j++){
            if (pArr[k][j] == -1) break;
            if (pArr[k][j] == -2) continue;
            printf(" %d ",pArr[k][j]);
            printf("교시 ");
        }
        printf("\n");    
    }
    printf("\n");
}

