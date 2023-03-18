#include <bitset>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
int main() {
    // ��JIEEE 754�榡��32��G�i��Ʀr
    float input = 12.42;
    cin >> input;
    cout << input << endl;

    int ieee754 = *(int*)&input;

    // ���X�Ÿ���A�i�ٲ�
    bool sign = (ieee754 >> 31) & 0x1;

    // �p����ƭ�
    char exp = (ieee754 >> 23) & 0xFF;
    char exp_value = exp - 127;

    // �p����ơA�b�e���[�W�@�����t���e�m��1�A�o��1.xxxxx���Φ�
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
