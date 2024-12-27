// ***************************
// 電機一甲_413241350_郭靖書 
// ***************************
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

// 全域變數，用來記錄各課程的選課狀態。0 表示未選，1 表示已選。
int l1, l2, l3, l4 = 0; // l1: 計算機概論, l2: 微積分, l3: 電路學, l4: 電子學

// 函式宣告
void add_class(); // 加選系統
void del_class(); // 退選系統
void total(); // 列出總共已選擇科目


int main(void) {
    int model = 1; 

    while (model != 0) { // 當輸入 0 時，結束迴圈
        printf("---請選擇輸入1.加選 2.退選 <輸入0離開>---\n");
        scanf("%d", &model);

        
        switch (model) {
        case 1: // 加選
            add_class(); 
            total(); // 顯示目前已選課程
            break;

        case 2: // 退選
            del_class(); 
            total(); // 顯示目前已選課程
            break;

        case 0: // 離開
            break; 

        default : // 防呆處理
            printf("輸入錯誤，請重新輸入\n");
            total(); 
            break;
        }
    }

    printf("感謝您使用本系統\n");
    total(); // 程式結束前再次顯示已選課程

    system("pause"); 
    return 0; 
}



// 加選函式
void add_class() {
    int lesson; // 用於儲存使用者選擇的課程編號

    printf("請選擇要加選的課程\n");
    printf("<1>計算機概論\n");
    printf("<2>微積分\n");
    printf("<3>電路學\n");
    printf("<4>電子學\n");

    scanf("%d", &lesson);

    switch (lesson) {
    case 1: // 計算機概論
        if (l1 == 0) { // 若尚未選修
            if (l3 == 1) { 
                printf("衝堂，與電路學同一時段\n");
            }
            else if (l3 == 0) { // 若不衝堂
                printf("您目前所選擇的課程\n");
                printf("<1>計算機概論\n");
                l1 = 1; // 設定為已選修
            }
        }
        else if (l1 == 1) { // 若已選修
            printf("已選過此課程\n");
        }
        break;

    case 2: // 微積分，邏輯同計算機概論
        if (l2 == 0) {
            if (l4 == 1) {
                printf("衝堂，與電子學同一時段\n");
            }
            else if (l4 == 0) {
                printf("您目前所選擇的課程\n");
                printf("<2>微積分\n");
                l2 = 1;
            }
        }
        else if (l2 == 1) {
            printf("已選過此課程\n");
        }
        break;
    case 3: // 電路學，邏輯同計算機概論
        if (l3 == 0) {
            if (l1 == 1) {
                printf("衝堂，與計算機概論同一時段\n");
            }
            else if (l1 == 0) {
                printf("您目前所選擇的課程\n");
                printf("<3>電路學\n");
                l3 = 1;
            }
        }
        else if (l3 == 1) {
            printf("已選過此課程\n");
        }
        break;
    case 4: // 電子學，邏輯同計算機概論
        if (l4 == 0) {
            if (l2 == 1) {
                printf("衝堂，與微積分同一時段\n");
            }
            else if (l2 == 0) {
                printf("您目前所選擇的課程\n");
                printf("<4>電子學\n");
                l4 = 1;
            }
        }
        else if (l4 == 1) {
            printf("已選過此課程\n");
        }
        break;
    default: // 防呆處理
        printf("輸入錯誤，請重新輸入\n");
    }
}



// 退選函式
void del_class() {
    int lesson; // 用於儲存使用者選擇的課程編號

    printf("請選擇要退選的課程\n");
    if (l1 == 1) {
        printf("<1>計算機概論\n");
    }
    if (l2 == 1) {
        printf("<2>微積分\n");
    }
    if (l3 == 1) {
        printf("<3>電路學\n");
    }
    if (l4 == 1) {
        printf("<4>電子學\n");
    }

    scanf("%d", &lesson);

    switch (lesson) {
    case 1: // 計算機概論
        if (l1 == 1) { // 若已選修
            l1 = 0; // 設定為未選修
            printf("退選成功\n");
        }
        else if (l1 == 0) { // 若未選修
            printf("不能退選未選科目，請重新輸入\n");
        }
        break;

    case 2: // 微積分，邏輯同計算機概論
        if (l2 == 1) {
            l2 = 0;
            printf("退選成功\n");
        }
        else if (l2 == 0) {
            printf("不能退選未選科目，請重新輸入\n");
        }
        break;

    case 3: // 電路學，邏輯同計算機概論
        if (l3 == 1) {
            l3 = 0;
            printf("退選成功\n");
        }
        else if (l3 == 0) {
            printf("不能退選未選科目，請重新輸入\n");
        }
        break;

    case 4: // 電子學，邏輯同計算機概論
        if (l4 == 1) {
            l4 = 0;
            printf("退選成功\n");
        }
        else if (l4 == 0) {
            printf("不能退選未選科目，請重新輸入\n");
        }
        break;

    default: // 防呆處理
        printf("輸入錯誤，請重新輸入\n");
    }
}



// 顯示總共已選的課程
void total() {
    printf("\n您現在總共已經選擇的課程\n");

    if (l1 == 1) {
        printf("<1>計算機概論\n");
    }
    if (l2 == 1) {
        printf("<2>微積分\n");
    }
    if (l3 == 1) {
        printf("<3>電路學\n");
    }
    if (l4 == 1) {
        printf("<4>電子學\n");
    }

    printf("\n");
}
