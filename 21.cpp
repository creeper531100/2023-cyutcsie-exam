﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

//By asoocomtw
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