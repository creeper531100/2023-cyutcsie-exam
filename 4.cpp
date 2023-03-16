#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;

int main() {
    //99是隨便定的一個數字，只要足夠大就可以了
    char res[99] = { '\0' };
    FILE* file = fopen("d.txt", "r+");
    fread(res, 1, sizeof(res), file); //fgets 讀檔案所有內容

    string dst = "0";
    int ans = 0;

    for (int i = 0; i < strlen(res); i++) {
        if (res[i] >= '0' && res[i] <= '9') {
            //若在0~9範圍內將數字加入字串中
            dst += res[i];
            continue;
        }

        ans += atoi(dst.c_str()); //atoi將字串轉為數字
        dst = "0"; //清除 dst
    }
    printf("%s\n", res);
    printf("Ans=%d", ans);
}

/*
 * 請從資料檔 d.txt 讀入好幾行字串資料，字串資料是由字元(‘a’~’z’,’A’~’Z’)、數
 * 字(‘0’~’9’)以及空白字元所構成的，接著將字串中這些由字元或者空白隔開的數字部
 * 分進行加總(54+256+72+125+56+22+66=751)，並且將原字串以及結果輸出。
 * 範例輸入：
 * Cyut54is a356good 72school
 * Ne125ver 56give22 66up
 * 第一次消去 AL 字串得到 Thisisabl
 * 第二次消去 AL 字串得到 Thisis
 *
 * 計算方法：54+356+72+125+56+22+66=751
 * 範例輸出：
 * Cyut54is a356good 72school
 * Ne125ver 56give22 66up
 * Ans=751
 */