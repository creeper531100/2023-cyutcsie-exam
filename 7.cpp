#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main() {
    FILE* file = fopen("b.txt", "r+");

    float dec;
    int integer;

    //99是隨便定的一個數字，只要足夠大就可以了
    char buf[99] = { '\0' };

    fscanf(file, "%s", &buf);
    sscanf(buf, "%d%f", &integer, &dec);
    /*
     * 這邊使用fscanf()是因為可以先輸出輸入數字，日後也可以直接使用sscanf()解析
     * sscanf()函式會將讀取到的字串轉換成指定的型別
     * 在這裡，使用%d%f分別將整數部分和小數部分轉換成int和float型別
     */

    printf("%s", buf);
    printf("\nAns=");

    string tmp;
    while (integer != 0) {
        /*
         * 使用 while 迴圈將整數部分轉換為二進位數字，把每個二進位位數存入字串變數 tmp 中。
         * 轉換過程是不斷地除以 2，直到整數部分變為 0 為止。
         * 這邊為了方便反轉輸出結果，我們使用C++的字串加總
         */
        tmp += integer % 2 + '0';
        integer /= 2;
    }

    //將二進制數字反轉輸出
    for(int i = tmp.length(); i >= 0; i--) {
        printf("%c", tmp[i]);
    }

    printf("+");
    //取小數點後三位
    for (int i = 0; i < 3; i++) {
        /*
         * 先把小數部分乘上 2，然後把整數部分取出來。
         * 如果整數部分為 1，就代表需要進位，把小數部分扣掉 1。
         * 這樣就可以不斷地乘以 2，取整數，直到小數部分轉換完畢。
         */
        dec *= 2.0; //十進制轉二進制小數, 不斷乘二
        printf("%d", (int)dec);

        if ((int)dec == 1) {
            //若進位扣1
            dec--;
        }
    }
}