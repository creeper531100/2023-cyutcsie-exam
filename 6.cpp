#include <fstream>
#include <iostream>

using namespace std;

//求最大公因數
int GCD(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    return GCD(num2, num1 % num2);
}

//求最小公倍數
int LCM(int num1, int num2) {
    return num1 * num2 / GCD(num1, num2);
}

int main() {
    ifstream iss("b.txt", ios::in);
    int ans = 1;
    int data;

    while (iss >> data) {
        printf("%d ", data);
        ans = LCM(ans, data);
    }

    printf("\nAns=%d\n", ans);
}

/*
 * 試寫一程式，從檔案(c.txt)讀入一串正整數(最多 10 個)，試找出此串正整數之最小公倍
 * 數。例如：
 * 範例輸入：
 * 12 16 36 128
 * 範例輸出：
 * 12 16 36 128
 * Ans=1152
 */