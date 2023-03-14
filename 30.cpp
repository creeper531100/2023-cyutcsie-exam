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
    fstream file("123.txt", ios::in);
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
