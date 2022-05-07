#include "manager.h"

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
    printf("        7.  날짜로 밥고(팀플) 가능 사용자 조회\n");
    printf("        8.  시간으로 밥고(팀플) 가능 사용자 조회\n");
    printf("        9.  밥고에 해당하는 사용자 조회\n");
    printf("        10. 요일별 밥고(팀플) 가능 사용자 조회\n");
    printf("        11. 사용자의 요일별 밥고(팀플) 조회\n");
    printf("        0.  프로그램 종료\n\n");
    printf("메뉴를 선택하세요: ");
    scanf("%d",&select);
    return select;
}

void listTime(Time **t,int count){
    for(int i = 0; i < count; i++){
        if(t[i]->type == -1) continue;
        printf("%d번 ",i+1);
        readTime(t[i]);
    }
}

void listPurpose(Time *t, int count){

}

void searchTime(Time *t, int count){

}

void selectDataNum(Time *t, int count){

}

void saveData(Time *t, int count){

}

int loadData(Time *t){

}
