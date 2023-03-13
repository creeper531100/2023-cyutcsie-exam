#include <iostream>
#include <stack>
using namespace std;

//法一： ByTFShih
int main() {
    string res = "(){[()]}()";
    stack<char> st;  //運用類似資料結構中以堆疊(stack)求後序式之技巧 
    bool currect = true;
    cout << res << endl;
    for (int i = 0; i < res.length(); i++) {
        if (res[i] == '{' || res[i] == '[' || res[i] == '(') { //遇到左括號就推進堆疊(stack)
            st.push(res[i]);
        }
        else if (!st.empty()) {  //遇到右括號就由堆疊(stack)取出一個左括號進行配對驗證 
            if (st.top() == '{' && res[i] == '}' || st.top() == '[' && res[i] == ']' || st.top() == '(' && res[i] == ')') {
                st.pop();
            }
        }
        else {
            currect = false;
            break;
        }
    }

    if (currect && st.empty()) //堆疊(Stack)並須為空，保證左右括號都有對稱
        cout << "Ans=CORRECT" << endl;
    else
        cout << "Ans=ERROR" << endl;
}