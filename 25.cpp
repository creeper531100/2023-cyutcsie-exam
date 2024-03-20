#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream ifs("123.txt");

    // 這些只是預設數值方便我測試
    int f1 = 2;
    int f2 = 4;

    int total = 15;
    int foots = 42;

    ifs >> f1 >> f2 >> total >> foots;
    printf("%d %d %d %d\n", f1, f2, total, foots);

    // 直接用一元二次代數化簡求解
    // 化簡流程如下
    // https://github.com/creeper531100/2023-cyutcsie-exam/blob/master/image/img0.png
    int x = (foots - total * f2) / (f1 - f2);  // 求解 x 的值
    int y = (foots - total * f1) / (f2 - f1);  // 求解 y 的值

    // 判斷方程是否有解，並檢查解是否為正數
    if (x + y == total && x > 0 && y > 0) {
        // 如果總數正確且為正數，則輸出解
        printf("Ans=%d %d\n", x, y);  
    }
    else {
        printf("Ans=No Solution\n");
    }
}

/*
 * 雞兔同籠：有一個籠子裡裝了若干的雞和兔，數一數他們的頭，一共有 15 顆頭，數一數
 * 他們的腳，一共有 42 隻腳，請問雞和兔各有多少隻呢？
 * 透過簡單的代數計算可以得知雞有 9 隻，兔子有 6 隻，他們的腳一共是：
 * 9*2+6*4=18+24=42
 * 請撰寫一個程式，可以從資料檔 e.txt 中讀入四個數字，分別表示第一種動物的腳數、第
 * 二種動物的腳數、頭的總數與腳的總數，然後輸出第一種動物的數目以及第二種動物的
 * 數目，若是解答不存在的話則輸出 No Solution。
 * 範例輸入一：（第一種動物 2 隻腳，第二種動物 4 隻腳，頭一共 15 個，腳一共 42 隻）
 * 2 4 15 42
 * 範例輸出一：
 * 2 4 15 42
 * Ans=9 6
 * 範例輸入二：（第一種動物 2 隻腳，第二種動物 4 隻腳，頭一共 10 個，腳一共 42 隻）
 * 2 4 10 42
 * 範例輸出二：（注意：No Solution 的字串請與題目說明完全一致，以避免驗證失敗）
 * 2 4 10 42
 * Ans=No Solution
 */