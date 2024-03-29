﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//By asoocomtw

/*
 * 判斷排序方式
 * asc: 是否為升序排序
 * left: 比較的左邊數字
 * right: 比較的右邊數字
 */
bool sorted_asc_desc(int asc, int left, int right) {
    if (asc) {
        // 若asc為1，代表降序排列，左邊數字要大於右邊數字
        return left > right;
    }
    else {
        // 若asc為0，代表升序排列，左邊數字要小於右邊數字
        // else可以省略，若你想要簡潔一點的話
        return left < right;
    }
}

int main() {
    int count = 0;
    int num[100] = { 0 };
    int sort = 0;

    string res;
    getline(cin, res);
    sort = atoi(res.c_str());
    cout << sort << endl;

    getline(cin, res);
    stringstream ss(res);

    cout << res << endl;

    // 讀取第一行的排序方式，0為升序，1為降序
    // 讀取檔案中的數字，並將數字存入num陣列
    while (ss >> num[count]) {
        count++;
    }

    // 排序
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < i; j++) {
            // 使用sorted_asc_desc判斷排序方式，進行升序或降序排列
            if (sorted_asc_desc(sort, num[i], num[j])) {
                /*
                 * 這邊採用氣泡排序法
                 * 排序的邏輯為，比較每一對相鄰的元素，如果它們的順序錯誤，就把它們交換過來。
                 * 每次迴圈會讓一個元素排到正確的位置，也就是排序的末端。
                 */
                int sw = num[j];
                num[j] = num[i];
                num[i] = sw;
            }
        }
    }

    // 輸出排序後的結果
    cout << "Ans=";
    for (int i = 0; i < count; i++) {
        cout << num[i];
        if (i < count - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

/*
 * 排序：請針對 b.txt 中的資料進行排序，並依題意由大至小或由小至大將排序結果印
 * 出，排序方式不限，排序後的資料間以一個空白間格分隔。
 * 輸入檔說明：
 * 輸入檔中包含兩行文字，第一行的數字為 0 或 1。0 代表輸出結果由小至大排列，1 則
 * 代表輸出結果由大至小排列。第二行則包含欲排序的數字，每個數字均為整數，數字個
 * 數不超過 100 個，每個數字間以空白間隔。
 * 範例輸入：
 * 0
 * 3 2 5 7 8 1
 * 範例輸出：
 * 0
 * 3 2 5 7 8 1
 * Ans=1 2 3 5 7 8
 */