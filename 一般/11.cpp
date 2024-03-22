#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    ifstream ss("123.txt");

    int tmp1;
    int tmp2;

    // 陣列長度
    int len = 0;

    // 質數的乘積
    int prime_mul = 1;

    // 儲存質數和對應的餘數
    // 255是隨便定的一個數字，只要足夠大就可以了
    int a1[255];
    int a2[255];

    // 儲存商和對應的倍數值
    int prime[255];
    int rem[255];

    //x = 35 * 2 * 2 + 21 * 1 * 3 + 15 * 1 * 2 % 105 = 23
    //     ^   ^   ^
    //  105/3  餘數 下一個數字

    // 逐個讀入質數(tmp1)和餘數(tmp2)，並計算質數的乘積
    while (ss >> tmp1 >> tmp2) {
        a1[len] = tmp1;
        a2[len] = tmp2;
        printf("%d %d ", tmp1, tmp2);

        prime_mul *= tmp1;
        len++;
    }

    //TODO: 題目提供解法
    for (int i = 0; i < len; i++) {
        prime[i] = prime_mul / a1[i];
        for (int j = 1;; j++) { // 找到對應的倍數值
            if ((prime[i] * j) % a1[i] == 1) {
                rem[i] = j;
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < len; i++) {
        ans += prime[i] * rem[i] * a2[i];
    }

    printf("\nAns=%d\n", ans % prime_mul);
}

/*
 * 中國餘數定理最早記載於第一世紀之孫子算經中，其原題目為：今有物不知其數，三三
 * 數之剩二，五五數之剩三，七七數之剩二，問物幾何？
 * 其計算過程如下：
 * 1.首先計算所有質數的乘積 -> N=3*5*7=105
 * 2.計算 N 除以每個質數的商 -> 105/3=35, 105/5=21, 105/7=15
 * 3.計算這個商的倍數值，使得對原質數取餘數的結果為 1
 * 35*y1 mod 3=1 得到 y1=2
 * 21*y2 mod 5=1 得到 y2=1
 * 15*y3 mod 7=1 得到 y3=1
 * 4.答案 x 等於每個質數的商、倍數值、餘數三者乘積的總和 mod 原來質數的乘積
 * x=35*2*2+21*1*3+15*1*2 mod 105=23
 * 請撰寫一個程式從資料檔 e.txt 依序讀入幾個質數（不一定只有三個質數）與對應的
 * 餘數，然後輸出解答。
 * 範例輸入：
 * 3 2 5 3 7 2
 * 範例輸出：
 * 3 2 5 3 7 2
 * Ans=23
 */