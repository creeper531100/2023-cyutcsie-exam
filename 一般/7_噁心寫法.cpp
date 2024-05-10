#include <bitset>
#include <iostream>
#include <fstream>

using namespace std;
int main() {
    // 輸入IEEE 754格式的32位二進制數字
    float input = 21.33;
    ifstream ifs("e.txt");

    ifs >> input;
    cout << input << endl;

    int ieee754 = *(int*)&input;

    // 取出符號位，可省略
    // bool sign = (ieee754 >> 31) & 0x1;

    // 計算指數值
    char exp = (ieee754 >> 23) & 0xFF;
    char exp_value = exp - 127;

    // 計算尾數，在前面加上一個隱含的前置位1，得到1.xxxxx的形式
    int mantissa = ieee754 & 0x7FFFFF;
    mantissa |= 0x800000;

    string ans = bitset<32>(mantissa).to_string();
    string integer = ans.substr(0, 9 + exp_value);
    string dec = ans.substr(9 + exp_value, 3);

    int int_integer = atoi(integer.c_str());

    cout << "Ans=" << int_integer << "+" << dec << endl;
}

/*
 * 請撰寫一程式，此程式從 b.txt 中讀取一個正的十進位數字(含小數)後將此十進位數字轉
 * 換成二進位數字，轉換後的數字請取至小數點第三位(小數點第三位以後的數字直接捨
 * 去)。輸出格式為：轉換後的整數+轉換後的小數部分
 * 範例輸入：
 * 21.33
 * 說明：
 * 21.33 轉換成二進位數字為 10101.010101…
 * 取小數點後三位後的數字為 10101.010
 * 因此輸出結果為 10101+010
 * 範例輸出：
 * 21.33
 * Ans=10101+010
 */
