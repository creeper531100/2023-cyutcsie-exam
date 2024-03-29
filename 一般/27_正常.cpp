﻿#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
using namespace std;


int main() {
    ifstream iss("123.txt");
    string str;
    iss >> str;

    cout << str << endl;
    cout << "Ans=";
    /*
     * 偏移量是由每個 'C' 後面的數字所決定，例如 'C3' 表示偏移量為 3。
     * 接著從 'C' 後面的第一個字元開始，依序取出數字進行轉換，直到遇到下一個 'C' 為止。
     */
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'C') {
            // 由於第一個字元是 'C'，後面的第一個字為 3 因此取出偏移量 3。
            int offset = str[i + 1] - '0';
            //從偏移量 3 字元開始，直到遇到下一個 'C' 為止
            for (int j = i + 2; j < str.length(); j++) {
                if (str[j] == 'C')
                    break;
				
                // 計算數字加總，加上 10 是為了防止出現負數
				// 並且再使用%來取尾數
                // 2 % 10 = 2; 12 % 10 = 2 也不會被影響
                int ans = ((str[j] - '0') - offset + 10) % 10;
                cout << ans;
            }
        }
    }

    cout << endl;
}

/*
 * 小明想要安全的將一串由數字 0~9 所構成的字串傳給朋友，於是他想了一個方法，他把
 * 這個字串切成好幾段不固定長度的子字串，每一段都隨機使用一個位移編碼的方式來進
 * 行傳換，位移量為 1~9，並且每一段子字串的開頭加入一個字元‘C’，這樣朋友收到之
 * 後，就可以依照指定方式來還原出原始字串。底下是一個例子，假設原始字串如下：
 * 042332300077139487945
 * 小明將上面字串隨機切割為好幾個子字串如下：
 * 04 23323000 771394 87945
 * 每一段使用不同的隨機位移量進行編碼：
 * 04 (位移量 3)  37
 * 23323000 (位移量 8)  01101888
 * 771394 (位移量 2)  993516
 * 87945 (位移量 7)  54612
 * 所以真正傳送給朋友的字串如下：
 * C337C801101888C2993516C754612
 * 麻煩從資料檔 d.txt 中讀入這一段編碼的字串，然後解碼還原出原本小明想要傳送的字
 * 串。
 * 範例輸入：
 * C337C801101888C2993516C754612
 * 範例輸出：
 * C337C801101888C2993516C754612
 * Ans=042332300077139487945
 */