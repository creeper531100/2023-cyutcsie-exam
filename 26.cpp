#include <iostream>
#include <fstream>

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
 * 有一天小明設計了一個新的數值大小比較方法，主要依照數值的「位數」以及「數字加
 * 總取 10 的餘數」所轉換出的新數值來比較，舉例來說，有兩個數值 117 與 899，119
 * 是 3 位數，數字加總是 1+1+7=9，轉換為新數值 39，899 也是 3 位數，數字加總是
 * 8+9+9=26，取 10 的餘數是 6，因此形成新數字 36，由於轉換後的數值 39>36，所以
 * 原來的數值 117>899。
 * 請從 e.txt 中先讀入一個數字 N(N10)，表示接著有多少個正整數，接著將每個正整
 * 數經過轉換並比較之後，輸出轉換後最大數值與對應的正整數（測試資料只會有唯一的
 * 最大值）。
 * 範例輸入一：
 * 5
 * 10
 * 215 69 923 327 188
 */