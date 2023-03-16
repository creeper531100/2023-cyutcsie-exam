﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
 * 這段程式碼讀取一個檔案"a.txt"中的整數，並使用質因數分解的方式將其分解為所有質數的乘積。
 * 具體來說，程式碼中定義了一個整數陣列mp，用於記錄每個質數出現的次數。一開始將mp陣列所有元素都初始化為0。
 * 接下來，程式碼從2開始遍歷到res（也就是讀取的整數），依次判斷每個數字是否為質數。
 * 如果是質數，就使用while迴圈將res中的所有該質數的倍數都除掉，同時在mp陣列中增加該質數的次數。
 * 這樣做可以確保分解的結果都是質數的乘積。
 *
 * 最後，程式碼從mp陣列的尾部開始遍歷，輸出所有出現次數不為0的質數及其次數。
 * 其中，每個質數及其次數都用括號括起來，質數與次數之間用逗號分隔。整個分解結果的輸出以"Ans="開頭。
 */

int main() {
    int res = 0;
    FILE* file = fopen("a.txt", "r+");
    fscanf(file, "%d", &res);
    printf("%d\n", res);

    int mp[65535] = { 0 };

    // 從2開始到res，進行以下的迴圈
    // 質因數從2開始，結果不大於輸入數字
    for (int i = 2; i <= res; i++) {
        // 如果res可以被i整除，進入以下的迴圈
        while (res % i == 0) {
            mp[i] = mp[i] + 1; // 增加該質數的次數，將mp[i]加1
            res /= i; //除掉倍數
        }
    }

    printf("Ans=");
    // 從65535 - 1開始到0，進行以下的迴圈
    for (int i = 65534; i >= 0; i--) {
        // 如果mp[i]出現質數的次數不為0，進入以下的條件式
        if (mp[i] != 0) {
            printf("%d(%d)", i, mp[i]);
        }
    }
	printf("\n");
}

/*
 * 請寫一個程式，從資料檔(a.txt)讀入一個正整數，把它的所有質因數找出來。例如：
 * 如果輸入是 72，因為 72=23×32，於是質因數就有 2 與 3，如果輸入是 181944，因為
 * 181944=192×7×32×23，於是質因數就有 19，7，3 與 2。為方便起見，192×7×32×23，
 * 使用 19(2)7(1)3(2)2(3)作輸出。也就是說，ab 輸出為 a(b)。
 *
 * 範例輸入：
 * 181944
 * 範例輸出：
 * 181944
 * Ans=19(2)7(1)3(2)2(3)
 */