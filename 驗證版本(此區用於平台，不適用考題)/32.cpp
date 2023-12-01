#define _CRT_SECURE_NO_WARNINGS
#include <fstream> 
#include <iostream> 

using namespace std;

int main() {
    // 69是隨便定的一個數字，只要足夠大就可以了
    char str[69] = { '\0' };
    FILE* file = fopen("123.txt", "r+");
    fread(str, 1, sizeof(str), file);

    printf("%s\n", str);
    printf("Ans=");

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

/*
 * 字串加密：試寫一個程式可以讀入一個字串(長度最大為 100)，接著將字串中的英文字
 * 元(’a’-‘z’或’A’-‘Z’)，依照其順序數值進行加總(‘a’與’A’的順序為 1，’b’與’B’
 * 的順序為 2，依此類推)，加總結果取 26 的餘數視為密鑰，也是每個英文字元的位移量，
 * 假設位移量是 2，則’a’-‘z’的加密結果如下：
 * 原始: abcdefghijklmnopqrstuvwxyz
 * 加密: cdefghijklmnopqrstuvwxyzab
 * 請從資料檔 e.txt 中讀入一行字串，將字串中的大小寫英文字元都進行加密，其餘字元
 * 則是原封不動，輸出加密後的字串。
 * 範例輸入：
 * It is never too late to learn, just do it.
 * 範例輸出：(所有英文字元依據其順序的加總值為 412，取 26 的餘數為 22)
 * It is never too late to learn, just do it.
 * Ans=Ep eo jaran pkk hwpa pk hawnj, fqop zk ep.
 */