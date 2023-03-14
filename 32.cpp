#define _CRT_SECURE_NO_WARNINGS
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
    FILE* file = fopen("123.txt", "r+");

    // 格式化單字陣列
    char words[99][99] = { {'\0'} };

    int words_len = 0; // 單字數量
    int max_word_len = 0; // 最長單字的長度

    // 讀取每個單字
    while (!feof(file)) {
        fscanf(file, "%s", words[words_len]);
        printf("%s ", words[words_len]);

        // 更新最長單字的長度
        if (max_word_len <= strlen(words[words_len])) {
            max_word_len = strlen(words[words_len]);
        }

        words_len++;
    }

    printf("\n");

    // 輸出星號邊框 (左右邊星號也需要印出，所以+2)
    print_star(max_word_len + 2);
    for (int i = 0; i < words_len; i++) {
        /*
         * *%-*s*\n 是一個格式化字串，用於輸出一個字符串並進行對齊操作。
         * *：表示字段寬度的值通過參數傳遞，而不是直接在格式字符串中指定。
         * -：表示左對齊輸出，即在字段寬度內將字符串向左對齊。
         * %s：表示輸出字符串。
         * \n：表示換行。
         */
        printf("*%-*s*\n", max_word_len, words[i]);
    }

    print_star(max_word_len + 2);
}