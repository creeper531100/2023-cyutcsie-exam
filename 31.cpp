#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

// 輸出指定數量的星號字符
void print_star(int num) {
    for (int i = 0; i < num; i++) {
        printf("*");
    }
    printf("\n");
}

int main() {
    ifstream file("123.txt", ios::in);

    // 單字暫存變數
    // 99是隨便定的一個數字，只要足夠大就可以了
    char word[99] = { '\0' };
    // 格式化單字陣列
    char words[99][99] = { {'\0'} };

    // 單字數量
    int words_len = 0;
    // 最長單字的長度
    int max_word_len = 0;
	
    string str;
    // 讀取每個單字
    while(file >> word) {
        // 更新最長單字的長度
        if (max_word_len  <= strlen(word)) {
            max_word_len  = strlen(word);
        }
        // 將單字復制到陣列中
        str = str + word + " ";
        sscanf(word, "%s", words[words_len]);
        words_len++;
    }
    cout << str.substr(0, str.length() - 1) << endl;
	
    // 輸出星號邊框 (左右邊星號也需要印出，所以+2)
    print_star(max_word_len  + 2);
    for (int i = 0; i < words_len; i++) {
        /*
         * *%-*s*\n 是一個格式化字串，用於輸出一個字符串並進行對齊操作。
         * *：表示字段寬度的值通過參數傳遞，而不是直接在格式字符串中指定。
         * -：表示左對齊輸出，即在字段寬度內將字符串向左對齊。
         * %s：表示輸出字符串。
         * \n：表示換行。
         */
        printf("*%-*s*\n", max_word_len , words[i]);
    }

    print_star(max_word_len  + 2);
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