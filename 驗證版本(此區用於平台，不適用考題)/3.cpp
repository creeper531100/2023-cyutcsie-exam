#define _CRT_SECURE_NO_WARNINGS // 忽略警告

#include <fstream> // 輸入輸出檔案用
#include <iostream> // 輸出結果用
#include <math.h>  

using namespace std;
int main() {
    float ans; // 儲存運算結果
    float num; // 儲存讀入的數字
    char op; // 儲存讀入的運算符號

    cin >> ans >> op; // 讀取第一個運算元和運算符號
    cout << ans << op; // 輸出讀入的數字

    while (op != '=') { // 當運算符號不是 '=' 時，進行運算
        cin >> num; // 讀取下一個運算元
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
        cin >> op; // 讀取下一個運算符號
        cout << op; // 輸出讀入的運算符號
    };
    printf("%d\n", (int)round(ans)); // 輸出運算的結果，四捨五入為整數
}

// 從檔案(c.txt)讀入一算術運算式，計算並列印其結果。
// (1)運算式包含+-*/四則算術運算
// (2)輸入數字可能包含小數點
// (3)不分+-*/一律由左而右依序計算
// (4)運算式的最後結果依四捨五入後取整數值
// 以下幾個範例可供參考測試之：
// 範例輸入一：
// 15*3/8*10/3=
// 範例輸出一：
// 15*3/8*10/3=19
// 範例輸入二：
// 6.53*5+3-8=
// 範例輸出二：
// 6.53*5+3-8=28