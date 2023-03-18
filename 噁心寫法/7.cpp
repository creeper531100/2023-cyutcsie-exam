#include <bitset>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
int main() {
    // 輸入IEEE 754格式的32位二進制數字
    float input = 12.42;
    cin >> input;
    cout << input << endl;

    int ieee754 = *(int*)&input;

    // 取出符號位，可省略
    bool sign = (ieee754 >> 31) & 0x1;

    // 計算指數值
    char exp = (ieee754 >> 23) & 0xFF;
    char exp_value = exp - 127;

    // 計算尾數，在前面加上一個隱含的前置位1，得到1.xxxxx的形式
    int mantissa = ieee754 & 0x7FFFFF;
    mantissa |= 0x800000;

    string ans = bitset<32>(mantissa).to_string();
    string integer = ans.substr(0, 9 + exp_value);
    string dec = ans.substr(9 + exp_value, 3);

    int int_integer;
    stringstream ss(integer);
    ss >> int_integer;

    cout << "Ans=" << int_integer << "+" << dec << endl;
}
