#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

// 函數用於獲取每個月的天數，考慮閏年
int get_day(int year, int month) {
    int days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // 各月份的天數
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) { // 判斷是否為閏年
        days[2] = 29; // 如果是閏年，2月天數改為29天
    }
    return days[month]; // 返回指定月份的天數
}


int main() {
    ifstream file("123.txt"); // 開啟檔案，設定為讀取模式

    int year; // 年份
    int month; // 月份
    int day; // 日份

    file >> year >> month >> day; // 從檔案中讀取日期資訊

    // 輸出讀取的日期資訊
    printf("%d %d %d\n", year, month, day);

    // 判斷日期是否合法
    if (year > 2100 || year < 1900 || day > get_day(year, month)) {
        cout << "Ans=Error" << endl; // 輸出錯誤訊息
        return 0; // 結束程式
    }

    int total = 0; // 總天數

    // 計算自1900年1月1日以來的月數，記得減一不要計算到當月月份
    int passed = (year - 1900) * 12 + month - 1; 
    for (int i = 0; i < passed; i++) {
        int current_year = 1900 + i / 12; // 當前年份
        int current_month = i % 12 + 1; // 當前月份
        total += get_day(current_year, current_month); // 累加每個月的天數
    }

    char weekdays[7][70] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" }; // 星期幾
    printf("Ans=%s\n", weekdays[(total + day) % 7]); // 輸出計算後的星期幾
}

/*
 * 閏年的 2 月為 29 日，閏年的規則如下：
 * (1) 如果年份被 4 整除，則移至步驟 2。否則，請跳至步驟 5。
 * (2) 如果年份被 100 整除，則移至步驟 3。否則，請跳至步驟 4。
 * (3) 如果年份被 400 整除，則移至步驟 4。否則，請跳至步驟 5。
 * (4) 該年份為閏年 (有 366 天)。
 * (5) 該年分不是閏年 (有 365 天)。
 * 請由檔案 d.txt 中讀入一個日期，格式為(西元制年 月 日，且年度範圍為 1900 1 月 1
 * 日至 2100 12 月 31 日)請先判斷日期是否合法？如果合法請輸出此日期為星期幾？(可以
 * 使用今天為基準來進行推算)
 * (Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday)
 * 7
 * 上面正整數的輸出結果為：
 * 範例輸入一：
 * 1988 9 32
 * 範例輸出一：
 * 1988 9 32
 * Ans=Error
 * 範例輸入二：
 * 2002 11 10
 * 範例輸出二：
 * 2002 11 10
 * Ans=Sunday
 */
