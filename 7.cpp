#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;
int main() {
    FILE* file = fopen("b.txt", "r+");

    string ans;
    float dec;
    int integer;
	//99是隨便定的一個數字，只要足夠大就可以了
    char buf[99];

    fscanf(file, "%s", &buf);
    sscanf(buf, "%d%f", &integer, &dec);

    while (integer != 0) {
        ans += integer % 2 + '0'; //取餘數，char轉型用 + '0'
        integer /= 2; //十進制轉二進制, 不斷除二
    }

    ans += '+';
    for (int i = 0; i < 3; i++) {
        dec *= 2.0; //十進制轉二進制小數, 不斷乘二
        ans += (int)dec + '0'; //取整數
        if ((int)dec == 1) //若進位扣1
            dec--;
    }

    cout << buf << endl;
    cout << "Ans=" << ans << endl;
}