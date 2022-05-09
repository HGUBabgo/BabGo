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

void listTime(Time **t,int count){
    for(int i = 0; i < count; i++){
        if(t[i]->type == -1) continue;
        printf("%d번 ",i+1);
        readTime(t[i]);
    }
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

int setPurpose(Time **t,int count, Time **p,int p_count){
    int sel, set, j = 0;
    int timeList[20] = {-1};
    char str[100];
    printf("설정할 시간 약속을 정하십시오:\n");
    printf("1.  밥고\n");
    printf("2.  팀플\n");
    printf("입력 : ");
    scanf("%d",&sel);
    for (int i = 0; i < count; i++){
        if(t[i]->type == -1) continue;
        if(t[i]->type != sel) continue;
        printf("%d번 ",i+1);
        readTime(t[i]);
        timeList[j] = i;
        j++;
    }
    printf("설정할 방식을 입력하십시오:\n");
    printf("1. 사용자 전부\n");
    printf("2. 사용자 선택\n");
    printf("입력 : ");
    scanf("%d",&set);
    getchar();
    if (set == 1){
        printf("\n\n가능한 시간대 출력 완료\n");
        settingBaseTime(p[p_count],t[timeList[0]]);
        for (int j = 1; j < sizeof(timeList) / sizeof(int); j++){
            if (timeList[j] == 0) break;
            settingTime(p[p_count],t[timeList[j]]);
        }
        readTime(p[p_count]);
    }
    else if (set == 2) {
        memset(timeList, -1, 20*sizeof(timeList[0]));
        char str[100];
        printf("포함할 사용자의 번호를 선택하세요\n");
        printf("띄어쓰기로 번호를 입력할 것 EX)1 3 4 \n");
        printf("입력 :");
        gets(str);
        char *ptr = strtok(str, " ");
        int i = 0;
        while (ptr != NULL)
        {
            timeList[i] = atoi(ptr) - 1;
            ptr = strtok(NULL, " ");
            i+=1;
        }
        printf("\n\n가능한 시간대 출력 완료\n");
        settingBaseTime(p[p_count],t[timeList[0]]);
        for (int j = 1; j < sizeof(timeList) / sizeof(int); j++){
            if (timeList[j] == -1) break;
            settingTime(p[p_count],t[timeList[j]]);
        }
        readTime(p[p_count]);
    }
    p_count = makePurpose(p,p_count);
    printf("\n만들어진 시간 약속\n");
    readTime(p[p_count]);
    return p_count + 1;
}

int settingBaseTime(Time *p, Time *t){
    int *tArr[7] = {t->mon, t->tue, t->wed, t->thu, t->fri, t->sat, t->sun};
    int *pArr[7] = {p->mon, p->tue, p->wed, p->thu, p->fri, p->sat, p->sun};
    for(int i = 0; i < 7; i++) for (int j = 1; j < 11; j++) pArr[i][j-1] = j;
    memcpy(p->name,t->name,sizeof(t->name));
    p->type = t->type;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 10 ; j++){
            for (int k = 0; k < sizeof(tArr[i]); k++) {
                if (pArr[i][j] == -1) break;
                if (pArr[i][j] == tArr[i][k]) pArr[i][j] = -2;
            }
        }
    }
    return 0;
}

int settingTime(Time *p, Time *t){
    char * getname;
    int *tArr[7] = {t->mon, t->tue, t->wed, t->thu, t->fri, t->sat, t->sun};
    int *pArr[7] = {p->mon, p->tue, p->wed, p->thu, p->fri, p->sat, p->sun};
    strcat(p->name,", ");
    strcat(p->name,t->name);
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < sizeof(tArr[i]); k++){
                if (pArr[i][j] == -1) break;
                if (pArr[i][j] == tArr[i][k]) {
                    pArr[i][j] = -2;
                    break;
                }
            }
        }
    }
return 0;
}

int makePurpose(Time **p,int p_count){
    char *type;
    if (p[p_count]->type == 1) type = "밥고";
    else type = "팀플";
    memcpy(p[p_count+1]->name,p[p_count]->name,sizeof(p[p_count]->name));
    p[p_count+1]->type = p[p_count]->type;
    printf("\n원하는 %s시간을 입력하십시오.\n",type);
    printf("띄어쓰기로 번호를 입력할 것(없다면 빈칸으로 엔터) EX)1 3 4\n");
    setTimeDay(p[p_count+1]);
    return p_count + 1;
}

void listPurpose(Time **p,int p_count){
    int j = 1;
    for(int i = 1; i < p_count; i+=2){
        if(p[i]->type == -1) continue;
        printf("\n%d번 약속 \n",j);
        readTime(p[i]);
        j++;
    }
}

