#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
/*
 * 需要注意的是，程式碼中的 count 函式需要使用 algorithm 標頭檔案。
 * 因此編譯失敗需要在檔案開頭加上 "#include<algorithm>" 才能順利編譯。
 */

using namespace std;

int main() {
    FILE* file = fopen("d.txt", "r+");
    // 分別用來存儲讀入的字串和計算結果的字串
    // 99是隨便定的一個數字，只要足夠大就可以了
    char res[99], ans[99];

    // 從檔案中讀入字串
    // 將讀入的字串複製到計算結果的字串中

    fscanf(file, "%s", res);
    printf("%s\n", res);
    strcpy(ans, res);

    // 逐個字符檢查，如果是大炸彈，則將其爆炸範圍內的 0 替換為 '-'
    // 如果是小炸彈，也做同樣的替換
    for (int i = 0; i < strlen(res); ++i) {
        if (res[i] == 'X') {
            ans[i - 2] = '-';
            ans[i + 2] = '-';
        }

        if (res[i] == 'x' || res[i] == 'X') {
            ans[i - 1] = '-';
            ans[i] = '-';
            ans[i + 1] = '-';
        }
    }

    // 計算剩餘的 0 的個數並輸出
    printf("Ans=%d\n", count(ans, ans + 99, '0'));
}