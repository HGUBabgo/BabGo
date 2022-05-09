#include "managetime.h"

int main (void){
    Time *t[20] = {0, };
    for (int i = 0; i < 20; i++){
        t[i] = (Time *)malloc(sizeof(Time));
    }
    Time *p[20] = {0, };
    for (int i = 0; i < 20; i++){
        p[i] = (Time *)malloc(sizeof(Time));
    }
    int sel;
    int count,p_count;
    count = loadUserData(t);
    p_count = loadPurposeData(p);
    while(1)
    {
        sel = selectMenu();

        if (sel == 0) {
            for (int i = 0; i < sizeof(t) / sizeof(Time); i++) {
                free(t[i]);
                free(p[i]);
            }
            printf("프로그램이 종료되었습니다.");
            break;
        }
        else if (sel == 1) listPurpose(p,p_count);
        else if (sel == 2) count += createTime(t[count]);
        else if (sel == 3) updateTime(t,count);
        else if (sel == 4) deleteTime(t,count);
        else if (sel == 5) listTime(t,count);
        else if (sel == 6) p_count = setPurpose(t,count,p,p_count);
        else if (sel == 7) saveData(t,count,p,p_count);
        else printf("\nwrong input. try it agian.\n");
    }
    return 0;

}
