#include <fstream>
#include<iostream>
using namespace std;

int main() {
    fstream ifs("123.txt", ios::in);
    char first_char; //宣告字元變數first_char，用來存放身分證號碼的第一個字元
    string id_number; //宣告字串變數id_number，用來存放身分證號碼的第二到最後一個字元
    ifs >> first_char >> id_number;//讀取檔案內容，將檔案的第一個字元存入first_char，其他存入number

    //宣告整數陣列conversion，並初始化為0，陣列大小為字元'Z'的ASCII碼值+1
    //因為需要存入'A' ~ 'Z'的值
    int conversion['Z' + 1] = { 0 };

    conversion['A'] = 10;
    conversion['B'] = 11;
    conversion['C'] = 12;
    conversion['D'] = 13;
    conversion['E'] = 14;
    conversion['F'] = 15;
    conversion['G'] = 16;
    conversion['H'] = 17;
    conversion['I'] = 34;
    conversion['J'] = 18;
    conversion['K'] = 19;
    conversion['L'] = 20;
    conversion['M'] = 21;
    conversion['N'] = 22;
    conversion['O'] = 35;
    conversion['P'] = 23;
    conversion['Q'] = 24;
    conversion['R'] = 25;
    conversion['S'] = 26;
    conversion['T'] = 27;
    conversion['U'] = 28;
    conversion['V'] = 29;
    conversion['W'] = 32;
    conversion['X'] = 30;
    conversion['Y'] = 31;
    conversion['Z'] = 33;

    //計算檢查碼，先將header轉換成數字後，取個位數乘上9
    int ans = conversion[first_char] % 10 * 9;

    //再將header轉換成數字後，取十位數加上去
    ans += conversion[first_char] / 10;

    //宣告變數weight為8，用來計算身分證號碼倒數第二位到第八位的權重
    int weight = 8;

    //使用迴圈計算身分證號碼倒數第二位到第八位的權重總和
    for(int i = 0; i < id_number.length(); i++) {
        //將字元轉換為數字，存入變數digit
        int digit = id_number[i] - '0';
        //將digit乘上weight，加到checksum中
        ans += digit  * weight;
        weight--;
    }

    ans = ans % 10;

    //確認權重是否大於0
    if(ans > 0) {
        ans = 10 - ans;
    }

    cout << first_char << id_number << ans << endl;
}
