#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    fstream ifs("123.txt", ios::in);
    int X;
    int K;
    ifs >> X >> K;
    printf("%d\n%d\n", X, K);

    /*
     * 謝囉機掰題目
     * 在計算過程中，除數可能很大，而被除數也可能很大，導致結果的精度不足。
     * 這會導致答案有誤，甚至可能溢出。
     * 所以你不能用float，解決方法是使用較大的浮點數(double)。
     * 不然計算容易溢位，幹還好我有驗證，耖
     */
    double ans = 0;
    for (int i = 1; i <= K; i++) {
        double factorial_result = 1;
        //計算 i 的階乘
        for (int j = 1; j <= i; j++) {
            factorial_result *= j;
        }
        //計算 X 的 i 次方，相加至 ans 變數
        ans += (double)pow(X, i) / factorial_result;
    }
    printf("Ans=%lld\n", (long)ans);
}