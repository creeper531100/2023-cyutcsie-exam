#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    fstream ifs("123.txt", ios::in);
    int X = 5;
    int K = 8;
    ifs >> X >> K;
    printf("%d\n%d\n", X, K);

    float ans = 0;
    for(int i = 1; i <= K; i++) {
        int factorial_result = 1;
        //計算 i 的階乘
        for(int j = 1; j <= i; j++) {
            factorial_result *= j;
        }
        //計算 X 的 i 次方，相加至 ans 變數
        ans += pow(X, i) / factorial_result;
    }
    printf("Ans=%d\n", (int)ans);
}