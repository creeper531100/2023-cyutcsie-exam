#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

bool asc(int left, int right) {
    return left < right;
}

bool desc(int left, int right) {
    return left > right;
}

int main() {
    ifstream ifs("123.txt");
    int count = 0;
    int num[100] = { 0 };
    int sel = 0;

    // 讀取第一行的排序方式，0為升序，1為降序
    ifs >> sel;
    cout << sel << endl;

    // 讀取檔案中的數字，並將數字存入num陣列
    while (ifs >> num[count]) {
        cout << num[count] << " ";
        count++;
    }

    // 使用STL中的sort函數對數字進行排序
    sort(num, num + count, asc); // 預設升序排序

    // 如果選擇為降序，則使用desc函數進行降序排序
    if (sel == 1) {
        sort(num, num + count, desc);
    }

    // 輸出排序後的結果
    printf("\nAns=");
    for (int i = 0; i < count; i++) {
        cout << num[i] << " ";
    }
}

/*
 * 排序：請針對 b.txt 中的資料進行排序，並依題意由大至小或由小至大將排序結果印
 * 出，排序方式不限，排序後的資料間以一個空白間格分隔。
 * 輸入檔說明：
 * 輸入檔中包含兩行文字，第一行的數字為 0 或 1。0 代表輸出結果由小至大排列，1 則
 * 代表輸出結果由大至小排列。第二行則包含欲排序的數字，每個數字均為整數，數字個
 * 數不超過 100 個，每個數字間以空白間隔。
 * 範例輸入：
 * 0
 * 3 2 5 7 8 1
 * 範例輸出：
 * 0
 * 3 2 5 7 8 1
 * Ans=1 2 3 5 7 8
 */