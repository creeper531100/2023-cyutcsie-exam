﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

/********************************************************************
* 注意，此程式碼並非我撰寫的
* 此程式碼是由 Kashionz 撰寫，我只加入了註解並改善了變數名稱。
* 如果您想了解更多訊息，請參閱 Kashionz 的原始碼。
* https://gist.github.com/Kashionz/2430b7408ae6193e832365535f953ecb
*********************************************************************/

using namespace std;
int main() {
    fstream file("123.txt", ios::in); // 開啟檔案，設定為讀取模式
    int M; // 每年存款金額
    int T; // 存款年數
    float S; // 本利和

    file >> M >> T >> S; // 從檔案中讀取資料
    printf("%d\n%d\n%.0lf\n", M, T, S);

    S = S / M; // 將本利和轉換成每年的本利和

    float r = 1; // 複利率初始值為1（即不複利）

    while (true) {
        /*
         * 這個不等式的意思是，以年複利率 r，存款年數 T，每年存款金額相同為 M 的情況下，存款的本利和大於 S。
         * 其中，S 是給定的本利和數量，代表了我們想要達到的目標。
         * 在這個判斷式中，r 代表年複利率。在程式中，我們通過不斷調整 r 的值，使得上面的判斷式成立
         */
        if (r * (pow(r, T) - 1) / (r - 1) > S) {
            break; // 如果相等，則跳出迴圈
        }
        r += 0.00001; // 如果不相等，則嘗試增加複利率0.00001，重新計算本利和
    }

    // 輸出結果，注意要將預期本利和乘以每年存款金額
    printf("Ans=%.2f%%\n", (r - 1) * 100);
}