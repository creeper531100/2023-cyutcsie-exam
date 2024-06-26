#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream file("123.txt");

    // 格式化單字陣列
    string words[99];

    int idx = 0; // 單字數量
    int max = 0; // 最長單字的長度

    // 讀取每個單字
    while (file >> words[idx]) {
        // 更新最長單字的長度
        if (max <= words[idx].length()) {
            max = words[idx].length();
        }

        cout << words[idx] << " ";
        idx++;
    }

    printf("\n");

    // 輸出星號邊框 (左右邊星號也需要印出，所以+2)
    // 生成一個max + 2 的字串並且填充他
    string padding(max + 2, '*');
    cout << padding << endl;

    for (int i = 0; i < idx; i++) {
        /*
         * *%-*s*\n 是一個格式化字串，用於輸出一個字符串並進行對齊操作。
         * *：表示字段寬度的值通過參數傳遞，而不是直接在格式字符串中指定。
         * -：表示左對齊輸出，即在字段寬度內將字符串向左對齊。
         * %s：表示輸出字符串。
         * \n：表示換行。
         */
        printf("*%-*s*\n", max, words[i].c_str());
    }

    cout << padding << endl;
}

/*
 * 請撰寫一個程式，從資料檔 e.txt 讀入一個英文句子(由 a-z 的大小寫與空白組成，不
 * 含句點)，裡面有好幾個單字，接著以最長單字為最大寬度，將這些單字輸出在一個由星
 * 號字元的長方形中。
 * 範例輸入：
 * CYUT is the top 1000 university
 * 範例輸出：
 * CYUT is the top 1000 university
 * ************
 * *CYUT      *
 * *is        *
 * *the       *
 * *top       *
 * *1000      *
 * *university*
 * ************
*/
