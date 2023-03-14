#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    fstream ifs("123.txt", ios::in);

    int n;
    // 存放每一個數字的字串陣列，69是隨便定的一個數字，只要足夠大就可以了
    string str[69];

    // 讀入數字個數
    ifs >> n;
    cout << n << endl;

    for (int i = 0; i < n; i++) {
        ifs >> str[i];
        cout << str[i] << " ";
    }

    cout << "\n";

    int max_value = 0;
    int max_index = 0;

    for (int i = 0; i < n; i++) {
        // 存放轉換後的數字
        int sum = 0;
        // 取得數字的位數
        int str_len = str[i].length();

        for (int j = 0; j < str_len; j++) {
            // 計算數字加總，加上 10 是為了防止出現負數
            sum += str[i][j] - '0' + 10;
        }

        // 將位數和數字加總取 10 的餘數合併成一個新數字
        int value = (str_len * 10) + sum % 10;

        // 如果轉換後的數字比目前的最大值還要大
        if (value > max_value) {
            max_value = value;// 更新最大值
            max_index = i; // 更新最大值所對應的數字索引
        }
    }

    // 輸出轉換後最大的數字以及對應的正整數
    cout << "Ans=" << max_value << " " << str[max_index] << endl;
}
/*
 * 你的程式碼看起來已經可以讀入測試資料並正確輸出測試資料中最大的數值以及對應的正整數。以下是一些可以進一步優化程式碼的建議：
 * 為了取得正整數數字加總，你的程式碼採用了字串相加，這樣的作法是會比較慢的。你可以採用數字取餘數的方式來取得正整數數字加總，這樣會更快速。
 * 你的程式碼中使用了一個名為 max 的變數，這個變數名稱會和標準函式庫中的 max 函式產生衝突，不建議採用這樣的變數名稱。
 * 你的程式碼中有一個數字 69，這個數字不是很明顯的來源，也不太好維護。你可以將這個數字改成一個有意義的常數，例如 const int MAX_N = 100。
 */