void saveData(Time **t,int count,Time **p,int p_count){
    savePurpose(p,p_count);
    saveUserData(t,count);
    printf("저장이 완료 되었습니다.");
}

int savePurpose(Time **p,int p_count){
    FILE *fp;
    fp = fopen("time.txt", "wt");
    for(int k = 1; k < p_count; k+=2){
        int *pArr[7] = {p[k]->mon, p[k]->tue, p[k]->wed, p[k]->thu, p[k]->fri, p[k]->sat, p[k]->sun};
        fprintf(fp,"%s\n",p[k]->name);
        fprintf(fp,"%d\n",p[k]->type);
        for(int i = 0; i < 7; i++){
            int check = 0;
            if (pArr[i][check] == -1) {
                fprintf(fp,"%d\n",pArr[i][check]);
                continue;
            }
            while(1){
                if (pArr[i][check+1] == -1) fprintf(fp,"%d\n",pArr[i][check]);
                else fprintf(fp,"%d ",pArr[i][check]);
                check+=1;
                if (pArr[i][check] == -1) break;
        }
    }
    }
    fprintf(fp,"%s","end");
    fclose(fp);
    return 0;
}

int saveUserData(Time **t,int count){
    FILE *fp;
    fp = fopen("user.txt", "wt");
    for(int k = 0; k < count; k++){
        if (t[k]->type == -1) continue;
        int *tArr[7] = {t[k]->mon, t[k]->tue, t[k]->wed, t[k]->thu, t[k]->fri, t[k]->sat, t[k]->sun};
        fprintf(fp,"%s\n",t[k]->name);
        fprintf(fp,"%d\n",t[k]->type);
        for(int i = 0; i < 7; i++){
            int check = 0;
            if (tArr[i][check] == -1) {
                fprintf(fp,"%d\n",tArr[i][check]);
                continue;
            }
            while(1){
                if (tArr[i][check+1] == -1) fprintf(fp,"%d\n",tArr[i][check]);
                else fprintf(fp,"%d ",tArr[i][check]);
                check+=1;
                if (tArr[i][check] == -1) break;
            }
        }
    }
    fprintf(fp,"%s","end");
    fclose(fp);
    return 0;
}

int loadUserData(Time **t){
    int i = 0;
    char line[200], *result;
    FILE *fp, *check = NULL;
    if (check = fopen("user.txt","rt"))
    {
       fp = fopen("user.txt","rt");
       while (1)
       {
            if((result = fgets(line, 256, fp)) != NULL) {
            if(strcmp(result,"end") == 0) break;
            strcpy(t[i]->name,result);
            }
            if ((result = fgets(line, 256, fp)) != NULL) t[i]->type = atoi(result);
            int *tArr[7] = {t[i]->mon, t[i]->tue, t[i]->wed, t[i]->thu, t[i]->fri, t[i]->sat, t[i]->sun};
            for (int j = 0; j < 7 ; j ++)
            {
                if ((result = fgets(line, 256, fp)) != NULL) {
                    char *ptr = strtok(result, " ");
                    int k = 0;
                    while (ptr != NULL)
                    {
                        if(atoi(ptr) == -1) break;
                        tArr[j][k] = atoi(ptr);
                        ptr = strtok(NULL, " ");
                        k+=1;
                    }
                    tArr[j][k] = -1;
                }
            }
            i++;
        }
        fclose(fp);
        printf("=============== 사용자 로딩 완료 ===============\n");
        return i;
    }
    else printf("================= 사용자 파일 없음 =================\n");
    return 0;
}

int loadPurposeData(Time **p){
    int i = 1;
    char line[200], *result;
    FILE *fp, *check = NULL;
    if (check = fopen("time.txt","rt"))
    {
       fp = fopen("time.txt","rt");
       while (1)
       {
            if((result = fgets(line, 256, fp)) != NULL) {
            if(strcmp(result,"end") == 0) break;
            strcpy(p[i]->name,result);
            }
            if ((result = fgets(line, 256, fp)) != NULL) p[i]->type = atoi(result);
            int *pArr[7] = {p[i]->mon, p[i]->tue, p[i]->wed, p[i]->thu, p[i]->fri, p[i]->sat, p[i]->sun};
            for (int j = 0; j < 7 ; j ++)
            {
                if ((result = fgets(line, 256, fp)) != NULL) {
                    char *ptr = strtok(result, " ");
                    int k = 0;
                    while (ptr != NULL)
                    {
                        if(atoi(ptr) == -1) break;
                        pArr[j][k] = atoi(ptr);
                        ptr = strtok(NULL, " ");
                        k+=1;

                    }
                    pArr[j][k] = -1;
                }
            }
            i +=2;
        }
        fclose(fp);
        printf("================= 약속 로딩 완료 =================\n");
        return i;
    }
    else printf("================= 약속 파일 없음 =================\n");
    return 0;
}
