#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
//By asoocomtw

using namespace std;
int main() {
    // 打開檔案
    ifstream ifs("123.txt"); // "123.txt" 是檔案名稱，ios::in 表示以讀取模式開啟檔案
    string boom; // 第一個字串
    string check; // 第二個字串

    // 從檔案讀入兩個字串
    ifs >> boom >> check; // 將兩個字串依序讀入變數 boom 和 check 中
    cout << boom << endl; // 輸出第一個字串
    cout << check << endl; // 輸出第二個字串

    int A = 0; // 記錄 A 的數量
    int B = 0; // 記錄 B 的數量

    // 檢查每個數字是否相同
    for (int i = 0; i < boom.length(); i++) { // 逐一檢查第一個字串中的每個數字
        if (boom[i] == check[i]) { // 如果在同一個位置上的數字相同
            A++; // A 的數量加 1
        }

        for (int j = 0; j < check.length(); j++) { // 逐一檢查第二個字串中的每個數字
            if (boom[i] == check[j]) { // 如果在不同的位置上的數字相同
                B++; // B 的數量加 1
            }
        }
    }

    // 輸出結果
    printf("Ans=%dA%dB\n", A, B - A); // %d 代表輸出一個整數，\n 表示換行
    /*
     * 在上述程式碼中，我們用變數 a 紀錄兩個字串中相同位置的數字數量，用變數 b 紀錄兩個字串中不同位置但是有相同數字的數量。
     * 因此， b - a 就是兩個字串中只有數字相同但位置不同的數量。
     * 要注意的是，當 b 中包含了所有數字相同的情況，包括位置相同和位置不同的情況。
     * 所以，我們需要扣除位置相同的情況，以避免重複計算。因此，要減去 a，才能得到只有數字相同但位置不同的數量。
     */
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