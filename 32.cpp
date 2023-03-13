#define _CRT_SECURE_NO_WARNINGS
#include <fstream> 
#include <iostream> 

using namespace std;

int main() {
	// 69是隨便定的一個數字，只要足夠大就可以了
    char str[69] = { '\0' };
    FILE* file = fopen("123.txt", "r+");
    fread(str, 1, sizeof(str), file);

    int offset = 0; // 設定初始位移量為 0
    for (int i = 0; i < strlen(str); i++) { // 遍歷整個字串
         // 如果是大小寫英文字元
        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z') {
            offset += toupper(str[i]) - 'A' + 1; // 將其順序數值加總，不分大小寫
        }
    }

    offset = offset % 26; // 取總和的 26 的餘數作為位移量

    // 再次遍歷整個字串
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') { // 如果是小寫英文字元
            // 加上位移量，取 26 的餘數後，再加回 'a' 的 ASCII 值，得到加密後的字元
            printf("%c", ((str[i] - 'a' + offset) % 26) + 'a'); 
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') { // 如果是大寫英文字元
            // 加上位移量，取 26 的餘數後，再加回 'A' 的 ASCII 值，得到加密後的字元
            printf("%c", ((str[i] - 'A' + offset) % 26) + 'A'); 
        }
        else {
            // 其他字元不用加密，直接輸出原本的字元
            printf("%c", str[i]);
        }
    }
}