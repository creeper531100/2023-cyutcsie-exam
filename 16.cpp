﻿#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

/*
 * By 1000
 * 這個程式利用了一個 while 循環，不斷嘗試不同的存款複利率，直到計算出來的本利和與給定的本利和相等為止。
 * 在循環中，每次會根據存款年數和存款複利率來計算出每年的本利和，並且加總得到總本利和。
 * 當總本利和與給定的本利和相差不大時，就認為計算出來的存款複利率是正確的。
 */

int main() {
    fstream ifs("123.txt", ios::in);
    int M; // 每年存款金額
    int T; // 存款年數
    int S; // 本利和

    ifs >> M >> T >> S; // 從標準輸入讀入三行資料

    cout << M << endl; // 輸出每年存款金額
    cout << T << endl; // 輸出存款年數
    cout << S << endl; // 輸出本利和

    double ans = 0; // 用來存儲每年的本利和
    double count = 0.0; // 存款複利率，初始值為0

    // 反算複利率
    while ((int)ans != S && (int)ans + 1 < S) { // 如果計算出的本利和與給定的本利和不同，就繼續計算
        ans = 0; // 本利和歸零
        count += 0.000001; // 每次增加0.000001，即0.0001%
        for (int i = 0; i < T; i++) { // 根據存款年數進行循環
            ans += M; // 加上每年存款金額
            ans = ans * (1.0 + count); // 乘以（1+存款複利率）
        }
    }

    printf("Ans=%.2f%%\n", count * 100); // 輸出計算得到的複利率，保留兩位小數
}

/*
 * 儲蓄是一種美德，目前常見的儲蓄方式為定時存款，整筆領回，利率採每年複利的方式
 * 計算。例如：每年存 100000，存 3 年，若是複利率為 2.25%，3 年後的本利和如下：
 * 第一年初存入 100000，本金=100000
 * 第二年初，前一年本利=100000*(1+2.25%)=102250，加上存入的 100000，合計 202250
 * 第三年初，前一年本利=202250*(1+2.25%)=206801，加上存入的 100000，合計 306801
 * 第三年尾合計領回的本利和=306801*(1+2.25%)=313704
 * 請寫一個程式從資料檔 a.txt 中讀入三行資料，第一行是每年存款的金額，第二行是存
 * 款年數，第三行是本利和，接著反算出存款複利率為何（請計算到小數點後兩位）。
 * 範例輸入:
 * 6
 * 100000
 * 3
 * 313704
 * 範例輸出:
 * 100000
 * 3
 * 313704
 * Ans=2.25%
 */