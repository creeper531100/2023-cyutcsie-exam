#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <stack>
using namespace std;

int calc(string str) {
    int left;
    int right;
    char op;

    // 使用 sscanf 來從字串中讀取數值和運算子
    // sscanf 同 scanf 但不是從控制台輸入格式化，而是直接從字串格式化
    sscanf(str.c_str(), "(%c %d %d)", &op, &left, &right);

    switch (op) {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        return left / right;
    }
}

int main() {
    string str = "(+,(*,3,5),(-,(*,2,4),6))";
    string tmp;

    stack<int> a_pos;
    bool is_first = true;

    //運用資料結構堆疊(stack)之技巧
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ',') {
            // 將逗號替換為空格，方便後續使用 sscanf 解析字串
            // 使用 sscanf 時可以直接忽略空格
            str[i] = ' ';
        }
        if (str[i] == '(') { // 遇到左括弧代表開始位置
            is_first = false; // 設為 false，代表不是第一個括弧
            a_pos.push(i); // 將位置加入堆疊內
        }
        else if (!is_first && (str[i] == ')')) { // 遇到右括弧代表截止位置
            //堆疊的特性是先進先出，所以抽出來的字串會是內部括號

            // 0123456789ABCDEFGHIJKLMNo
            // (+,(*,3,5),(-,(*,2,4),6))
            // ^  ^     ^ ^  ^     ^  ^^
            // 壓 壓    抽 壓 壓    抽  抽抽
            //         ^^這時候抽出堆疊會從頂層取出
            //           也就是第二個括弧的位置(3)

            tmp = str.substr(a_pos.top(), i - a_pos.top() + 1); //substr 子字串，用來切割字串 .substr(起點,長度)
            int ans = calc(tmp);//解析計算結果

            for (int j = a_pos.top(); j <= i; j++) {
                // 同38行註解
                str[j] = ' ';
            }

            // 將開始括弧的位置從堆疊中取出
            str.insert(a_pos.top(), std::to_string(ans));
            a_pos.pop();// 將開始括弧的位置從堆疊中取出
        }
    }

    // 計算最終的運算式結果
    int ans = calc(tmp);
    cout << ans << "\n\n";
}