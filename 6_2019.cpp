#include <fstream>
#include <iostream>

using namespace std;

int GCD(int num1, int num2) {
    if (num2 == 0) {
        return num1;
    }
    return GCD(num2, num1 % num2);
}

int LCM(int num1, int num2) {
    return num1 * num2 / GCD(num1, num2);
}

int main() {
    ifstream iss("b.txt", ios::in);
    int ans = 1;
    int data;

    while (iss >> data) {
        ans = LCM(ans, data);
    }

    printf("Ans=%d", ans);
}