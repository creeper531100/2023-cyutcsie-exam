#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string str = "";
    string ans = "";
    int pos = 0;
    ifstream ifs("123.txt");

    getline(ifs, str);
    cout << str << endl;

    // 遍歷輸入的文字
    for (int i = 0; i < str.length(); i++) {
        // 如果該字元是 'a' 或 'A'
        if (str[i] == 'a' || str[i] == 'A') {
            // 更新位置索引為目前的索引值
            pos = i;
        }
        // 否則如果該字元是 'l' 或 'L' 且 pos 不為 0（代表已經找到 'a' 或 'A'）
        else if (str[i] == 'l' || str[i] == 'L' && pos) {
            // 從位置 pos 到目前索引值的字元都設為空字元 '\0'
            for (int j = pos; j <= i; j++) {
                str[j] = '\0';
            }
            // 重設位置索引為 0
            pos = 0;
            // 重設索引值 i 為 0，以便重新開始搜尋下一組 'a' 或 'A'
            i = 0;
        }
    }

    cout << "Ans=" << str << endl;
}
