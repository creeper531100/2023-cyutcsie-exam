#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main() {
    FILE* file = fopen("123.txt", "r+");

    int month;
    int day;

    fscanf(file, "%d %d", &month, &day);
    printf("%d %d\n", month, day);

    /*
     * 宣告一個長度為 13 的整數陣列 "mons"，用來儲存每個月份的天數。
     * mons[1] 表示 1 月的天數，mons[2] 表示 2 月的天數，以此類推。
     * mons[0] 用來佔位，方便解析
     */ 
    int mons[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    /*
     * 計算輸入日期到 2013 年 1 月 1 日的總天數。
     * 首先將 day 減 1，因為要從 1 月 1 日開始算起。
     * 然後從 1 月開始循環到輸入月份，將每個月的天數加總到 total_days 變數中。
     */ 
    int total_days = day - 1;
    for (int i = 1; i < month; i++) {
        /*
         * 計算總天數對應的星期幾。
         * 然後將結果%7，得到的數字就是星期幾（星期日為 0，星期一為 1，以此類推）。
         */
        total_days += mons[i];
    }

    // 2013 年 1 月 1 日 是星期二，所以基準點需要加上 2
    printf("Ans=%d\n", (total_days + 2) % 7);
}
