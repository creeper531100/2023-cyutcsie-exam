#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>

using namespace std;

//蘇佑緯學長提供

/*
 * 解題思路
 * 從檔案中讀入兩個整數，分別代表上限和目標值。
 * 使用迴圈從 0 到上限進行數字的計算。
 * 將每個數字轉換成字串，並逐位計算數字總和。
 * 如果數字總和等於目標值，就把計數器加 1。
 * 最後輸出計數器的值，即為結果。
 */

int main() {
    int range; // 上限數字
    int target; // 目標數字和
    int count = 0; // 符合條件的數字個數

    ifstream ifs("123.txt");
    ifs >> range >> target;

    printf("%d %d\n", range, target);

    // 搜尋範圍內的每個數字
    for (int i = 0; i <= range; i++) {
        // 目前數字的數字和
        int digit_sum = 0;
        int tmp = i;

        while (tmp != 0) {
            // 首先計算tmp除以10的餘數，即tmp % 10，這是為了得到i的最低位數
            digit_sum += tmp % 10;
            // tmp 除以10，即將其向右移動一位，以處理i的下一位數。
            tmp /= 10;
        }

        // 如果數字和符合條件，則計數器加一
        if (digit_sum == target) {
            count++;
        }
    }

    printf("Ans=%d\n", count);
}

/*
 * 請撰寫一個程式從檔案 e.txt 中讀入二個正整數 n 與 k(n100000000)，接著輸出 0~n
 * 的數值中，每個數字總合為 k 的個數。
 * 範例輸入：
 * 100 5
 * 表示要從 0~100 中找出數字總合為 5 的數值個數，這些數值有：
 * 5
 * 14（因為 1 + 4 = 5）
 * 23（因為 2 + 3 = 5）
 * 32（因為 3 + 2 = 5）
 * 41（因為 4 + 1 = 5）
 * 50（因為 5 + 0 = 5）
 * 範例輸出：
 * 100 5
 * Ans=6
 */
