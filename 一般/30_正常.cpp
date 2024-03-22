#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
    ifstream file("123.txt");
    string tmp;
    string ans_str = "";

    // getline() 函數用於從檔案中讀取一行文本，並存儲到指定的字符串變數 tmp 中。
    // 讀取測試資料筆數
    getline(file, tmp);
    cout << tmp << endl;

    // atoi 字串轉數字
    int max = atoi(tmp.c_str());


    for (int pos = 0; pos < max; pos++) {
        int len = 0;
        getline(file, tmp);
        /*
         * stringstream 是 C++ 中一個實用的字符串流，它可以像檔案流一樣使用運算符 >> 來從字符串中讀取數據。
         * 在此程式碼中，它被用於將讀取到的每個卡號字符串分解為一個個數字，並存儲到 digit 數組中。
         */
        stringstream ss(tmp);
        cout << tmp << endl;

        // 最長的卡號長度為 19
        int number[19] = { 0 };
        // 將卡號拆成一個個數字
        while(ss >> number[len]) {
            len++;
        }

        // 反轉並將偶數位置的字元乘以 2
        int ans = 0;
        int count = 0;
        for (int i = len; i >= 0; i--) {
            if (count % 2 == 0) {
                number[i] *= 2;
            }
            //%取個位數 /取十位數
            ans += number[i] % 10 + number[i] / 10;
            count++;
        }

        // 判斷卡號是否有效
        if (ans % 10 == 0) {
            ans_str += "valid ";
        }
        else {
            ans_str += "invalid ";
        }
    }

    cout << "Ans=" << ans_str << endl;
}

/*
 * 小明有一天外出在地上撿到一張信用卡，為了確認該卡片號碼是否造假，小明依據下面
 * 的演算法(Luhn Formula)進行計算：
 * 1. 假設卡號如下:
 * 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 2
 * 2. 反轉所有數字，結果如下:
 * 2 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1
 * 3. 將偶數位置的字元乘以 2，結果如下:
 * 2 10 4 6 2 2 0 18 8 14 6 10 4 6 2 2
 * 4. 將每個單一字元的數值進行加總，結果如下:
 * 2+1+0+4+6+2+2+0+1+8+8+1+4+6+1+0+4+6+2+2=60
 * 5. 加總結果如果是 10 的倍數，表示卡號是有效的(valid)，否則就是無效卡號
 * (invalid)。
 * 12
 * 請撰寫程式可以從 e.txt 資料檔，先讀入測試資料筆數 N，接著，針對下面 N 行卡號，
 * 逐一讀入，並輸出對應的 valid 或 invalid。
 * 範例輸入：
 * 2
 * 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 2
 * 5 5 2 0 0 4 0 0 4 7 9 4 3 4 0 9
 * 範例輸出：
 * 2
 * 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 2
 * 5 5 2 0 0 4 0 0 4 7 9 4 3 4 0 9
 * Ans=valid invalid
 */