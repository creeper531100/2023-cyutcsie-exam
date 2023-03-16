#include <fstream>
#include <iostream>
#include <stack>
using namespace std;

//By TFShih
int main() {
    fstream ifs("123.txt", ios::in);
    string res = "(){[()]}()";
    ifs >> res;

    stack<char> st;  //運用類似資料結構中以堆疊(stack)求後序式之技巧

    // 定義一個變量表示當前字串是否合法，初始值為 true
    bool currect = true;
    cout << res << endl;

    // 遍歷字符串中的每個字符
    for (int i = 0; i < res.length(); i++) {
        //如果遇到左括號，就推進堆疊(stack)
        if (res[i] == '{' || res[i] == '[' || res[i] == '(') {
            st.push(res[i]);
        }
        else if (!st.empty()) {
            // 如果遇到右括號，則檢查 stack 中是否有左括號與之配對
            if (st.top() == '{' && res[i] == '}' || st.top() == '[' && res[i] == ']' || st.top() == '(' && res[i] == ')') {
                st.pop();
            }
        }
        else {
            // 如果遇到了右括號但是 stack 中沒有左括號與之配對，則字符串不合法
            currect = false;
            break;
        }
    }
    // 如果字符串中所有的左括號都能夠與右括號配對成功，且 stack 已經為空，則該字符串合法
    if (currect && st.empty())
        cout << "Ans=CORRECT" << endl;
    else
        cout << "Ans=ERROR" << endl;
}

/*
 * 分別自檔案 e.txt 讀入一串由()[]{}所組成之字串，判斷字串是否合法，一個()[]{}必須
 * 對稱存在，且對應的括號間不能插入單獨的括號。
 * 範例輸入一：
 * {[()]()})
 * 範例輸出一：
 * ({[()]()})
 * Ans=CORRECT
 * 範例輸入二：
 * (){[()]()
 * 範例輸出二：
 * (){[()]()
 * Ans=ERROR
 */