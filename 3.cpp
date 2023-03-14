#define _CRT_SECURE_NO_WARNINGS // 忽略警告

#include <fstream> // 輸入輸出檔案用
#include <iostream> // 輸出結果用
#include <math.h>  

using namespace std;
int main() {
    fstream file("c.txt", ios::in); // 開啟檔案，設定為讀取模式
    float ans; // 儲存運算結果
    float num; // 儲存讀入的數字
    char op; // 儲存讀入的運算符號

    file >> ans >> op; // 讀取第一個運算元和運算符號
    cout << ans << op; // 輸出讀入的數字

    while (op != '=') { // 當運算符號不是 '=' 時，進行運算
        file >> num; // 讀取下一個運算元
        cout << num;// 輸出讀入的數字
        switch (op) { // 根據運算符號進行相應的運算
        case '+':
            ans += num;
            break;
        case '-':
            ans -= num;
            break;
        case '*':
            ans *= num;
            break;
        case '/':
            ans /= num;
            break;
        }
        file >> op; // 讀取下一個運算符號
        cout << op; // 輸出讀入的運算符號
    };
    printf("%d\n", (int)round(ans)); // 輸出運算的結果，四捨五入為整數
}