#include <fstream>
#include <iostream>

using namespace std;

/*
 * 透過雙重迴圈依序檢查第一個字串 boom 中每個數字是否和第二個字串 check 中的任意一個數字相同
 * 如果相同則進一步判斷它們是否在同一個位置上。
 * 在同一個位置上的數字相同，就將 A 的數量加一，表示這是一個 A。
 * 如果在不同的位置上的數字相同，就將 B 的數量加一，表示這是一個 B。
 * 最終，程式會輸出 A 和 B 的數量，即為答案。
 */

int main() {
    // 打開檔案
    fstream ifs("123.txt", ios::in); // "123.txt" 是檔案名稱，ios::in 表示以讀取模式開啟檔案
    string boom; // 第一個字串
    string check; // 第二個字串

    // 從檔案讀入兩個字串
    ifs >> boom >> check; // 將兩個字串依序讀入變數 boom 和 check 中
    cout << boom << endl; // 輸出第一個字串
    cout << check << endl; // 輸出第二個字串

    int A = 0; // 記錄 A 的數量
    int B = 0; // 記錄 B 的數量

    // 逐一檢查第一個字串中的每個數字
    for (int i = 0; i < boom.length(); i++) {
        // 逐一檢查第二個字串中的每個數字
        for (int j = 0; j < check.length(); j++) {
            // 找到相同數字
            if (boom[i] == check[j]) {
                if (i == j) {
                    // 若在同一個位置上的數字相同
                    A++;
                }
                else {
                    // 若在不同的位置上的數字相同
                    B++;
                }
            }
        }
    }

    printf("Ans=%dA%dB\n", A, B);
}

/*
 * 猜數字：請撰寫一個程式從 a.txt 中讀入兩個數字字串（長度最長為 10 且數字不重複），
 * 並且判斷字串中的每個數字，若是兩個字串在同一個位置的數字都相同，則記載一個 A，
 * 若是兩個字串都有這個數字但是位置不同，則記載一個 B，當沒有 A 也沒有 B 時則輸出
 * 0A0B，底下是輸入的範例：
 * 14685
 * 47653
 * 輸出結果：
 * 14685
 * 47653
 * Ans=1A2B
 */