#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

// 函數：get_leap
// 功能：判斷某年某月的天數（閏年2月為29天）
// 參數：year：年份；month：月份
// 回傳值：該年該月的天數
int get_leap(int year, int moon) {
    int mons[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // TODO: 題目提供方法
    if (year % 4 != 0) {
        //該年分不是閏年
        return mons[moon];
    }

    if (year % 100 != 0) {
        //該年份為閏年，2月改為29天
        mons[2] = 29;
        return mons[moon];
    }

    if (year % 400 != 0) {
        //該年份為閏年，2月改為29天
        mons[2] = 29;
        return mons[moon];
    }

    //該年分不是閏年
    return mons[moon];

    /*
     *  TODO: 你也可以用以下方法替換上面代碼快，使用此方法比較簡潔
     *  if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
     *      //該年份為閏年
     *      mons[2] = 29;
     *  }
     *  return mons[month];
     */
}

int main() {
    int year;
    int month;
    int day;

    cin >> year >> month >> day;
    printf("%d %d %d\n", year, month, day);

    char weeks[7][70] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    // 判斷使用者是否輸入超過該月份天數或是超過規定年分
    if (day > get_leap(year, month) || year > 2100 || year < 1900) {
        cout << "Ans=Error" << endl;
        return 0;
    }

    // 將total_days加上指定日期的天數減1（因為從1月1日算起），就得到了從1900年1月1日到指定日期所經過的天數。
    int total_days = day - 1;

    /*
     * 第一個迴圈從1900年開始，一直加到指定年份的前一年，對每一年的12個月進行計算，並將經過的天數加到total_days中。
     * 這部分代碼中，變數i代表當前年份與1900年之間的差距，now_year代表當前年份。
     */
    for (int i = 0; i < year - 1900; i++) {
        int now_year = 1900 + i;
        for (int j = 1; j <= 12; j++) {
            total_days += get_leap(now_year, j);
        }
    }

    // 第二個迴圈計算指定年份1月到指定月份前一個月的天數，並將其加到total_days中。
    for (int i = 1; i < month; i++) {
        total_days += get_leap(year, i);
    }

    // 1900 年 1 月 1 日 是星期一，所以基準點需要加上 1
    printf("Ans=%s\n", weeks[(total_days + 1) % 7]);
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