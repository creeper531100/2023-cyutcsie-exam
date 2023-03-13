#include <iostream>
#include <stack>
//法一： ByTFShih 
using namespace std;
int main() {
    string str = "This is a ball";
    stack<int> a_pos;
    bool is_first = true;

    //堆疊的特性是先進先出，所以抽出來的字串會是內部括號

    // 0123456789ABCDEFGHIJKLMNo
    // (+,(*,3,5),(-,(*,2,4),6))
    // ^  ^     ^ ^  ^     ^  ^^
    // 壓 壓    抽 壓 壓    抽  抽抽
    //         ^^這時候抽出堆疊會從頂層取出
    //           也就是第二個括弧的位置(3)

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'A') {
            is_first = false;
            a_pos.push(i);
        }
        else if (!is_first && (str[i] == 'l' || str[i] == 'L')) {
            //遇到"L"或"l"且前面有"A"或"a"出現過就代表有AL字串， 
            //就將該AL字串標為"\0"即標記為無效
            for (int j = a_pos.top(); j <= i; j++) {
                str[j] = '\0';
            }
            a_pos.pop();
        }
    }
    cout << "Ans=" << str << endl;
}