#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main() {
    fstream ifs("123.txt", ios::in);

    int max_len; //最大長度
    string str;  //文件內容字符串
    int ans = 0; //答案

    //從文件中讀取字符串和最大長度
    ifs >> str >> max_len;
    cout << str << endl;
    cout << max_len << endl;

    //從頭到尾遍歷整個字符串，每次從 i 開始取出最大長度的子串，每次遞增3
    for (int i = 0; i < str.length(); i += max_len) {
        string spilit = str.substr(i, max_len); //使用 .substr() 函數截取子串 .substr(起始位置, 長度)
        ans += atoi(spilit.c_str()); //將子串轉換為整數，並將其加到答案中
    }

    /* TODO: 不使用STL容器方法（可替換上面的代碼塊）
     * for (int i = 0; i < str.length(); i += max_len) {
     *     char tmp[4] = { '\0' }; // 暫存，用於轉整數
     *     //從頭到尾遍歷整個字符串，每次從 i 開始取出最大長度的子串，每次遞增3
     *     //以防數值超過字串長度造成溢位，需要加入i + j < str.length()判斷
     *     for (int j = 0; j < max_len; j++) {
     *         if (i + j < str.length()) {
     *             break;
     *         }
     *         tmp[j] = str[i + j];
     *     }
     *     ans += atoi(tmp);
     * }
     */

    cout << "Ans=" << ans << endl;
}

/*
 * 雜湊(hashing)是用來計算一個鍵值(key value)對應之索引(index)的方法，而「折疊法」是
 * 雜湊函數的方法之一，假設有一個鍵值為 5120969190600791，而折疊的長度為 3，折疊
 * 的計算過程如下，首先鍵值先依照折疊長度加以切割，由於鍵值有 16 個數字，每 3 個數
 * 字進行切割的話，可以切出 6 段，如下所示：
 * 512 096 919 060 079 1
 * 接著這些數值進行加總就可以得到所需要的索引 1667，如下所示：
 * 512+096+919+060+079+1=1667
 * 所以請撰寫一個程式從 b.txt 中讀入兩行資料，第一行是鍵值的字串，第二行是折疊的
 * 長度，接著輸出索引的結果。
 * 範例輸入：
 * 5120969190600791
 * 3
 * 範例輸出：
 * 5120969190600791
 * 3
 * Ans=1667
 */