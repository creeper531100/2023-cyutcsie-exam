﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
/*
 * 最小的子序列是指在原數列中包含給定的 K 個元素，且該子序列的長度最短。
 * 例如 1 2 3 7 1 12 9 11 9 6 3 7 5 4 5 3 1 10 3 3
 * K=4，那麼最小的子序列是 1 2 3 7 1 12 9 11 9 6 3 7 5 4，因為它是包含給定的四個元素，且長度最短的子序列。
 *
 * 此程式主要是讀入一個數列的長度N，以及M和K，然後按照題目給出的方式生成一個數列X。
 * 接著，在X中尋找包含1到K的最小子數列的長度，並輸出答案。如果找不到這樣的子數列，則輸出"No"。
 * 生成數列的方式很簡單，依照題目給定的攻勢 Xi=(Xi-3+ Xi-2+ Xi-1) % M + 1, for i = 4 to N計算就好
 * 尋找包含1到K的最小子數列的方式也很簡單，從頭到尾就好
 */
int main() {
    fstream ifs("123.txt", ios::in);

    int N = 0;  // 數列的長度
    int M = 0;  // 數列中每個數的最大值，即 mod 的數字
    int K = 0;  // 子數列的長度

    // 從檔案讀取數列的長度、最大值和要尋找的子數列的長度
    ifs >> N >> M >> K;
    cout << N << " " << M << " " << K << endl;
    cout <<  "Ans=";

    // 99是隨便定的一個數字，只要足夠大就可以了
    int X[99] = { 0 };

    // 因為題目敘述是以 X1=1, X2=2, X3=3 為起點
    // 所以這邊從1開始，不以0為起點
    X[1] = 1;
    X[2] = 2;
    X[3] = 3;

    // 根據題目給出的方式生成數列，題目從 4 開始
    for (int i = 4; i <= N; i++) {
        // 用題目所述的方式，計算數列的每一個元素
        X[i] = (X[i - 3] + X[i - 2] + X[i - 1]) % M + 1;
    }

    // 在數列中尋找子數列的尾巴，也就是 K
    // 如果超過長度 N，而且還沒有找到符合要求的子數列，那麼輸出 No。
    for (int i = 1; i <= N; i++) {
        if (X[i] == K) { // 找到了以K為結尾的子數列
            cout << i << endl; // 輸出子數列的長度
            return 0; // 找到結果即可結束程式
        }
    }
    // 若未找到結果輸出No
    cout << "No" << endl;
}

/*
 * 假設 N 個正整數數列是依據下面的方式來產生：
 * X1=1, X2=2, X3=3
 * Xi=(Xi-3+ Xi-2+ Xi-1) % M + 1, for i = 4 to N
 * 假設 M=12，則產生的數列如下：
 * 1 2 3 7 1 12 9 11 9 6 3 7 5 4 5 3 1 10 3 3
 * 假設另外給定一個正整數 K，請撰寫程式找出包含 1, 2, 3, …, K 的最小子數列長度
 * 以 K=4 為例，最小的子數列為：
 * 1 2 3 7 1 12 9 11 9 6 3 7 5 4
 * 所以，長度為 14
 * 請從 e.txt 中讀入 N, M, K 三個數字，接著輸出最小的子數列長度，若是找不到則輸出 No。
 * 輸入範例 1：
 * 20 12 4
 * 輸出範例 1：
 * 20 12 4
 * Ans=14
 * 輸入範例 2：
 * 20 12 8
 * 8
 * 輸出範例 2：
 * 20 12 8
 * Ans=No
 */