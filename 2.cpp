#include <fstream>
#include <iostream>
#include <stack>
#include <string>

//By TFShih 
using namespace std;
int main() {
    string str;
    fstream ifs("123.txt", ios::in);

    // 從ifs讀取一行文字
    std::getline(ifs, str);
    cout << str << endl;

    stack<int> a_pos;
    bool first_is_not_A = false;

    //堆疊的特性是先進先出，所以抽出來的字串會是內部括號

    // 0123456789ABCDEFGHIJKLMNo
    // This is a ball
    //         ^  ^^^
    //         壓 壓抽抽
    //             ^^^這時候抽出堆疊會從頂層取出
    //              也就是B的位置

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'A') {
            // 如果字串開頭沒有 A 字元，那麼在檢查字元 L 是否出現時就不用檢查了。
            // 所以程式中有一個 is_first 的變數來判斷是否為第一個 A 字元。
            first_is_not_A = true;
            a_pos.push(i);
        }
        else if (first_is_not_A && (str[i] == 'l' || str[i] == 'L')) {
            // 遇到"L"或"l"且前面有"A"或"a"出現過就代表有AL字串， 
            // 就將該AL字串標為"\0"標記為無效，以便後續輸出時不會顯示出來。
            for (int j = a_pos.top(); j <= i; j++) {
                str[j] = '\0';
            }
            a_pos.pop();
        }
    }
    cout << "Ans=" << str << endl;
}

/*
 * 對於一個字串若起始字元為 A，最後字元為 L，且其間不含任何 A 或 L 字元則稱 AL 字串。
 * 例： APENCIL 或 AXXBBHCL （四方形表示空白字元）
 * 請設計一程式能從資料檔 b.txt 讀入一個字串（不超過 200 個字元），然後消去所有可
 * 能的 AL 字串，使得消去後之輸出不包含 AL 字串。
 * 範例輸入：
 * Thisisaball
 * 範例輸出：
 * Thisisaball
 * Ans=Thisis
 */