#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

int reverse_str(std::string str) {
    char tmp[99] = { '\0' }; // 一個暫存陣列，用來儲存反轉後的字串
    int len = 0;

    // 將原字串從右至左反轉，並存入暫存陣列中
    for(int i = str.length() - 1; i >= 0 ; i--) {
        tmp[len++] = str[i];
    }

    return atoi(tmp); // 將暫存陣列轉換為整數後返回
}

int main() {
    std::string res = "(*,10,5)";
    std::stack<int> st;
    // 從右至左遍歷運算式的每個字符的方式來處理後綴表達式
    // 當遍歷到數字字符時，程式碼從該字符開始向左找到數字的開始位置，
    // 將數字字符轉換為整數，並壓入棧中。當遍歷到運算符時，程式碼從棧中彈出兩個操作數，
    // 根據運算符進行計算，將計算結果壓入棧中。
    // 堆疊的特性是先進先出，所以抽出來的字串會是最新的數字

    // 從右至左遍歷運算式的每個字符
    std::string str;
    for (int i = res.size() - 1; i >= 0; i--) {
        // 如果遇到數字字符，則將其轉換為整數，並壓入棧中
        if (res[i] >= '0' && res[i] <= '9') {

            //這段程式碼是在處理運算式中的數字字符。
            //當程式碼遇到一個數字字符時，它會進入while迴圈，並繼續往前尋找數字字符，如果當前字符不是數字字符，while迴圈就會停止。
            while (res[i] >= '0' && res[i] <= '9') {
                str += res[i];
                i--; //檢視下一個數字
            }
            //回到原始位置
            i++;
            
            int ans = reverse_str(str);
            st.push(ans); // 將整數壓入棧中
            str = "";

            // 如果編譯器支援且你願意背更短的的方式
            // 你可以使用下面方法，reverse_str就不用打了
            // if (res[i] >= '0' && res[i] <= '9') {
            //     std::string str;
            //     while (res[i] >= '0' && res[i] <= '9') {
            //         str += res[i];
            //         i--;
            //     }
            //     i++;
            //     std::reverse(str.begin(), str.end());
            //     int ans = atoi(str.c_str());
            //     st.push(ans);
            //  }
        }
        else if (res[i] == '+' || res[i] == '-' || res[i] == '*' || res[i] == '/') {
            // 如果遇到運算符，則從棧中彈出兩個操作數，進行計算，再將結果壓入棧中
            // 從棧中彈出左操作數
            int left = st.top();
            st.pop();
            // 從棧中彈出左操作數
            int right = st.top();
            st.pop();

            // 根據運算符進行計算，並將結果壓入棧中
            if (res[i] == '+')
                st.push(left + right);
            if (res[i] == '-')
                st.push(left - right);
            if (res[i] == '*')
                st.push(left * right);
            if (res[i] == '/')
                st.push(left / right);
        }
    }
    // 最後棧中剩下的元素即為計算結果，將其輸出
    cout << st.top() << endl;
}
