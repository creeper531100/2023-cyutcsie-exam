#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream ifs("123.txt");

    int month;
    int day;

    ifs >> month >> day;
    printf("%d %d\n", month, day);

    /*
     * 宣告一個長度為 13 的整數陣列 "mons"，用來儲存每個月份的天數。
     * mons[1] 表示 1 月的天數，mons[2] 表示 2 月的天數，以此類推。
     * mons[0] 用來佔位，方便解析
     */
    int mons[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    /*
     * 計算輸入日期到 2013 年 1 月 1 日的總天數。
     * 然後從 1 月開始循環到輸入月份，將每個月的天數加總到 total_days 變數中。
     */

    int total = 0;
    for (int i = 1; i < month; i++) {
        total += mons[i];
    }

    /*
     * 2013 年 1 月 1 日 是星期二，所以基準點需要加上 1
     * 計算總天數對應的星期幾。
     * 然後將結果%7，得到的數字就是星期幾（星期日為 0，星期一為 1，以此類推）。
     */
    printf("Ans=%d\n", (total + day + 1) % 7);
}

/*
 * 西元 2013 年的 1 月 1 日為星期二，請撰寫程式從資料檔 d.txt 讀入兩個數字(中間以
 * 空格區分)，分別代表哪一個月的哪一天，接著算出此日期在 2013 年中為星期幾，最後
 * 將星期幾以數字輸出，星期日為 0，星期一為 1，星期二為 2，以此類推。
 * 範例輸入一：
 * 3 14
 * 範例輸出一：
 * 3 14
 * Ans=4
 * 範例輸入二：
 * 12 7
 * 範例輸出二：
 * 12 7
 * Ans=6
 */
