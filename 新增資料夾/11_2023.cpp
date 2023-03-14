#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    // stringstream ss("3 2 5 3 7 2");
    ifstream ss("123.txt", ios::in);

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

    /* TODO: 使用快速解法求解rem[i]的值（可替換上面的代碼塊）
     * for (int i = 0; i < len; i++) {
     *   prime[i] = prime_mul / a1[i];
     *   rem[i] = prime[i] % a1[i];
     * }
     */

    int ans = 0;
    for (int i = 0; i < len; i++) {
        ans += prime[i] * rem[i] * a2[i];
    }

    printf("\nAns=%d\n", ans % prime_mul);
}
