#include <bitset>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
int main() {
    // 块IEEE 754Α32秈计
    float input = 123.111;
    int ieee754 = *(int*)&input;

    // 才腹计场だ㎝Ю计场だ
    bool sign = (ieee754 >> 31) & 0x1;
    char exp = (ieee754 >> 23) & 0xFF;
    int mantissa = ieee754 & 0x7FFFFF;

    // 璸衡计
    char exp_value = exp - 127;

    // Ю计场だ1眔1.xxxxxΑ
    mantissa |= 0x800000;

    string ans = bitset<32>(mantissa).to_string();
    string integer = ans.substr(0, 9 + exp_value);
    string dec = ans.substr(9 + exp_value, 3);

    int int_integer;
    stringstream ss(integer);
    ss >> int_integer;

    cout << int_integer << "+" << dec << endl;
}
