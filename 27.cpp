#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
using namespace std;


int main() {
    fstream iss("123.txt", ios::in);
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
