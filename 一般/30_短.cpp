#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file("123.txt");
    string tmp;

    string strs[2] = { "invalid", "valid" };
    string ans_str;

    getline(file, tmp);
    cout << tmp << endl;

    while(getline(file, tmp)) {
        cout << tmp << endl;

        // 反轉目前行的內容
        reverse(tmp.begin(), tmp.end());
        stringstream ss(tmp);

        int len = 0;

        // 陣列用於存儲信用卡號的每一位數字
        int number[19] = { 0 };
        while (ss >> number[len]) {
            // 對於偶數位數字，乘以2
            if((len + 1) % 2 == 0) {
                number[len] *= 2;
            }
            len++;
        }

        // 計算校驗和
        int ans = 0;
        for (int i = 0; i < len; i++) {
            ans += number[i] % 10 + number[i] / 10;
        }

        // 判斷卡號是否有效
        ans_str += strs[ans % 10 == 0] + " ";
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
