#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream ifs("123.txt");
    char ch; //宣告字元變數ch，用來存放身分證號碼的第一個字元
    string id; //宣告字串變數id，用來存放身分證號碼的第二到最後一個字元

    ifs >> ch >> id;//讀取檔案內容，將檔案的第一個字元存入ch，其他存入id
    cout << ch << id << endl;

    //宣告整數陣列map，並初始化為0，陣列大小為字元'Z'的ASCII碼值+1
    //因為需要存入'A' ~ 'Z'的值
    int map['Z' + 1] = { 0 };

    //將陣列映射至id
    map['A'] = 10;
    map['B'] = 11;
    map['C'] = 12;
    map['D'] = 13;
    map['E'] = 14;
    map['F'] = 15;
    map['G'] = 16;
    map['H'] = 17;
    map['I'] = 34;
    map['J'] = 18;
    map['K'] = 19;
    map['L'] = 20;
    map['M'] = 21;
    map['N'] = 22;
    map['O'] = 35;
    map['P'] = 23;
    map['Q'] = 24;
    map['R'] = 25;
    map['S'] = 26;
    map['T'] = 27;
    map['U'] = 28;
    map['V'] = 29;
    map['W'] = 32;
    map['X'] = 30;
    map['Y'] = 31;
    map['Z'] = 33;

    //計算檢查碼，先將header轉換成數字後，取個位數乘上9
    int check = map[ch] % 10 * 9;

    //再將header轉換成數字後，取十位數加上去
    check += map[ch] / 10;

    //使用迴圈計算身分證號碼倒數第二位到第八位的權重總和
    for (int i = 0; i < id.length(); i++) {
        //將字元轉換為數字，存入變數digit
        int digit = id[i] - '0';
        //將digit乘上weight，加到ans中
        check += digit * (8 - i);
    }

    check = check % 10;
    check = 10 - check;

    cout << "Ans=" << ch << id << check << endl;
}

/* 身份證號碼的最後一碼為檢查碼，用於確認號碼是否正確，此檢查碼運算規則如下：
 * 1. 英文代號先以下表轉換成數字
 * A=10 B=11 C=12 D=13 E=14 F=15 G=16 H=17 I=34
 * J=18 K=19 L=20 M=21 N=22 O=35 P=23 Q=24 R=25
 * S=26 T=27 U=28 V=29 W=32 X=30 Y=31 Z=33
 * 2. 英文轉成的數字，個位數乘 9 再加上十位數
 * 3. 各數字從右到左依次乘 1,2,3,4,5,6,7,8
 * 4. 計算上面兩項的總和，計算總和除 10 後之餘數，再用 10 減該餘數，結果就是檢查
 * 碼，若餘數為 0，檢查碼就是 0。
 * 舉例來說：身分證號碼是 W100232736， 身份證號碼的前 9 個字元為 W10023273
 *  W 1 0 0 2 3 2 7 3
 *  3 2
 *  * * * * * * * * * *
 *  1 9 8 7 6 5 4 3 2 1
 *  ────────────────
 *  3+18+8+0+0+10+12+6+14+3=74
 *  74/10=7....4 (餘數)
 *  10-4=6 (檢查碼)
 * 請撰寫一個程式從資料檔 c.txt 讀入一個身份證號碼的前 9 個字元，然後輸出檢查碼。
 * 範例輸入：
 * W10023273
 * 範例輸出：
 * W10023273
 * Ans=W100232736
 */
