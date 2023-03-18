#include <bitset>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
int main() {
    // ��JIEEE 754�榡��32��G�i��Ʀr
    float input = 123.111;
    int ieee754 = *(int*)&input;

    // ���X�Ÿ���B���Ƴ����M���Ƴ���
    bool sign = (ieee754 >> 31) & 0x1;
    char exp = (ieee754 >> 23) & 0xFF;
    int mantissa = ieee754 & 0x7FFFFF;

    // �p����ƭ�
    char exp_value = exp - 127;

    // ���Ƴ����[�W1�A�o��1.xxxxx���Φ�
    mantissa |= 0x800000;

    string ans = bitset<32>(mantissa).to_string();
    string integer = ans.substr(0, 9 + exp_value);
    string dec = ans.substr(9 + exp_value, 3);

    int int_integer;
    stringstream ss(integer);
    ss >> int_integer;

    cout << int_integer << "+" << dec << endl;
}
